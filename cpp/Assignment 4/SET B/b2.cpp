#include <iostream>
using namespace std;
class pd
{
public:
    void print(int n)
    {
        cout << n;
    }
    void print(char *str)
    {
        cout << endl
             << str;
    }
    void print(char *str, int n)
    {
        int i = 0;
        while (i < n)
        {
            cout << str[i];
            i++;
        }
    }
};
int main()
{
    pd p;
    p.print(5);
    p.print("mno");
    cout << endl;
    p.print("name", 3);
    return 0;
}
