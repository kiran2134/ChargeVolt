<!DOCTYPE html>
<html>

<head>
    <title>Class Timetable</title>
</head>

<body>

    <?php
    // Define an array of timetable information
    $timetable = array(
        array(
            'day' => 'Monday',
            '8:00am' => 'Math',
            '9:00am' => 'Science',
            '10:00am' => 'English',
            '11:00am' => 'History'
        ),
        array(
            'day' => 'Tuesday',
            '8:00am' => 'Math',
            '9:00am' => 'Science',
            '10:00am' => 'English',
            '11:00am' => 'History'
        ),
        array(
            'day' => 'Wednesday',
            '8:00am' => 'Math',
            '9:00am' => 'Science',
            '10:00am' => 'English',
            '11:00am' => 'History'
        ),
        array(
            'day' => 'Thursday',
            '8:00am' => 'Math',
            '9:00am' => 'Science',
            '10:00am' => 'English',
            '11:00am' => 'History'
        ),
        array(
            'day' => 'Friday',
            '8:00am' => 'Math',
            '9:00am' => 'Science',
            '10:00am' => 'English',
            '11:00am' => 'History'
        )
    );

    // Start the table
    echo '<table border="1">';

    // Table header
    echo '<tr>';
    echo '<th>Day</th>';
    echo '<th>8:00am</th>';
    echo '<th>9:00am</th>';
    echo '<th>10:00am</th>';
    echo '<th>11:00am</th>';
    echo '</tr>';

    // Loop through the array of timetable and display the information
    foreach ($timetable as $day) {
        echo '<tr>';
        echo '<td>' . $day['day'] . '</td>';
        echo '<td>' . $day['8:00am'] . '</td>';
        echo '<td>' . $day['9:00am'] . '</td>';
        echo '<td>' . $day['10:00am'] . '</td>';
        echo '<td>' . $day['11:00am'] . '</td>';
        echo '</tr>';
    }

    // End the table
    echo '</table>';
    ?>

</body>

</html>