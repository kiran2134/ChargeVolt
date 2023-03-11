<!DOCTYPE html>
<html>

<body>
    <form method='post'>
        Enter string:
        <input type="text" name="string" id="num"><br>
        <input type="radio" name="choice" value="1">Display<br>
        <input type="radio" name="choice" value="2">Delete<br>
        <input type="submit" name="submit">
    </form>
    <?php
    $arr = array("Element1", "Element2");
    $string = $_POST['string'];
    $choice = $_POST['choice'];
    switch ($choice) {
        case 1:
            array_unshift($arr, $string);
            print_r($arr);
            break;
        case 2:
            echo "Deleted Element is " . array_shift($arr);
            break;
        default:
            echo "something went wrong";
    }
    ?>
</body>

</html>