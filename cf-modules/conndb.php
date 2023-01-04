<?php
$server = "141.148.162.186";
$username = "u18_tQNX0LfXqj";
$password = "X^R+a1nI5LITrBNj@Yv77PDX";
$database = "s18_cf-users";
// Create connection
$conn = mysqli_connect($server, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}else{
  echo "Connected Successfully!";
}
?>