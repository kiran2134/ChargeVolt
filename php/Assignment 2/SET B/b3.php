<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body {
            background-color: blueviolet;
        }

        form {
            display: flex;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
    </style>
</head>

<body>
    <form method="POST">
        <label for="num1">Enter num</label>
        <input type="number" name="num1" id="num1">
        <label for="num2">Enter num</label>
        <input type="number" name="num2" id="num2"></br>
        <input type="radio" name="sum" value="add">Add</br>
        <input type="radio" name="sum" value="subtract">Subtract</br>
        <input type="radio" name="sum" value="multiply">Multiply</br>
        <input type="radio" name="sum" value="divide">Divide</br>
        <input type="submit" name="submit" id="">
    </form>
    <?php
    $num1 = $_POST['num1'];
    $num2 = $_POST['num2'];

    if (isset($_POST['sum'])) {
        $sum = $_POST['sum'];
    } else {
        echo "<p>Please select a Arithmetic Operation</p>";
    }
    if ($sum == 'add') {
        echo "Addition is : " . $num1 + $num2;
    } else if ($sum == 'subtract') {
        echo "Subtraction is : " . $num1 - $num2;
    } else if ($sum == 'multiply') {
        echo "Miltiplication is : " . $num1 * $num2;
    } else if ($sum == 'divide') {
        echo "Remainder is " . $num1 / $num2;
    } else {
        echo "Something Went wrong RELOAD!!";
    }
    ?>
</body>

</html>