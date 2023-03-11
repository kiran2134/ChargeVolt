<html?>
<body>
    <style>
              body {
                  background-color:skyblue;
              }
              h1 {text-align: center;}
        </style>
    <form  method="GET">
        <label for="num">Enter number</label>
        <input type="text" name="num" id="num"> 
        <input type="submit" name="submit" id="">
    </form>
    <?php 
        $num = $_GET['num'];
        $factorial = 1;
        for ($x=$num; $x>=1; $x--)
        {
        $factorial = $factorial * $x;
        }
        echo "Factorial of $num is $factorial";
        ?>
</body>
</html>