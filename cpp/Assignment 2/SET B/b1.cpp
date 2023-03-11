#include <iostream>
#include <string.h>
using namespace std;
class Department
{
private:
    int dept_id, year, nof, nos;
    char name[10];

public:
    void accept()
    {
        cout << "Enter details:";
        cin >> dept_id >> year >> nof >> nos >> name;
    }
    void display()
    {
        cout << dept_id << endl
             << year << endl
             << nof << endl
             << nos << endl
             << name;
    }
    void displaydept(Department D[], int n)
    {
        char dname[10];
        cout << "\nEnter dept name";
        cin >> dname;
        for (int i = 0; i < n; i++)
        {
            if (strcmp(dname, D[i].name) == 0)
                cout << endl
                     << D[i].dept_id << "\t" << D[i].name << "\t" << D[i].year << "\t" << D[i].nof << "\t" << D[i].nos;
        }
    }
    void displayyear(Department D[], int n)
    {
        int dyear;
        cout << "\nEnter the year:";
        cin >> dyear;
        for (int i = 0; i < n; i++)
        {
            if (dyear = D[i].year)
                cout << endl
                     << D[i].dept_id << "\t" << D[i].name << "\t" << D[i].year << "\t" << D[i].nof << "\t" << D[i].nos;
        }
    }
    void displayfac(Department D[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (D[i].nof > 10)
            {
                cout << D[i].dept_id << D[i].name << D[i].year << D[i].nof << D[i].nos;
            }
        }
    }
};
    int main(){
        Department Dobj;
        Department D[100];
        int n;
        cout << "\nEnter a:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            D[i].accept();
        }
        for (int i = 0; i < n; i++)
        {
            D[i].display();
        }
        Dobj.displaydept(D, n);
        Dobj.displayyear(D, n);
        Dobj.displayfac(D, n);
        return 0;
}
