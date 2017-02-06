<?php

     /**
     *Read readme.txt
     */

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_form.php", ["title" => "Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // query database for user
        $rows = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        
        // check password
        if (password_verify($_POST["oldpassword"], $rows[0]["hash"]))
        {
            // check whether passwords are the same
            if ($_POST["newpassword"] == $_POST["confirmpassword"])
            {
                // try to insert new password in database
                $result = CS50::query("UPDATE users SET hash = ? WHERE id = ?", password_hash($_POST["newpassword"], PASSWORD_DEFAULT), $_SESSION["id"]);
                $_SESSION['alert'] = "Done!";
                redirect("/");
            }
            else
            {
                apologize("New passwords not the same.");
            }
        }
        else
        {
            apologize("Wrong old password.");
        }
    }    
?>
