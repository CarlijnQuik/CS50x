#!/usr/bin/env php
<?php

    /**
    * Read "Readme.txt" for information about this file
    */    
    
    // configuration
    require("../includes/config.php");

    // check whether right commands are given
    if ($argc == 2)
    {
         // read and open file
        $usfile = $argv[1];
        if (file_exists($usfile) && is_readable($usfile) && $vfile = fopen($usfile, "r"))
        {
            // insert values into database
            while(($line = fgetcsv($vfile, 0, "\t")) !== FALSE)
            {
                $insert = CS50::query("INSERT INTO places 
                (country_code, postal_code, place_name, admin_name1, admin_code1, admin_name2, admin_code2, admin_name3, admin_code3, latitude, longitude, accuracy)
                VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                $line[0], $line[1], $line[2], $line[3], $line[4], $line[5], $line[6], $line[7], $line[8], $line[9], $line[10], $line[11]);
            }
            fclose($vfile);
        }
        else
        {
            echo "File does not exist, is not readable or does not open.";
        }
    }
    else
    {
        echo "Required input = ./import /path/to/US.txt";
    }
    
?>