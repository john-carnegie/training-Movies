<?php
function menumagic_user_tab($wildcard){
    if(is_numeric($wildcard)&& ($account = user_load($wildcard))){
        return array(
            '#type' => 'markup',
            '#markup' => t("%username is awsome . ", array ('%username'=>$account->name)),

        );

    }
    else{
        return drupal_not_found();
    }

}