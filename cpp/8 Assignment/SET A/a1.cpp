#include<iostream>
using namespace std;
class Shape{
     protected: 
     float area;
     public:
     virtual void calcarea()=0;
     void display()
     {
         cout<<"Area: "<<area<<endl;
     }
};
class Circle:virtual public Shape{
    int radius;
    public:
    void calcarea()
    {
         cout<<"Enter the radius: ";
         cin>>radius;
         area=3.14*radius*radius;
    }
};
class Rectangle:virtual public Shape{
    int l,b;
    public:
    void calcarea()
    {
        cout<<"Enter the length and breadth: ";
        cin>>l>>b;
        area=l*b;
    }
};
class Trapezoid:virtual public Shape{
    int x,y,z;
    public:
    void calcarea()
    {
         cout<<"Enter the x y z: ";
         cin>>x>>y>>z;
         area=x*y*z/2;
    }
};
int main()
{
    Shape *s;
    Circle c;
    Rectangle r;
    Trapezoid t;

    s=&c;
    s->calcarea();
    s->display();

    s=&r;
    s->calcarea();
    s->display();

    s=&t;
    s->calcarea();
    s->display();

    return 0; 
}