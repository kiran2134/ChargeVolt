<?php

// Storing the elements of the webpage into an array
$source_code = file('https://www.geeksforgeeks.org');

// 1. traversing through each element of the array
// 2.printing their subsequent HTML entities
foreach ($source_code as $line_number => $last_line) {
    echo nl2br(htmlspecialchars($last_line) . "\n");
}

?>