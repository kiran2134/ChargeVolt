#include <iostream>
using namespace std;
class Number
{
    int x, y;

public:
    Number()
    {
        x = 0;
        y = 0;
    }
    Number(int a, int b)
    {
        x = a;
        y = b;
    }
    Number(Number &N)
    {
        x = N.x;
        y = N.x;
    }
    void display()
    {
        int max = x > y ? x : y;
        cout << "\nx=" << x << "\ny=" << y;
        cout << "\nmax is" << max;
    }
    ~Number()
    {
        cout << "\nObject is deleted";
    }
};
int main()
{
    Number N1;
    Number N2(40, 50);
    Number N3(N2);
    N1.display();
    N2.display();
    N3.display();
    return 0;
}