#include <iostream>
#include <math.h>
using namespace std;
float area_equi(float s1)
{
    return (sqrt(3) / 4 * (s1 * s1));
}
float area_iso(float base, float height)
{
    return (0.5 * base * height);
}
float area_right(float a, float b)
{
    return (a * b / 2);
}
int main()
{
    float area, base, height, a, b, s1;
    cout << "Enter the value of the side of the right angled triangle: ";
    cin >> a >> b;
    cout << "Area of right angled triangle is:";
    cout << area_right(a, b) << endl;

    cout << "Enter the value of the side of the isoceles triangle: ";
    cin >> base >> height;
    cout << "Area of isoceles triangle is:";
    cout << area_iso(base, height) << endl;

    cout << "Enter the value of the side of the equilateral triangle: ";
    cin >> s1;
    cout << "Area of equilateral triangle is: ";
    cout << area_equi(s1);
    return 0;
}