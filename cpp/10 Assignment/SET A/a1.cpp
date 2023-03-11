#include <iostream>
#include <cmath>
using namespace std;
int my_sqrt(int num)
{
    if (num < 0)
    {
        throw "Number cannot be negative:";
    }
    return sqrt(num);
}
int main()
{
    int num;
    cout << "Enter a number to compute its square root:";
    cin >> num;
    try
    {
        int result = my_sqrt(num);
        cout << "Square root of"
             << " " << num << " "
             << "is"
             << " " << result << endl;
    }
    catch (const char *msg)
    {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}