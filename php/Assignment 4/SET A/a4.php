<?php
// Define a class
class Car
{
    public $make;
    public $model;
    public $year;

    function __construct($make, $model, $year)
    {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    function display()
    {
        echo "Make: " . $this->make . ", Model: " . $this->model . ", Year: " . $this->year;
    }
}

// Create an instance of the class
$myCar = new Car("Toyota", "Corolla", 2021);

// Use the get_object_vars() function to get the properties of the object
$vars = get_object_vars($myCar);
echo "Properties of the object: ";
print_r($vars);
echo "<br>";

// Use the get_class() function to get the class name of the object
$class = get_class($myCar);
echo "Class name of the object: " . $class . "<br>";

// Use the get_class_methods() function to get the methods of the object
$methods = get_class_methods($myCar);
echo "Methods of the object: ";
print_r($methods);
echo "<br>";

// Use the method_exists() function to check if a method exists in the object
if (method_exists($myCar, 'display')) {
    echo "The object has the 'display' method.<br>";
} else {
    echo "The object does not have the 'display' method.<br>";
}
?>