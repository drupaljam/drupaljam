<?php

function livecycle_livecycle_property_type_info() {
  return array('stage', 'state');
}
function livecycle_livecycle_property_info($op) {
  switch ($op) {
    case 'state':
      return array(
        'pre callbacks' => array(
          'default' => array(),
          'build callback' => '_livecycle_build_property_array',
          'finalize callback' => '_livecycle_finalize_callbacks',
        ),
        'post callbacks' => array(
          'default' => array(),
          'build callback' => '_livecycle_build_property_array',
          'finalize callback' => '_livecycle_finalize_callbacks',
          'finalize arguments' => array('%stage', '%state', 'pre'),
        ),
        'access callback' => array(
          'default' => 'livecycle_stage_access',
        ),
        'access arguments' => array(
          'default' => array('%stage', '%state')
        )
      );
    case 'stage':
      $state_info = array(
        'build callback' => '_livecycle_build_properties_sub',
        'subtype' => 'state',
        'finalize callback' => '_livecycle_finalize_state',
      );
      return array(
        'includes' => array(
          'default' => array(),
        ),
        'label' => array(
          'default' => ''
        ),
        'enable' => $state_info,
        'disable' => $state_info
      );
  }
}


function livecycle_livecycle_stages_alter(&$stages) {
  $modules = array_keys(module_list());
  $moments = array('pre', 'post');
  $states = array('enable','disable');
  
  foreach ($stages as $stage => $info) {
    // make sure the includes are included
    foreach ($info['includes'] as $include) {
      include_once $include;
    }
    
    foreach ($modules as $module) {
      foreach ($states as $state) {
        foreach ($moments as $moment) {
          $options = array(
            $module . '_livecycle_stage_' . $moment . '_' . $state,
            $module . '_livecycle_stage_' . $stage . '_' . $moment . '_' . $state,
          );
          foreach ($options as $callback) {
            if (!in_array($callback, $stages[$stage][$state][$moment . ' callbacks']) && function_exists($callback)) {
               $stages[$stage][$state][$moment . ' callbacks'][] = $callback;
            }
          }
        }
      }
    }
  }
}