#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter the numbers:";
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw b;
        else
        {
            c = a / b;
            cout << "Result: " << c;
        }
    }
    catch (const int x)
    {
        cerr << "cannot be divided because 2nd is 0";
    }
    return 0;
}