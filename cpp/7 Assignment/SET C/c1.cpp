#include <iostream>
using namespace std;
class learninfo
{
protected:
    int rollno;
    char studname[10];
    char cls[10];
    float percent;
};
class earn_info
{
protected:
    int no_of_hour_worked;
    int charges_per_hour;
};
class earn_learn_info : public learninfo, public earn_info
{
    int salary;

public:
    earn_learn_info()
    {
        cout << "enter roll no\n";
        cin >> rollno;
        cout << "enter student name\n";
        cin >> studname;
        cout << "enter class \n";
        cin >> cls;
        cout << "enter percent\n";
        cin >> percent;
        cout << "enter no of hour worked\n";
        cin >> no_of_hour_worked;
        cout << "enter charges per hour\n";
        cin >> charges_per_hour;
    }
    void cal()
    {
        salary = no_of_hour_worked * charges_per_hour;
        cout << "salary that you earned\n"
             << salary;
    }
    void display()
    {
        cout << " roll no\t" << rollno;
        cout << "student name\t" << studname;
        cout << " class \t" << cls;
        cout << " percent\t" << percent;
        cout << " no of hour worked\t" << no_of_hour_worked;
        cout << " charges per hour\t" << charges_per_hour;
    }
};
int main()
{
    earn_learn_info obj;
    obj.cal();
    obj.display();
    return 0;
}