#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
    int p_code;
    char p_name[50];

public:
    void get_person_data()
    {
        cout << "Enter person code: ";
        cin >> p_code;
        cout << "Enter person name: ";
        cin >> p_name;
    }
    void display_person_data()
    {
        cout << "Person Code: " << p_code << endl;
        cout << "Person Name: " << p_name << endl;
    }
};

class Account : virtual public Person
{
protected:
    int ac_no;
    float balance;

public:
    void get_account_data()
    {
        cout << "Enter account number: ";
        cin >> ac_no;
        cout << "Enter account balance: ";
        cin >> balance;
    }
    void display_account_data()
    {
        cout << "Account Number: " << ac_no << endl;
        cout << "Account Balance: " << balance << endl;
    }
};

class Official : virtual public Person
{
public:
    char designation[50];
    int experience;

public:
    void get_official_data()
    {
        cout << "Enter designation: ";
        cin >> designation;
        cout << "Enter experience: ";
        cin >> experience;
    }
    void display_official_data()
    {
        cout << "Designation: " << designation << endl;
        cout << "Experience: " << experience << endl;
    }
};

class Employee : public Account, public Official
{
public:
    void get_employee_data()
    {
        get_person_data();
        get_account_data();
        get_official_data();
    }
    void display_employee_data()
    {
        display_person_data();
        display_account_data();
        display_official_data();
    }
};

int main()
{
    int choice, n, i;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee emp[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter data for employee " << i + 1 << ":" << endl;
        emp[i].get_employee_data();
    }
    while (true)
    {
        cout << "\n1. Display all employees" << endl;
        cout << "2. Display employees with HOD designation" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (i = 0; i < n; i++)
            {
                cout << "\nDetails of employee " << i + 1 << ":" << endl;
                emp[i].display_employee_data();
            }
            break;
        case 2:
            cout << "\nEmployees with HOD designation:" << endl;
            for (i = 0; i < n; i++)
            {
                if (strcmp(emp[i].designation, "HOD") == 0)
                {
                    cout << "\nDetails of employee " << i + 1 << ":" << endl;
                    emp[i].display_employee_data();
                }
            }
            break;
        case 3:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
