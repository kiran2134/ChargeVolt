<?php
function primenumber($n)
{
    $i = 1;
    if ($n % $i == 0 && $n % 2 != 0) {
        echo "Number is Prime";
    } else {
        echo "Number is Not Prime";
    }
}

primenumber(7);
?>