<?php

// database connection details
$host = "localhost";
$dbname = "your_db_name";
$username = "your_username";
$password = "your_password";

// connect to database
$conn = new PDO("mysql:host=$host;dbname=$dbname", $username, $password);

// accept project name from user
$project_name = "Project A"; // replace with user input

// prepare SQL statement to retrieve employees and hours worked on the given project
$sql = "SELECT Emp.ename, Emp_Project.no_of_hrs_worked
        FROM Emp
        INNER JOIN Emp_Project ON Emp.eno = Emp_Project.emp_no
        INNER JOIN Project ON Emp_Project.pno = Project.pno
        WHERE Project.pname = :pname";

$stmt = $conn->prepare($sql);
$stmt->bindParam(':pname', $project_name);
$stmt->execute();

// display results
echo "<table>";
echo "<tr><th>Employee Name</th><th>Hours Worked</th></tr>";
while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
    echo "<tr><td>" . $row['ename'] . "</td><td>" . $row['no_of_hrs_worked'] . "</td></tr>";
}
echo "</table>";

// close database connection
$conn = null;

?>