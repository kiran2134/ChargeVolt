<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Employee Count</title>
</head>

<body>
    <form method="post">
        <input type="text" name="deptname">
        <input type="submit" name="submit">
    </form>
    <?php
    if (isset($_POST['submit'])) {
        $deptname = $_POST['deptname'];

        $host = "host=localhost";
        $port = "port=5432";
        $dbname = "dbname=rv";
        $credentials = "user=postgres password=1234";
        $db = pg_connect("$host $port $dbname $credentials");

        if (!$db) {
            echo "Error : Unable to open database\n";
        } else {
            $query = "SELECT COUNT(*) FROM emp, dept WHERE emp.dno=dept.dno AND dept.dname='$deptname'";
            $result = pg_query($db, $query);
            if (!$result) {
                echo "Error : Unable to retrieve data\n";
            } else {
                $row = pg_fetch_row($result);
                echo "Total employees in $deptname department: " . $row[0];
            }
        }
    }
    ?>
</body>

</html>