<?php
/**
 * @file
 * feature_stages.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_stages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "livecycle" && $api == "default_livecycle_stages") {
    return array("version" => "3.0");
  }
}
