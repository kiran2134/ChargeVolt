#include <iostream>
#include <math.h>
using namespace std;
int power(double m, int n)
{
    return pow(m, n);
}
int power(int m, int n)
{
    return pow(m, n);
}
int main()
{
    cout << "value:" << power(4, 2) << endl;
    cout << "value:" << power(3, 3);
    return 0;
}