<?php
function review_links_admin_form(){
    $form['api_url'] = array(
        '#type' => 'textfield', //you can find a list of available types in the form api
        '#title' => t('API url'),
        '#default_value' => variable_get('api_url'),
        '#size' => 50,
        '#maxlength' => 500,
        '#required' => TRUE, //make this field required
    );

    //$form['submit'] = array('#type' => 'submit', '#value' => t('Search'));
    return system_settings_form($form);

}



