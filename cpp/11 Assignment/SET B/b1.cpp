#include <iostream>
using namespace std;
template <typename T>
T findMin(T arr[], int n)
{
    T minVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}
int main()
{
    int SIZE = 5, intArr[SIZE];
    float floatArr[SIZE];
    cout << "Enter " << SIZE << " integer values:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> intArr[i];
    }
    cout << "Enter " << SIZE << " floating point values:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> floatArr[i];
    }
    int intMin = findMin(intArr, SIZE);
    float floatMin = findMin(floatArr, SIZE);
    cout << "Minimum value in integer array: " << intMin << endl;
    cout << "Minimum value in float array: " << floatMin << endl;
    return 0;
}
