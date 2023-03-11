#include <iostream>
using namespace std;
class ComplexNumber
{
    int real, imag;

public:
    void accept()
    {
        cout << "\n Enter real no : ";
        cin >> real;
        cout << "\n Enter imaginary : ";
        cin >> imag;
    }
    void dis()
    {
        cout << "Complex no is : " << real << "+" << imag << "i" << endl;
    }
    friend void cal(ComplexNumber &a, ComplexNumber &b);
    void display()
    {
        cout << "\n Addition is : ";
        cout << real << "+" << imag << "i";
    }
};
void cal(ComplexNumber &a, ComplexNumber &b)
{
    a.real = a.real + b.real;
    a.imag = a.imag + b.imag;
}
int main()
{
    ComplexNumber c1, c2;
    cout << "\n Enter details of 1st no: ";
    c1.accept();
    c2.accept();
    c1.dis();
    c2.dis();
    cal(c1, c2);
    c1.display();
    return 0;
}