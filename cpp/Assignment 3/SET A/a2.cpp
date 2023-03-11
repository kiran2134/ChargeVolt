// Write a C++ program to print area of circle, square and rectangle using inline function.
#include<iostream>
using namespace std;
class Area{
    int side ,radius ,height,length;
    public:
        inline void area_of_circle(int radius){
            float pi = 3.14;
            cout<< int (pi * radius * radius) << endl;           //TypeCasting result to Integer
        }
        inline void area_of_square(int side){
            cout<< side * side << endl;
        }
        inline void area_of_rectangle(int length, int height){
            cout<< length * height <<endl;
        }
};
int main(){
    Area a1;
    a1.area_of_circle(3);
    a1.area_of_square(4);
    a1.area_of_rectangle(3,5);
}