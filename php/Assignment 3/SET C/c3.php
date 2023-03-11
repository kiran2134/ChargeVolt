<html>

<body>
    <?php
    $a1 = array("rohit", "anand", "mandar");
    $a2 = array("abhishek", "manoj", "eshaan");
    array_multisort($a1, SORT_ASC, $a2, SORT_DESC);
    print_r($a1);
    print_r($a2);
    ?>
</body>

</html>