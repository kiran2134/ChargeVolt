<html>

<body>
    <form method='POST'>
        Enter radius:
        <input type='text' name='radius'><br>
        Enter height:
        <input type='text' name='height'><br>
        <pre><input type='submit' name='submit' value='Area.'>  <input type='reset' name='reset' value='reset'>
</form>
<?php
$r = $_POST['radius'];
$h = $_POST['height'];
define('PPI', '3.1412');
interface fun
{
    function area($r, $h);
    function volume($r, $h);
}
class cylinder implements fun
{
    function area($r, $h)
    {
        $area = (2 * PPI * $r * ($r + $h));
        echo "<center><h3>The area of cylinder is:     $area</center></h3>";
    }
    function volume($r, $h)
    {
        $v = (PPI * $r * $r * $h);
        echo "<center><h3>The volume of cylinder is:     $v</center></h3>";
    }
}
$o = new cylinder;
$o->area($r, $h);
$o->volume($r, $h);
?>
</body>
</html>