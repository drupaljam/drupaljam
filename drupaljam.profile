<?php

function _drupaljam_settings() {
  return array(
    'name' => 'DrupalJam',
    'timezone' => 'Europe/Amsterdam',
    'country' => 'NL',
    'theme' => 'stark'
  );
}

function drupaljam_form_install_configure_form_alter(&$form, $form_state) {
  $settings = _drupaljam_settings();
  $form['site_information']['site_name']['#default_value'] = $settings['name'];
  $form['site_information']['site_name']['#access'] = FALSE;
  
  $form['site_information']['site_name_display'] = array(
    '#type' => 'item',
    '#markup' => check_plain($form['site_information']['site_name']['#default_value']),
    '#title' => $form['site_information']['site_name']['#title'],
    '#weight' => $form['site_information']['site_name']['#weight'] - 5
  );
  
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  
  $form['server_settings']['#access'] = FALSE;
  $form['server_settings']['site_default_country']['#default_value'] = $settings['country'];
  $form['server_settings']['date_default_timezone']['#default_value'] = $settings['timezone'];
}

/**
 * Implements hook_install_tasks_alter().
 * We add an extra install task for non interactive installs that make sure that
 * the changes we make to the form, using hook_form_FORM_ID_alter, are also 
 * reflected without a form. This extra tasks is added BEFORE the 
 * install_configure form.
 */
function drupaljam_install_tasks_alter(&$tasks, $install_state) {
  if (!$install_state['interactive']) {
    $tasks_keys = array_keys($tasks);
    $tasks_values = array_values($tasks);
    $key = array_search('install_configure_form', $tasks_keys);
    array_splice($tasks_keys, $key, 0, array('drupaljam_fix_settings'));
    array_splice($tasks_values, $key, 0, array(array('run' => INSTALL_TASK_RUN_IF_REACHED)));
    $tasks = array_combine($tasks_keys, $tasks_values);
  }
}
function drupaljam_fix_settings(&$install_state) {
  $settings = _drupaljam_settings();
  $install_state['forms']['install_configure_form']['site_name'] = $settings['name'];
  $install_state['forms']['install_configure_form']['date_default_timezone'] = $settings['timezone'];
  $install_state['forms']['install_configure_form']['site_default_country'] = $settings['country'];
}