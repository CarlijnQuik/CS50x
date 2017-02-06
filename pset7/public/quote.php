<?php
    // configuration
    require("../includes/config.php"); 
    
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("quote_form.php", ["title" => "Quote"]);
    } 
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // check whether stock exists
        if ($stock = lookup($_POST["symbol"]))
        {
            render("quote_info.php",["title" => "Info", "find" => $stock]);
        }
        else
        {
            apologize("Input incorrect or not found.");
        }
    }
?>
    
    
    
    

    
    