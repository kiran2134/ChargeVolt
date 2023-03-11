#include <iostream>
#include <string.h>
using namespace std;
class One
{
public:
    int *a, n;
    One(int size)
    {
        n = size;
        a = new int[n];
        for (int i = 1; i <= n; i++)
        {
            a[i] = 0;
        }
    }
    void accept()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter data in array:";
            cin >> a[i];
        }
    }
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << endl
                 << a[i];
        }
        int median = a[1] + a[n - 1] / 2;
        cout << endl
             << "median:" << median;
    }
    ~One()
    {
        delete[] a;
        cout << "\n Object is deleted";
    }
};
int main()
{
    One d1(5);
    d1.accept();
    d1.display();
    return 0;
}