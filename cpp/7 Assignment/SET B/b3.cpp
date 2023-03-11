#include <iostream>
using namespace std;

class student
{
protected:
    int rno;
    char name[10], cls[10];

public:
    void accept()
    {
        cout << " Enter roll no if sudent : ";
        cin >> rno;
        cout << "Enter the name of student : ";
        cin >> name;
        cout << " Enter the class of student : ";
        cin >> cls;
    }
    void display()
    {
        cout << "Roll no. :" << rno << "Name :" << name << "class : " << cls << endl;
    }
};
class Internal_Mark : public virtual student
{
protected:
    int i_mark[6];

public:
    int internal_mark()
    {
        int i;
        cout << " Enter the 5 subjects marks : ";
        for (i = 1; i <= 5; i++)
        {
            cout << "subject " << i << " : ";
            cin >> i_mark[i];
        }
        for (i = 1; i <= 5; i++)
        {
            if (i_mark[i] < 35)
                return 1;
        }
        return 0;
    }
    void i_display()
    {
        cout << " Internal marks is :\n ";
        for (int i = 1; i <= 5; i++)
        {
            cout << "subject " << i << "	" << i_mark[i] << endl;
        }
    }
};
class External_Mark : public virtual student
{
protected:
    int e_mark[6];

public:
    int external_mark()
    {
        int i;
        cout << " Enter the5 subjects External marks : ";
        for (i = 1; i <= 5; i++)
        {
            cout << "subject " << i << " : ";
            cin >> e_mark[i];
        }
        for (i = 1; i <= 5; i++)
        {
            if (e_mark[i] < 35)
                return 1;
        }
        return 0;
    }
    void e_display()
    {
        cout << " eXternal marks are \n: ";
        for (int i = 1; i <= 5; i++)
        {
            cout << "subject " << i << "	" << e_mark[i] << endl;
        }
    }
};
class result : public Internal_Mark, public External_Mark
{
    int total[6];
    char grade[10];
    float per;

public:
    void cal_res()
    {
        for (int i = 1; i <= 5; i++)
        {
            total[i] = i_mark[i] + e_mark[i];
        }
    }
    void dis_res()
    {
        display();
        i_display();
        e_display();
        cout << "Total marks :\n ";
        for (int i = 1; i <= 5; i++)
        {
            cout << "subject " << i << "	" << total[i] << endl;
        }
    }
};
int main()
{

    int n, ch, a, b;
    result obj;
    while (1)
    {
        cout << " 1.student info 2.Internal mark 3.Extranal mark 4. Result 0. exit ";
        cout << " Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.accept();
            break;
        case 2:
            a = obj.internal_mark();
            break;
        case 3:
            b = obj.external_mark();
            break;
        case 4:
            if (a == 0 && b == 0)
            {
                obj.cal_res();
                obj.dis_res();
            }
            else
                cout << "Fail\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice : ";
        }
    }
    return 0;
}