<?php

     /**
     *Read readme.txt
     */
    
    // configuration
    require("../includes/config.php"); 
    
    // get info
    $rowsh = CS50::query("SELECT * FROM history WHERE user_user_id = ?", $_SESSION["id"]);
    
     // make array
    $positionsh = [];

    // look up values
    foreach ($rowsh as $rowh)
    {
        $history = lookup($rowh["symbol"]);
        if ($history)
        {
            $positionsh[] = [
                "name" => $history["name"],
                "transaction" => $rowh["transaction"],
                "datetime" => $rowh["datetime"],
                "symbol" => $history["symbol"],
                "shares" => $rowh["shares"],
                "price" => $history["price"]
            ];
        }
    }
    
    // render form
    render("history_form.php", ["title" => "History", "positionsh" => $positionsh]);
    
?>