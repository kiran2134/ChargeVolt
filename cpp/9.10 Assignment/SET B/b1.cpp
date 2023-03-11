#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n < 0)
    {
        throw "Negative number exception!";
    }
    if (n > 20)
    {
        throw bad_alloc();
    }
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    try
    {
        int result = factorial(n);
        cout << "Factorial of " << n << " is " << result << endl;
    }
    catch (const char *e)
    {
        cerr << "Error: " << e << endl;
    }
    catch (bad_alloc &e)
    {
        cerr << "Error: Out of memory!" << endl;
    }
    return 0;
}
