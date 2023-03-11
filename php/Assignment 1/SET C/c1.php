<?php
function floydstriangle($n)
{
    $value = 1;
    for ($i = 1; $i <= $n; $i++) {
        echo "\n";
        for ($j = 1; $j <= $i; $j++) {
            echo "$value ";
            $value++;
        }
        echo "\n";
    }
}
floydstriangle(4);
?>