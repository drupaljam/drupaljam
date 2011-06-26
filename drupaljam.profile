<?php

function drupaljam_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'DrupalJam';
  $form['site_information']['site_name']['#access'] = FALSE;
  
  $form['site_information']['site_name_display'] = array(
    '#type' => 'item',
    '#markup' => check_plain($form['site_information']['site_name']['#default_value']),
    '#title' => $form['site_information']['site_name']['#title'],
    '#weight' => $form['site_information']['site_name']['#weight'] - 5
  );
  
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  
  $form['server_settings']['#access'] = FALSE;
  $form['server_settings']['site_default_country']['#default_value'] = 'NL';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Amsterdam';
}