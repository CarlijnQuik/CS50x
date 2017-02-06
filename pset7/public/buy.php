<?php

     /**
     *Read readme.txt
     */
     
    // configuration
    require("../includes/config.php"); 
    
     // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("buy_form.php", ["title" => "Buy"]);
    } 
    // if form is submitted
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        if ($stock && preg_match("/^\d+$/", $_POST["shares"]))
        {
            // calculate price
            $outcome = $stock["price"] * $_POST["shares"];
            
            //define cash
            $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
            
            // check whether user has enough money
            if ($cash >= $outcome)
            {
                // update database
                $insert = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)",
                $_SESSION["id"], $stock["symbol"], $_POST["shares"]);
                
                 // update cash
                CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $outcome, $_SESSION["id"]);
                
                // update history
                $track = CS50::query("INSERT INTO history (user_user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)",
                $_SESSION["id"], 'BUY', $stock["symbol"], $_POST["shares"], $stock["price"]);
                
                //redirect
                redirect("/");
            }
            else
            {
                apologize("You do not have enough cash.");
            }
        }
        else
        {
            apologize("Input incorrect or not found.");
        }
    }
?>
    