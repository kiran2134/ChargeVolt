<!DOCTYPE html>
<html>

<head>
	<title>Display Sales Orders</title>
</head>

<body>
	<form method="post">
		<label for="date">Enter sales order date:</label>
		<input type="date" id="date" name="date">
		<input type="submit" name="submit" value="Submit">
	</form>
	<?php
	if (isset($_POST['submit'])) {
		$date = $_POST['date'];
		$dbconn = pg_connect("host=localhost dbname=rv user=postgres password=1234") or die("Could not connect to database");
		$query = "SELECT * FROM Sales_order WHERE s_order_date < '$date'";
		$result = pg_query($dbconn, $query);
		if (!$result) {
			echo "An error occurred.\n";
			exit;
		}
		echo "<table>";
		echo "<tr><th>Sales Order Number</th><th>Sales Order Date</th><th>Client Number</th></tr>";
		while ($row = pg_fetch_row($result)) {
			echo "<tr><td>$row[0]</td><td>$row[1]</td><td>$row[2]</td></tr>";
		}
		echo "</table>";
		pg_close($dbconn);
	}
	?>
</body>

</html>