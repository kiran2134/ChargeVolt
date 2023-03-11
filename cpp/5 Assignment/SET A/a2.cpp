#include <iostream>
using namespace std;
class SI
{
    int P, R, N;

public:
    SI(int a, int c, int b = 5)
    {
        P = a;
        R = b;
        N = c;
    }
    void display()
    {
        int SI = P * R * N / 100;
        cout << "simple inetrest:" << SI;
    }
};
int main()
{
    SI S1(2000, 6);
    S1.display();
    return 0;
}
