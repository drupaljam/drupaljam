<?php
/**
 * @file
 * feature_stages.default_livecycle_stages.inc
 */

/**
 * Implementation of hook_default_livecycle_stages().
 */
function feature_stages_default_livecycle_stages() {
  $export = array();

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'After conference';
  $stage->machine_name = 'after';
  $stage->weight = 6;
  $export['after'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Announce';
  $stage->machine_name = 'announce';
  $stage->weight = 0;
  $export['announce'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Cancelled';
  $stage->machine_name = 'cancelled';
  $stage->weight = 7;
  $export['cancelled'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Call for Sessions';
  $stage->machine_name = 'cfs';
  $stage->weight = 1;
  $export['cfs'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Sessions closed';
  $stage->machine_name = 'closed';
  $stage->weight = 3;
  $export['closed'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Conference';
  $stage->machine_name = 'conf';
  $stage->weight = 5;
  $export['conf'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Program available';
  $stage->machine_name = 'program';
  $stage->weight = 4;
  $export['program'] = $stage;

  $stage = new stdClass;
  $stage->disabled = FALSE; /* Edit this to true to make a default stage disabled initially */
  $stage->api_version = 3.0;
  $stage->name = 'Voting';
  $stage->machine_name = 'vote';
  $stage->weight = 2;
  $export['vote'] = $stage;

  return $export;
}
