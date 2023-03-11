#include<iostream>
using namespace std;
class Number2;
class Number1 {
    int num1;
    public:
        Number1() {num1 =100;}
        friend void subtract(Number1 Obj1 , Number2 Obj2 );
};

class Number2 {
    int num2;
    public:
        Number2() {num2 =50;}
        friend void subtract(Number1 , Number2 );
};

void subtract(Number1 Obj1 , Number2 Obj2){
    cout<< Obj1.num1 - Obj2.num2;
}
int main(){
    Number1 Obj1;
    Number2 Obj2;
    subtract(Obj1,Obj2);
}