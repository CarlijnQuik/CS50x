<?php
    
    /**
    * Read "Readme.txt" for information about this file
    */    

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // filter input
    $input = $_GET["geo"];
    $input = urldecode($input);
    $input = str_replace(",", " ", $input);
    
    // search database for places matching $_GET["geo"], store in $places
    if (empty($input))
    {
        echo "No input.";
    }
    else
    {
        $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name, admin_name1, admin_code1) AGAINST (?)", $input);
        if (count($places) == 0)
        {
            $input .= "%";
            $places = CS50::query("SELECT * FROM places WHERE ((postal_code LIKE ?) OR (place_name LIKE ?) OR (admin_name1 LIKE ?) OR (admin_code1 LIKE ?))", $input, $input, $input, $input);
        }
    }
    
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>