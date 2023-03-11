<?php
function ternary_test($n)
{
    $r = $n > 30
        ? "greater than 30"
        : ($n > 20
            ? "greater than 20"
            : ($n > 10
                ? "greater than 10"
                : "Input a number atlest greater than 10!"));
    echo $n . " : " . $r . "\n";
}
ternary_test(23);
ternary_test(33);
ternary_test(15);
ternary_test(10);
?>