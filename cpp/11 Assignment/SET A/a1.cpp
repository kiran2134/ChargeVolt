#include <iostream>
#include <algorithm>
using namespace std;
template <typename T, int N>
void sortArray(T (&arr)[N])
{
    sort(arr, arr + N);
}
int main()
{
    int intArr[] = {5, 2, 7, 1, 9, 3};
    sortArray(intArr);
    cout << "Sorted integer array:";
    for (int i : intArr)
    {
        cout << " " << i;
    }
    return 0;
}
