#include <iostream>
using namespace std;
class student
{
    int rollno;
    char name[10];

public:
    void acceptinfo()
    {
        cout << "enter rollno\n";
        cin >> rollno;
        cout << "enter name\n";
        cin >> name;
    }
};
class theory : virtual public student
{
protected:
    int m1, m2, m3, m4, m5;

public:
    void acceptmarks()
    {
        cout << "enter marks of five sub\n";

        cout << "enter math mark\n";
        cin >> m1;
        cout << "enter eng mark\n";
        cin >> m2;
        cout << "enter sci mark\n";
        cin >> m3;
        cout << "enter cs mark\n";
        cin >> m4;
        cout << "enter os mark\n";
        cin >> m5;
    }
};
class practicle : public student
{
protected:
    int p1, p2;

public:
    void acceptpraticlemarks()
    {
        cout << "enter marks of two subjects\n";
        cout << "enter marks of c++\n";
        cin >> p1;

        cout << "enter marks of php\n";
        cin >> p2;
    }
};
class result : public theory, public practicle
{
    int totalmarks;
    char Class[10];

public:
    void display()
    {
        cout << "marks of five sub\n";
        cout << m1 << "\t" << m2 << "\t" << m3 << "\t" << m4 << "\t" << m5 << "\n";
        cout << "marks of praticle sub\n";
        cout << "c++" << p1 << endl;
        cout << "php" << p1 << endl;
        totalmarks = m1 + m2 + m3 + m4 + m5 + p1 + p2;
        cout << "\ntotal marks \n"
             << totalmarks;
        if (totalmarks >= 600 && totalmarks <= 700)
        {
            cout << "\nclass :: o\n";
        }
        else if (totalmarks >= 500 && totalmarks <= 600)
        {
            cout << "\nclass :: A\n";
        }
        else if (totalmarks >= 400 && totalmarks <= 500)
        {
            cout << "\nclass :: b\n";
        }
        else if (totalmarks >= 300 && totalmarks <= 400)
        {
            cout << "\nclass :: c\n";
        }
        else
        {
            cout << "\nfail\n";
        }
    }
};
int main()
{
    result obj;
    // obj.acceptmarks();
    // obj.acceptpraticlemarks();
    // obj.display();
    // return 0;
    int ch;
    while (1)
    {
        cout << "enter 1 for build a master table\n";
        cout << "enter 2 for accept praticlemarks \n";
        cout << "enter 3 for build a master table\n";
        cout << "enter 4 for exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.acceptmarks();
            break;

        case 2:
            obj.acceptpraticlemarks();
            break;

        case 3:
            obj.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "invalid\n";
        }
    }
    return 0;
}
