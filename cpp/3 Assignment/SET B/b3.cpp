
#include <iostream>
using namespace std;
class Jwellery
{
    int Jwellery_Code;
    int Jwellery_Price;
    char Jwellery_Name[20];
    static int count;

public:
    void accept()
    {
        cout << "\n Enter Jwellery details : " << endl;
        cin >> Jwellery_Code >> Jwellery_Name >> Jwellery_Price;
        count++;
    }
    void display()
    {
        cout << "\n Jwellery Code : " << Jwellery_Code;
        cout << "\n Jwellery Name : " << Jwellery_Name;
        cout << "\n Jwellery Price : " << Jwellery_Price;
    }
    static int showcount()
    {
        return count;
    }
};
int Jwellery::count = 0;
int main()
{
    Jwellery j1, j2;
    j1.accept();
    cout << "\n Jwellery 1: ";
    j1.display();
    j2.accept();
    cout << "\n Jwellery 2: ";
    j2.display();
    cout << "\n Count is : " << j2.showcount();
    return 0;
    return (0);
}