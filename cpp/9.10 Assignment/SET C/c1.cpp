#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int i;
    try
    {
        cout << "Enter the index of the element you want to access: ";
        cin >> i;
        if (i < 0 || i >= 5)
            throw "Index out of bounds exception!";

        cout << "The value at index " << i << " is: " << arr[i] << endl;
    }
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
    return 0;
}