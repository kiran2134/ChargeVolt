#include <iostream>
using namespace std;
class Array
{
public:
    float a[20];
    void accept()
    {
        cout << "\nEnter the array";
        for (int i = 1; i < 5; i++)
        {
            cin >> a[i];
        }
    }
    void operator-()
    {
        for (int i = 1; i < 5; i++)
        {
            a[i] = -a[i];
        }
    }
    void display()
    {
        cout << "\nArrray after negation";
        for (int i = 1; i < 5; i++)
        {
            cout << a[i] << endl;
        }
    }
};
int main()
{
    Array a;
    a.accept();
    a.operator-();
    a.display();
    return 0;
}
