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
        render("sell_form.php", ["title" => "Sell"]);
    } 
    // if form is submitted
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup stock
        if ($stock = lookup($_POST["symbol"]))
        {
         // check whether user has shares
         $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
         
         // calculate income
         $income = $stock["price"] * $shares[0]["shares"];
         
         // add income to cash in database
         CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $income, $_SESSION["id"]);
         
         // remove their shares in database
         CS50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
         
         $display = 'SELL';
         
         // update history
         $track = CS50::query("INSERT INTO history (user_user_id, transaction, symbol, shares, price) VALUES(?, ?, ?, ?, ?)",
         $_SESSION["id"], $display, $stock["symbol"], $shares[0]["shares"], $stock["price"]);
         
         //redirect
         redirect("/");
         }
         else
         {
             apologize("Input incorrect or not found.");
         }
   }
?>
    