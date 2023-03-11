// Write a C++ program to create two classes Rectangle1 and Rectangle2. Compare area of both the
// rectangles using friend function

#include <iostream>
using namespace std;

class Rectangle2;
class Rectangle1
{
    int length, breadth, area;

public:
    Rectangle1()                  //Constructor
    {
        length = 10;
        breadth = 5;
    }

    void rect_area()
    {
        area = length * breadth;
    }
    friend void compare(Rectangle1 Obj1, Rectangle2 Obj2);
    // ~Rectangle1();
};
class Rectangle2
{
    int length, breadth, area;

public:
    Rectangle2()                  //Constructor
    {
        length = 8;
        breadth = 5;
    }
    void rect_area()
    {
        area = length * breadth;
    }
    friend void compare(Rectangle1 Obj1, Rectangle2 Obj2);
    // ~Rectangle2();
};

void compare(Rectangle1 Obj1, Rectangle2 Obj2)
{
    Obj1.rect_area();
    Obj2.rect_area();
    cout << Obj1.area << endl
         << Obj2.area << endl
         << endl;
    Obj1.area > Obj2.area ? cout << "Rectangle 1 is bigger" : cout << "Rectangle 2 is bigger";
}

// Rectangle1 :: ~Rectangle1(){
//     cout<< endl <<"Rectangle 1 Destructured" << endl;
// }
// Rectangle2 :: ~Rectangle2(){
//     cout<< endl <<"Rectangle 2 Destructured" << endl;
// }

int main()
{
    Rectangle1 Obj1;
    Rectangle2 Obj2;

    compare(Obj1, Obj2);
    return 0;
}