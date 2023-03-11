<!DOCTYPE html>
<html>

<head>
    <title>Student Information</title>
</head>

<body>

    <?php
    // Define an array of student information
    $students = array(
        array(
            'name' => 'John Doe',
            'age' => 22,
            'class' => 'Senior'
        ),
        array(
            'name' => 'Jane Smith',
            'age' => 21,
            'class' => 'Junior'
        ),
        array(
            'name' => 'Bob Johnson',
            'age' => 20,
            'class' => 'Sophomore'
        )
    );

    // Loop through the array of students and display their information
    foreach ($students as $student) {
        echo '<h2>' . $student['name'] . '</h2>';
        echo '<p>Age: ' . $student['age'] . '</p>';
        echo '<p>Class: ' . $student['class'] . '</p>';
    }
    ?>

</body>

</html>