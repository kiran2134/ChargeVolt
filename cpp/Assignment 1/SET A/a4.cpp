#include<iostream>
using namespace std;
int main(){
    int a,b;
    char c;
    cout<<"Enter 2 values: ";
    cin>>a >>b;
    cout<<"\n\n '+' Additon | '-' Subtraction | '/' Division | '*' Multiplication\n\n";
    cout<<"Enter Operator: ";
    cin>>c;
    switch (c){
    case '+':
        cout<<a+b;
        break;
    case '-':
        cout<<a-b;
        break;
    case '/':
        cout<<a/b;
        break;
    case '*':
        cout<<a*b;
        break;
    default:
        break;
    }
}
