<?php
/*
 * drush command file
 */

function review_links_drush_command(){
    $items['review_links-content']=array(
        'description'=> 'For creating movies in the database',
        'aliases'=> array('movies'),
    );


    return($items);

}

function drush_review_links_content(){
    //print("Hello World!");
    $url= "https://query.yahooapis.com/v1/public/yql?q=select%20*%20from%20html%20where%20url%3D%27http%3A%2F%2Fwww.imdb.com%2Fchart%2Ftop%27%20and%20xpath%3D%27%2F%2F*%5B%40id%3D%22main%22%5D%2Fdiv%2Fspan%2Fdiv%2Fdiv%2Fdiv%5B3%5D%2Ftable%2Ftbody%2Ftr%2Ftd%2Fa%27&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";
    //$url = variable_get('api_url');
    $response = drupal_http_request($url);
    $out = drupal_json_decode($response->data);

    foreach ($out['query']['results']['a']as $result){
        if (array_key_exists('title', $result)) {
            print(" Item: ");
            //var_dump($result);
            $node = new stdClass();
            $node->title = $result['content'];
            $node->type =  "movie_review";
            $node->field_movie_review_movie_author = $result['title'];
            //$node->field_movie_review_imdb_link = $result['href'];
            print $node->title;
            node_object_prepare($node);
            $node = node_submit($node); // Prepare node for saving
            node_save($node);
            print $node->nid;
        }
    }
}

