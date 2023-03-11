#include<iostream>
using namespace std;
class employee{
    private:
        int empno;
        char name[20];
        float basic,hra,da,allowances;
    public:
        void accept(){
            cout<<"Enter Employee ID:";
            cin>>empno;
            cout<<"Enter Employee Name:";
            cin>>name;
            cout<<"Enter Basic Salary:";
            cin>>basic;
            hra=700;
            da=0.45*basic;
            allowances-0.75*basic;
        }
        void display(){
            cout<<"Employee ID:"<<empno;
            cout<<"Employee Name:"<<name;
            cout<<"Basic Salary:"<<basic;
            cout<<"Da:"<<da;
            cout<<"hra:"<<hra;
            cout<<"Allowances:"<<allowances;
        }
};
int main(){
    employee e;
    e.accept();
    e.display();
    return 0;
}