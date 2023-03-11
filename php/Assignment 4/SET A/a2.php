<html>

<body>
    <form method=get>
        <center>
            <h2>For Triangle</h2>
            <table>
                <tr>
                    <td>Enter Base </td>
                    <td><input type="text" name="r"></td>
                </tr>
                <tr>
                    <td>Enter Height</td>
                    <td> <input type="text" name="h"></td>
                </tr>
                <tr>
                    <td><input type="radio" name=op value=1>Triangle</td>
                </tr>
            </table>
            <table>
                <center>
                    <h2>For Square</h2>
                </center>
                <tr>
                    <td>Enter Side</td>
                    <td> <input type="text" name="r1"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="radio" name=op value=2>Square</td>
                </tr>
                <center>
                    <h2>For Rectangle</h2>
                </center>
                <tr>
                    <td>Enter Length</td>
                    <td> <input type="text" name="r2"></td>
                </tr>
                <tr>
                    <td>Enter Breadth</td>
                    <td> <input type="text" name="h1"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="radio" name=op value=3>Rectangle</td>
                </tr>
                <center>
                    <h2>For Circle</h2>
                </center>
                <tr>
                    <td>Enter Radius</td>
                    <td> <input type="text" name="r3"></td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="radio" name=op value=2>Circle</td>
                </tr>
                <tr>
                    <td></td>
                    <td><input type="submit" value="SUBMIT"></td>
                </tr>
            </table>
        </center>
    </form>
</body>

</html>
<?php
define('pi', 3.14);
interface shape
{
    function calc_area($r, $h);
}

class Triangle implements shape
{
    function calc_area($r, $h)
    {
        return 1 / 2 * $r * $h;
    }


}

class Square implements shape
{
    function calc_area($r, $h)
    {
        return $r * $r;
    }

}

class Rectangle implements shape
{
    function calc_area($r, $h)
    {
        return $r * $h;
    }

}
class Circle implements shape
{
    function calc_area($r, $h)
    {
        return pi * $r * $r;
    }
}

$op = $_GET['op'];

switch ($op) {
    case 1:
        $r = $_GET['r'];
        $h = $_GET['h'];
        $ob = new Triangle();
        $a = $ob->calc_area($r, $h);
        echo "Area of Triangle is" . $a;
        break;

    case 2:
        $r = $_GET['r'];

        $ob = new Square();
        $a = $ob->calc_area($r);
        echo "Area of Square is" . $a;
        break;

    case 3:
        $r = $_GET['r'];
        $h = $_GET['h'];
        $ob = new Rectangle();
        $a = $ob->calc_area($r, $h);
        echo "Area of Rectangle is" . $a;
        break;
    case 4:
        $r = $_GET['r'];
        $ob = new Circle();
        $a = $ob->calc_area($r);
        echo "Area of Circle is" . $a;
        break;
}
?>