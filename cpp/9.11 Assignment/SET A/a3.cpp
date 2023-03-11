#include <iostream>
using namespace std;
template <typename T>
void sqr(T a)
{
    cout << a * a << endl;
}
int main()
{
    int i;
    float j;
    double k;
    cout << "Enter the number:";
    cin >> i >> j >> k;
    sqr(i);
    sqr(j);
    sqr(k);
    return 0;
}