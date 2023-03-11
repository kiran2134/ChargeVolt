#include <iostream>
#include <string.h>
using namespace std;
class College
{
private:
    int dept_id, establishment_year, no_of_faculty, no_of_students;
    string dept_name;

public:
    void accept()
    {

        cout << "Enter Details ";

        cin >> dept_id >> dept_name >> establishment_year >> no_of_faculty >> no_of_students;
        // cin>>no_of_faculty;
    }
    void display()
    {
        cout << dept_id << dept_name << establishment_year << no_of_faculty << no_of_students << endl;
    }
    void specific_department(string sdept_name, int n, College C1[])
    {
        for (int i = 0; i < n; i++)
        {

            if (C1[i].dept_name.compare(sdept_name) == 0)
            {
                cout << C1[i].dept_id << " " << C1[i].dept_name << " " << C1[i].establishment_year << " " << C1[i].no_of_faculty << " " << C1[i].no_of_students << endl;
            }
        }
    }
    void specific_department(int syear, int n, College C1[])
    {
        for (int i = 0; i < n; i++)
        {
            // cout<<sdept_name<<C1[i].dept_name;

            if (C1[i].establishment_year == syear)
            {
                cout << C1[i].dept_id << " " << C1[i].dept_name << " " << C1[i].establishment_year << " " << C1[i].no_of_faculty << " " << C1[i].no_of_students << endl;
            }
        }
    }
    void decending_faculty(College C1[], int n)
    {
        int temp;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (C1[j].no_of_faculty < C1[j + 1].no_of_faculty)
                {
                    temp = C1[j].no_of_faculty;
                    C1[j].no_of_faculty = C1[j + 1].no_of_faculty;
                    C1[j + 1].no_of_faculty = temp;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << C1[i].no_of_faculty;
        }
    }
};
int main()
{
    int n, syear;
    string sdept_name;
    College C1[100], C2;

    cout << "Enter n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        C1[i].accept();
    }
    for (int i = 0; i < n; i++)
    {
        C1[i].display();
    }

    cout << "Enter Dept Name";
    cin >> sdept_name;

    C2.specific_department(sdept_name, n, C1);
    C2.decending_faculty(C1, n);
}