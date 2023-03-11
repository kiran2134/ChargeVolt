<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>

<body>
  <form method="post">
    <input type="text" name="name">
    <input type="submit" name="submit">
  </form>
  <?php
  $host = "host=localhost";
  $port = "port=5432";
  $dbname = "dbname=rv";
  $credentials = "user=postgres password=1234";
  $db = pg_connect("$host $port $dbname $credentials");
  if (!$db) {
    echo "error";
  } else {
    echo "successfully connected to the database";
  }
  $name = $_POST['name'];
  $query = "select property.pno,property.description,property.area from owner,property where owner.oname=property.oname and owner.oname='$name'";
  $res = pg_query($db, $query);
  if (!$res) {
    echo "error";
  } else {
    while ($row = pg_fetch_row($res)) {
      echo "<br>";
      echo "pno:" . $row[0];
      echo "<br>";
      echo "pname:" . $row[1];
      echo "<br>";
      echo "area:" . $row[2];
      echo "<br>";
    }
    pg_close($db);
  }
  ?>
</body>

</html>