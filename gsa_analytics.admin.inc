<?php 
/**
 * @file
 * Administrative page callbacks.
 */

/**
 * Page callback.
 */
function gsa_analytics_admin_settings_form($form, $form_state) {
  //$gsa_analytics_url = variable_get('gsa_analytics_url', 'https://github.com/GSA/DAP-Gov-wide-GA-Code');

  $form = array(
    'gsa_analytics_agency_name' => array(
      '#required' => TRUE,
      '#size' => 32,
      '#default_value' => variable_get('gsa_analytics_agency_name', ''),
      '#description' => t('A short, uppercase abbreviation uniquely identifying the Agency. e.g. DHS, EPA, GSA, etc'),
      '#type' => 'textfield',
      '#title' => t('Agency Name'),
    ),

    'gsa_analytics_sub­agency_name' => array(
      '#required' => FALSE,
      '#size' => 32,
      '#default_value' => variable_get('gsa_analytics_sub­agency_name', ''),
      '#description' => t('A short, uppercase abbreviation uniquely identifying the Agency. e.g. DHS, EPA, GSA, etc'),
      '#type' => 'textfield',
      '#title' => t('Sub-Agency Name'),
    ),
    
    'gsa_analytics_cookie_timeout' => array(
      '#required' => FALSE,
      '#size' => 4,
      '#default_value' => variable_get('gsa_analytics_cookie_timeout', '24'),
      '#description' => t('An integer value specifying period in months.'),
      '#type' => 'textfield',
      '#title' => t('Visitor Cookie Timeout'),
    ),
    
    'gsa_analytics_additional_ua' => array(
      '#required' => FALSE,
      '#size' => 32,
      '#default_value' => variable_get('gsa_analytics_additional_ua', ''),
      '#description' => t('ID(s) for optional tracking to a second, alternative GA account (UA­XXXX­YY) belonging to and managed by the Agency. Multiple UA ids can be specified in a comma­-separated list.'),
      '#type' => 'textfield',
      '#title' => t('Parallel UA'),
    ),
    
    'gsa_analytics_search_params' => array(
      '#required' => FALSE,
      '#size' => 32,
      '#default_value' => variable_get('gsa_analytics_search_params', 'q'),
      '#description' => t('A single value or a list of comma­-separated search parameter names.'),
      '#type' => 'textfield',
      '#title' => t('Search Parameter(s)'),
    ),
    
    'gsa_analytics_file_extensions' => array(
      '#required' => FALSE,
      '#size' => 64,
      '#default_value' => variable_get('gsa_analytics_file_extensions', ''),
      '#description' => t('A comma separated list of 1 or more extensions. Current List is xls, xlsx, doc, docx, ppt, pptx, pdf, txt, zip, rar, 7z, gz, tgz, exe, wma, mov, avi, wmv, mp3, mp4, csv, tsv, mobi, epub, swf'),
      '#type' => 'textfield',
      '#title' => t('Additional Download Extensions'),
    ),
    
    'gsa_analytics_youtube_tracking' => array(
      '#type' => 'checkbox',
      '#title' => t('Include Youtube tracking?'),
      '#default_value' => variable_get('gsa_analytics_youtube_tracking', 0),
      '#description' => t("Check this box if you want the script to track YouTube."),
    ),

    'submit' => array( 
      '#type' => 'submit',
      '#value' => t('Save'),
    )
  );

  return $form;
}

/**
 * Submit callback for config form.
 */
function gsa_analytics_admin_settings_form_submit($form, $form_state) {
  variable_set('gsa_analytics_agency_name', $form_state['values']['gsa_analytics_agency_name']);
  variable_set('gsa_analytics_sub­agency_name', $form_state['values']['gsa_analytics_sub­agency_name']);
  variable_set('gsa_analytics_cookie_timeout',  $form_state['values']['gsa_analytics_cookie_timeout']);
  variable_set('gsa_analytics_additional_ua', $form_state['values']['gsa_analytics_additional_ua']);
  variable_set('gsa_analytics_search_params',  $form_state['values']['gsa_analytics_search_params']);
  variable_set('gsa_analytics_file_extensions', $form_state['values']['gsa_analytics_file_extensions']);
  variable_set('gsa_analytics_youtube_tracking',  $form_state['values']['gsa_analytics_youtube_tracking']);

  drupal_set_message(t('Your configuration has been saved.'));
}