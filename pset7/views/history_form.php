<table class = "table table-striped table-hover">
    <thead class="thead-center">
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    
    <tbody class="thead-center">
        <?php
            foreach ($positionsh as $positionh)
            {
                print("<tr>");
                print("<td>{$positionh["transaction"]}</td>");
                print("<td>{$positionh["datetime"]}</td>");
                print("<th>{$positionh["symbol"]}</th>");
                print("<td>{$positionh["shares"]}</td>");
                print("<td>{$positionh["price"]}</td>");
                print("</tr>");
            }
        ?>
    </tbody>
</table>
