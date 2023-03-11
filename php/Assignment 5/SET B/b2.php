<?php
// establish database connection
$db_host = 'localhost';
$db_name = 'database_name';
$db_user = 'username';
$db_pass = 'password';

$conn = new mysqli($db_host, $db_user, $db_pass, $db_name);

// check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// get department name from user input
$dept_name = $_POST['dept_name'];

// prepare and execute SQL query to get department statistics
$sql = "SELECT dept.dname, MAX(emp.esalary) AS max_salary, MIN(emp.esalary) AS min_salary, SUM(emp.esalary) AS sum_salary FROM emp INNER JOIN dept ON emp.dno = dept.dno WHERE dept.dname = ?";

$stmt = $conn->prepare($sql);
$stmt->bind_param("s", $dept_name);
$stmt->execute();

// bind results to variables
$stmt->bind_result($dname, $max_salary, $min_salary, $sum_salary);
$stmt->fetch();

// display result
echo "Department name: " . $dname . "<br>";
echo "Maximum Salary: " . $max_salary . "<br>";
echo "Minimum Salary: " . $min_salary . "<br>";
echo "Sum of the Salary: " . $sum_salary . "<br>";

// close database connection
$stmt->close();
$conn->close();
?>