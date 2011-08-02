<?php

function _livecycle_get_properties($op = NULL) {
  static $properties;
  
  if (!isset($properties)) {
    $properties = array();
    
    $types = module_invoke_all('livecycle_property_type_info');
    foreach ($types as $type) {
      $properties[$type] = module_invoke_all('livecycle_property_info', $type);
    }
  }
  
  return $op ? $properties[$op] : $properties;
}

/**
 * Build a properties array
 *
 * @param $op The type of properties array to build
 * @param $base The information that is present by default
 * @param $info The information that comes from the module
 * @param $existing (optional) Optionally existing information
 */
function _livecycle_build_properties($op, $base, $info, $existing = FALSE) {
  $result = $base;
  $properties = _livecycle_get_properties($op);
  
  foreach ($properties as $key => $property_info) {
    $build_callback = isset($property_info['build callback']) ? $property_info['build callback'] : '_livecycle_build_property';
    $build_callback($result, $key, $property_info, $info, $existing);
  }
  
  return $result;
}

function _livecycle_build_default(&$result, $key, $info) {
  if (isset($info['default'])) {
    $result[$key] = $info['default'];
  }
  elseif (isset($info['default callback'])) {
    $args = isset($info['default arguments']) ? $info['default arguments'] : array();
    $result[$key] = call_user_func_array($info['default callback'], $args);
  }
}

function _livecycle_build_property(&$result, $key, $property_info, $info, $existing) {
  if (!$existing) {
    $existing = array();
  }
  
  if (!isset($info[$key]) && !isset($exiting[$key])) {
    _livecycle_build_default($result, $key, $property_info);
  } 
  elseif (isset($info[$key])) {
    $result[$key] = $info[$key];
  }
  else {
    $result[$key] = $existing[$key];
  }
}

function _livecycle_build_property_array(&$result, $key, $property_info, $info, $existing) {
  if (!$existing) {
    $existing = array();
  }
  
  if (!isset($info[$key]) && !isset($exiting[$key])) {
    _livecycle_build_default($result, $key, $property_info);
  } else {
    $result[$key] = array();
    if (isset($existing[$key])) {
      foreach ($existing[$key] as $item) {
        if (!in_array($item, $result[$key])) {
          $result[$key][] = $item;
        }
      }
    }
    if (isset($info[$key])) {
      foreach ($info[$key] as $item) {
        if (!in_array($item, $result[$key])) {
          $result[$key][] = $item;
        }
      }
    }
  }
}

function _livecycle_build_properties_sub(&$result, $key, $property_info, $info, $existing) {
  $subtype = $property_info['subtype'];
  
  $result[$key] = _livecycle_build_properties($subtype, array(), 
    isset($info[$key]) ? $info[$key] : array(),
    isset($existing[$key]) ? $existing[$key] : array()
  );
}
