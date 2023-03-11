<html>

<body>
    <form method='post'>
        [1]<input type="radio" name="choice" value="1">ksort<br>
        [2]<input type="radio" name="choice" value="2">krsort<br>
        [3]<input type="radio" name="choice" value="3">arsort<br>
        [4]<input type="radio" name="choice" value="4">filter<br>
        <input type="submit" name="submit">
    </form>
    <?php
    $arr = array("RV" => "20", "Anand" => "19", "Mandar" => "18", "Eshaan" => "21", "Manoj" => "22");
    $choice = $_POST['choice'];
    switch ($choice) {
        case 1:
            ksort($arr);
            foreach ($arr as $x => $x_value) {
                echo "Key=" . $x . ", Value=" . $x_value;
                echo "<br>";
            }
            break;
        case 2:
            krsort($arr);
            foreach ($arr as $x => $x_value) {
                echo "Key=" . $x . ", Value=" . $x_value;
                echo "<br>";
            }
            break;
        case 3:
            arsort($arr);
            foreach ($arr as $x => $x_value) {
                echo "Key=" . $x . ", Value=" . $x_value;
                echo "<br>";
            }
            break;
        case 4:
            function odd($arr)
            {
                return ($arr & 1);
            }
            print_r(array_filter($arr, "odd"));
            break;
        default:
            echo "Something went wrong";
    }
    ?>
</body>

</html>