#include <iostream>
using namespace std;
#include <string.h>
#include <iomanip>
class Mobile
{
public:
    int mid;
    double mp;
    char mname[20];
    Mobile(int id, double p, char name[20])
    {
        mid = id;
        mp = p;
        strcpy(mname, name);
    }
    void display()
    {
        cout << "Mobile id: " << endl
             << "\n Mobile name: " << mname;
        cout << endl;
        cout << "Mobile price: " << fixed << setprecision(2) << mp;
    }
};
int main()
{
    Mobile m1(1, 14000, "Samsung");
    m1.display();
    return 0;
}
