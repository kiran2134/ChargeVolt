<!DOCTYPE html>
<html>

<body>
    <form method='post'>
        Enter string:
        <input type="text" name="string" id="num"><br>
        <input type="radio" name="choice" value="1">push<br>
        <input type="radio" name="choice" value="2">pop<br>
        <input type="submit" name="submit">
    </form>
    <?php
    $arr = array("Element1", "Element2");
    $string = $_POST['string'];
    $choice = $_POST['choice'];
    switch ($choice) {
        case 1:
            array_push($arr, $string);
            print_r($arr);
            break;
        case 2:
            echo "Popped Element is " . array_pop($arr);
            break;
        default:
            echo "something went wrong";
    }
    ?>
</body>

</html>