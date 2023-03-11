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
        <label for="string">Enter the string 1:</label>
        <input type="text" name="str1" ;>
        <br>
        <label for="string">Enter the string 2:</label>
        <input type="text" name="str2" ;>
        <br>
        compare(strcmp)
        <input type="radio" name="op" value="1" ;>
        compare(==)
        <input type="radio" name="op" value="2" ;>
        Append
        <input type="radio" name="op" value="3" ;>
        reverse
        <input type="radio" name="op" value="4" ;>
        <br>
        <input type="submit" name="submit" ;>
    </form>
    <?php
    $str1 = $_POST['str1'];
    $str2 = $_POST['str2'];
    $op = $_POST['op'];
    $a;
    switch ($op) {
        case 1:
            if (strcmp($str1, $str2) == 0) {
                echo "strings are equal";
            } else {
                echo "string are not equal";
            }
            break;
        case 2:
            if ($str1 == $str2)
                echo "strings are equal";
            else
                echo "strings are not equal";
            break;
        case 3:
            $a = $str1 . $str2;
            echo "Append: $a";
            break;
        case 4:
            $a = strrev($str1 . $str2);
            echo "string reverse: $a";
            break;
        default:
            echo "wrong input";
            break;
    }
    ?>
</body>

</html>