#include <iostream>
using namespace std;
class Student
{

public:
    int s1, s2;
    int maximum(int m1, int m2);
    int maximum(int a[20], int n);
    void maximum(int a[20], int an, int m2);
};
int Student::maximum(int m1, int m2)
{
    if (m1 > m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}
int Student::maximum(int a[20], int n)
{
    int i, index, max;
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    cout << "Maximum:  " << a[index];
    return 0;
}
void Student::maximum(int a[], int an, int n)
{
    int i, index;
    for (i = 0; i < an; i++)
    {
        if (a[i] > n)
        {
            cout << a[i];
        }
    }
}
int main()
{
    Student s1;
    int i, b[20], k;
    cout << "Max: " << s1.maximum(48, 94) << endl;
    cout << "no of array: ";
    cin >> k;
    cout << "Enter the number: ";
    for (i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    s1.maximum(b, k);
    return 0;
}
