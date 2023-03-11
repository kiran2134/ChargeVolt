#include<iostream>
using namespace std;
class B;
class A
{ 
    int x;
    public:
    void input()
    {   
    cout<<"enter x\n";
    cin>>x;
    }
    friend int substract(A ,B);
};
class B
{
    int y;
    public:
    void input1()
    {
    cout<<"enter y\n";
    cin>>y;
    }
    friend int substract(A,B);
};
int substract(A obj,B obj1)
{
    int ans;
   ans=obj.x-obj1.y;
   cout<<"substraction is "<<ans;
}
int main()
{
    A t;
    B t2;
    t.input();
    t2.input1();
    substract(t,t2);
    return 0;
}
