<html>

<body>
    <form method="post">
        Enter Item code
        <input type="text" name="code"><br>
        Enter Item name
        <input type="text" name="name"><br>
        Enter No of units
        <input type="text" name="units"><br>
        Enter Rate
        <input type="text" name="rate"><br>
        <input type="submit" name="submit">
    </form>
    <?php
    $item_code = $_POST['code'];
    $name = $_POST['name'];
    $unit = $_POST['units'];
    $rate = $_POST['rate'];

    $arrcode = explode(",", $item_code);
    $arrname = explode(",", $name);
    $arrunit = explode(",", $unit);
    $arrrate = explode(",", $rate);

    echo "<table>
<tr>
    <th>Item code</th>
    <th>Item name</th>
    <th>No of units</th>
    <th>Rate</th>
  </tr>";
    $sum = 0;
    for ($i = 0; $i < count($arrname); $i++) {
        echo "<tr>
      <td>$arrcode[$i]</td>
      <td>$arrname[$i]</td>
      <td>$arrunit[$i]</td>
      <td>$arrrate[$i]</td>
      </tr>";
        $sum = $sum + $arrrate[$i] * $arrunit[$i];
    }
    echo "<tr>
      <td></td>
      <td></td>
      <th>Total is:</th>
      <th>$sum</th>
      </tr>";
    echo "</table>";
    ?>
</body>

</html>