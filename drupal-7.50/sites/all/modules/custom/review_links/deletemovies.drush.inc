<?php
/*
 * drush command file
 */
function deletemovies_drush_command(){
    $items['deletemovies-content']=array(
        'description'=> 'For deleting all movies in the database',
        'aliases'=> array('deletemovies'),
    );
    return($items);

}

function drush_deletemovies_content()
{
    print("Delete!");

$query = new EntityFieldQuery;

$result = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'movie_review')
    ->execute();

if (isset($result['node']) && count($result['node'])) {

    $node_ids = array_keys($result['node']);

    node_delete_multiple($node_ids);
}

//delete taxonomy terms
    print("Delete!");

    $vocabulary = taxonomy_vocabulary_machine_name_load('genre');
    foreach (taxonomy_get_tree($vocabulary->vid) as $term) {
        taxonomy_term_delete($term->tid);
    }
}
