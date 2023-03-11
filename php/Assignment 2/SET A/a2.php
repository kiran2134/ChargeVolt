<html>

<body>

    <head>
        <style>
            body {
                background-color: mediumaquamarine;
            }
        </style>
    </head>
    <form method="post">
        <label for="string">Enter the string</label>
        <input type="text" name="string" id="string">
        <input type="submit" name="submit" id="submit">
    </form>
    <?php
    $string = $_POST["string"];
    $rev_str;
    echo $string . "<br>";
    $len = strlen($string);
    $j = $len - 1;
    for ($i = 0; $i < $len; $i++) {
        $rev_str[$i] = $string[$j];
        $j--;
        echo $rev_str[$i];
    }
    ?>
</body>

</html>