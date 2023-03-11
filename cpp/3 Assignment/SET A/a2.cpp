#include <iostream>
using namespace std;
inline float area_circle(int r)
{
    float area_c = 3.14 * r * r;
    cout << "area of circle is " << area_c << "\n";
}
inline float area_square(int side)
{
    float areaof_square = side * side;
    cout << "area of square is " << areaof_square << "\n";
}
inline float areaof_rectangle(int length, int width)
{
    float area_rectangle = length * width;
    cout << "area of rectangle is " << area_rectangle;
}
int main()
{
    int r, side, length, width;
    cout << "enter radius for circle\n";
    cin >> r;
    area_circle(r);
    cout << "enter side of square\n";
    cin >> side;
    area_square(side);
    cout << "enter lenght and width\n";
    cin >> length >> width;
    areaof_rectangle(length, width);
    cout << "\n--------------------------\n";
    return 0;
}