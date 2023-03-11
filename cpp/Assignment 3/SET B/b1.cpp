// Write a C++ program to create two classes DM and DB which stores the value of distances. DM
// stores distance in m and cm and DB stores distance in feet and inches. Write a program that can
// read value for the class objects and add one object of DM with the other object of DB by using
// friend function

#include<iostream>
using namespace std;
class DB;
class DM{
    int m , cm;
    public:
    
        DM(){
            m=12;
            cm=8;
        }
        ~DM(){
            cout<<"Destructered DM";
        }
        friend void display(DM Obj1,DB Obj2);
        friend void sum(DM Obj1,DB Obj2);
};

class DB{
    int feet , inches;
    public:
        DB(){
            feet = 10;
            inches = 3;
        }
        friend void display(DM Obj1,DB Obj2);
        friend void sum(DM Obj1,DB Obj2);
};

void display(DM Obj1,DB Obj2){
        cout<<Obj1.m << " " << Obj1.cm << " " << Obj2.feet << " " << Obj2.inches << endl;
}
void sum(DM Obj1,DB Obj2){
    float MFeet  = Obj1.m * 3.28;
    float CInches = Obj1.cm * 0.39;
    cout<< CInches<< endl;
    cout<< "Sum of Feet and Meter is : " << MFeet + Obj2.feet << endl;
    cout<< "Sum of Inches and Cm is : " << CInches + Obj2.inches << endl;
}
 
int main(){

    DM Obj1;
    DB Obj2;
    
    display(Obj1,Obj2);
    sum(Obj1,Obj2);
}