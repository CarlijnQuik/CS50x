<?php
    
     /**
     *Read readme.txt
     */
    
    // configuration
    require("../includes/config.php"); 

    // query database for user
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);

    // make array
    $positions = [];

    // look up values
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions]);
    
?>
