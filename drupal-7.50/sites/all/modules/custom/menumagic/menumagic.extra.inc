<?php
function menumagic_extra($wildcard){
    $content= array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Magical menus and stuff like "%wildcard".', array('%wildcard' => $wildcard)) . '</p>',

    );
    return $content;
}