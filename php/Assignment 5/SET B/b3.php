<?php
// Establish database connection
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "myDB";
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Accept experience value from the user
$experience = $_POST['experience'];

// Prepare the update statement
$sql = "UPDATE Doctor SET city='Mumbai' WHERE experience < $experience";

// Execute the update statement
if (mysqli_query($conn, $sql)) {
    echo "City updated successfully for all doctors with experience less than $experience";
} else {
    echo "Error updating city: " . mysqli_error($conn);
}

// Close the database connection
mysqli_close($conn);
?>