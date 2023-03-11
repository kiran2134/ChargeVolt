#include<iostream>
using namespace std;
class Distance{
        public:
        int feet , inches;
    public:
        void accept(){
            cout<< endl <<"Enter inches";
            cin>>inches;
            cout<< endl <<"Enter feet";
            cin>>feet;
        }
        void display(){
            cout<< endl <<"Feet : "<<feet<<" Inches : "<<inches;
        }
        void sum(){
            int sum = feet + inches;
            cout<< endl <<"Sum is : "<<sum;
        }
};
int main(){
    Distance Obj1, Obj2;
    Obj1.accept();
    Obj1.display();
    // Obj1.sum();

    Obj2.accept();
    Obj2.display();
    // Obj2.sum();

    int feetsum  = Obj1.feet + Obj2.feet;
    int inchessum  = Obj1.inches + Obj2.inches;
    cout<< endl << "Sum of feet is : " <<feetsum;
    cout<< endl << "Sum of inches is : " <<inchessum;
    return 0;
}