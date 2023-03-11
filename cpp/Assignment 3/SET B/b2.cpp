#include <iostream>
using namespace std;
class rectangle2;
class rectangle1
{
    int l1, b1;

public:
    void accept()
    {
        cout << "enter length and breadth\n";
        cin >> l1 >> b1;
    }
    friend void compare(rectangle1, rectangle2);
};
class rectangle2
{
    int l2, b2;

public:
    void input()
    {

        cout << "enter length and breadth\n";
        cin >> l2 >> b2;
    }
    friend void compare(rectangle1, rectangle2);
};
void compare(rectangle1 x, rectangle2 y)
{
    if (x.l1 * x.b1 > y.l2 * y.b2)
    {
        cout << "rectagle 1 is bigger than 2\n";
    }
    else
    {
        cout << "rectagle 2 is bigger than 1\n";
    }
}
int main()
{
    rectangle1 obj;
    rectangle2 obj1;
    obj.accept();
    obj1.input();
    compare(obj, obj1);
    return 0;
}