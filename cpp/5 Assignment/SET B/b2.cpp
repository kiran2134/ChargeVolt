#include <iostream>
#include <string.h>
using namespace std;
class Worker
{
public:
    char wname[20];
    int nod, pr, sal;
    Worker()
    {
        strcpy(wname, "\0");
        nod = 0;
        pr = 0;
    }
    Worker(int nw, int p, char name[20])
    {
        nod = nw;
        pr = p;
        strcpy(wname, name);
    }
    Worker(Worker &w1)
    {
        nod = w1.nod;
        pr = w1.pr;
        strcpy(wname, w1.wname);
    }
    int cal()
    {
        sal = pr * nod;
        return sal;
    }
    void display()
    {
        cout << "\nwname: " << wname << "\nno of days working: " << nod;
        cout << "\nPay rate: " << pr << "\nSalary: " << sal;
    }
    ~Worker()
    {
        cout << "\nDeleted object";
    }
};
int main()
{
    Worker w2(26, 1500, "RV");
    w2.cal();
    w2.display();
    return 0;
}
