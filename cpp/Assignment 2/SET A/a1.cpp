#include<iostream>
using namespace std;
class Cylinder
{
   private:   
   float radius,height;
   float volumn,area;
   public:
    void accept()
    { 
   cout<<"Enter the radius:";
   cin>>radius;
   cout<<"Enter the height:";
   cin>>height;
}
   void display()
   {
   area=2*(3.14*radius*height)+2*(3.14*radius*radius);
   volumn=3.14*radius*radius*height;
   cout<<"Area of a cylinder:"<<area<<endl;
   cout<<"Volumn of a cylinder:"<<volumn<<endl;
  }
};
int main()
{ 
    Cylinder obj1,obj2;
    obj1.accept();
    obj1.display();
    obj2.accept();
    obj2.display();
    return 0;  
}