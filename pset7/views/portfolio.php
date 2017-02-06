<?php
    if (isset($_SESSION['alert']))
    {
        echo '<div class="alert alert-success" role="alert">' . $_SESSION['alert'] . '</div>';
        $_SESSION['alert'] = NULL;
    }
?>

<div class="row">
    <table class = "table table-striped table-hover">
        <thead class="thead-center">
            <tr>
                <th>Symbol</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
            </tr>
        </thead>
        
        <tbody class="thead-center">
            <?php
                foreach ($positions as $position)
                {
                    print("<tr>");
                    print("<th>{$position["symbol"]}</th>");
                    print("<td>{$position["name"]}</td>");
                    print("<td>{$position["shares"]}</td>");
                    print("<td>{$position["price"]}</td>");
                    print("</tr>");
                }
            ?>
        </tbody>
    </table>
</div>
