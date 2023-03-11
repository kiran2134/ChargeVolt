<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form method="get">
        <label for="num">Enter Email</label>
        <input type="text" name="search" id="search">
        <input type="submit" name="submit" id="search">
    </form>
    <?php
    $search = $_GET['search'];
    if (preg_match_all('/^([a-z0-9\+_\-]+)(\.[a-z0-9\+_\-]+)*@([a-z0-9\-]+\.)(com|in)$/ix', $search, $match)) {
        echo '<pre>';
        echo "Email Entered Successfully<br>";
        print_r($match[0][0]);
        echo '</pre>';
    } else {
        echo '<script>alert("Invalid Input ")</script>';
    }
    ?>
</body>

</html>