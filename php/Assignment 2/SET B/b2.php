<html lang="en">

<head>
    <title>Document</title>
</head>

<body>
    <form method="GET">
        <label for="num">Enter string</label>
        <input type="text" name="string" id="string">
        <input type="submit" name="submit" id="">
    </form>

    <?php
    $string = $_GET['string'];

    $i;
    $flag = 0;
    $aCount = $eCount = $iCount = $oCount = $uCount = 0;
    $length = strlen($string);

    for ($i = 0; $i < $length; $i++) {
        if ($string[$i] == 'a' || $string[$i] == 'A') {
            $aCount++;
            $flag++;
        } else if ($string[$i] == 'e' || $string[$i] == 'E') {
            $eCount++;
            $flag++;
        } else if ($string[$i] == 'i' || $string[$i] == 'I') {
            $iCount++;
            $flag++;
        } else if ($string[$i] == 'o' || $string[$i] == 'O') {
            $oCount++;
            $flag++;
        } else if ($string[$i] == 'u' || $string[$i] == 'U') {
            $uCount++;
            $flag++;
        }
    }
    echo "<h1> Total No of Vowels Found : $flag </h1></br></br>
             <h1> Total NO of A : $aCount </h1></br>
             <h1> Total NO of E : $eCount </h1></br>
             <h1> Total NO of I : $iCount </h1></br>
             <h1> Total NO of O : $oCount </h1></br>
             <h1> Total NO of U : $uCount </h1></br>
        ";
    // ?>
</body>

</html>