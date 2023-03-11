#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Vector
{
    T a[10];
    int n;

public:
    void accept()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i];
        }
    }
    void modify(T num, int index)
    {
        a[index] = num;
    }
    void multiply(T num)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] * num;
        }
    }
};
int main()
{
    Vector<int> v1;
    vector<float> v2;
    v1.accept();
    v1.display();
    v1.modify(10, 5);
    v1.multiply(20);
    return 0;
}