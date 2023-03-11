<?php
$multi = array(
    array(2, 5, 6, 7),
    array(3, 4, 8, 9),
    array(8, 1, 2, 5)
);
for ($i = 0; $i < count($multi); $i++) {
    for ($j = 0; $j < count($multi[$i]); $j++)
        echo $multi[$i][$j];
    echo "<br>";
}
echo "<br>";
?>