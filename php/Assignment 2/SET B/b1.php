<!-- Design a HTML page to accept a number and write a PHP script to display that  number in 
words e.g. 123 - one two three  -->

<!DOCTYPE html>
<html>

<body>
    <form method="GET">
        <label for="num">Enter num</label>
        <input type="text" name="num" id="num">
        <input type="submit" name="submit" id="">
    </form>
    <?php
    $num = $_GET['num'];
    switch ($num) {
        case 1:
            echo "One";
            break;
        case 2:
            echo "Two";
            break;
        case 3:
            echo "Three";
            break;
        case 4:
            echo "Four";
            break;
        case 5:
            echo "Five";
            break;
        case 6:
            echo "Six";
            break;
        case 7:
            echo "Seven";
            break;
        case 8:
            echo "Eight";
            break;
        case 9:
            echo "Nine";
            break;
        case 0:
            echo "Zero";
            break;

    }
    ?>
</body>

</html>