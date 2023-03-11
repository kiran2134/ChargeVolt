#include<iostream>
using namespace std;
class db;
class dm{
    float m,cm;
    public:
    void input()
    {
    cout<<"enter m and cm\n";
    cin>>m>>cm;
    }
    friend void add(dm,db);
};
class db{
    float feet,inches;
    public:
    void input1()
    {
    cout<<"enter feet and inches\n";
    cin>>feet>>inches;
}
    friend void add(dm,db);
};
void add(dm x,db y)
{
    x.m=y.feet*0.3048;
    x.cm=y.inches*2.54;
    cout<<"total meter "<<x.m<<"\n";
    cout<<"total cm"<<x.cm;
}
int main()
{
    dm obj;
    db obj1;
    obj.input();
    obj1.input1();
    add(obj,obj1);
    return 0;
}
