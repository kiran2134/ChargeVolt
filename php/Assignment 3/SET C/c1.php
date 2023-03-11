<html>

<body>
    <form method='post'>
        [1]<input type="radio" name="choice" value="1">Merge<br>
        [2]<input type="radio" name="choice" value="2">Intersection<br>
        [3]<input type="radio" name="choice" value="3">Difference<br>
        <input type="submit" name="submit">
    </form>
    <?php
    $arr = array('RV', 'Anand', 'Mandar', 'Eshaan');
    $alpha = array('RV', 'Manoj', 'Abhishek');
    $choice = $_POST['choice'];
    switch ($choice) {
        case 1:
            print_r(array_merge($arr, $alpha));
            break;
        case 2:
            $result = array_intersect($arr, $alpha);
            print_r($result);
            break;
        case 3:
            $result = array_diff($arr, $alpha);
            print_r($result);
            break;
    }
    ?>
</body>

</html>