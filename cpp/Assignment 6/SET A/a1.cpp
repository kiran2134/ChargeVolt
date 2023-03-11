#include <iostream>
using namespace std;
class Number
{
    int num;

public:
    void accept()
    {
        cout << "Enter num \n";
        cin >> num;
    }
    void operator++()
    {
        num++;
    }
    void operator++(int)
    {
        ++num;
    }
    void display()
    {
        cout << num;
    }
};
int main()
{
    Number n;
    n.accept();
    ++n;
    cout << "pre increment is \n";
    n.display();
    n++;
    cout << "\nPost increment is \n";
    n.display();
    return 0;
}
