#include <iostream>
using namespace std;
class account
{
protected:
    char acc_holder_name[10];
    char acc_holder_contactno[10];
};
class saving : public account
{
protected:
    int saving_acc_balance;
    char saving_account_no[10];

public:
    void accept()
    {
        cout << "enter acc holder name\n";
        cin >> acc_holder_name;
        cout << "enter accholder contact no\n ";
        cin >> acc_holder_contactno;

        cout << "enter saving acc balance\n";
        cin >> saving_acc_balance;
        cout << "enter saving acc no\n ";
        cin >> saving_account_no;
    }
    void calintrest()
    {
        saving_acc_balance = saving_acc_balance + (saving_acc_balance * (1.5 / 100));
        cout << "\ninterest calculated plz check balance \n";
    }
    void display()
    {
        cout << "acc holder name\t" << acc_holder_name << endl;
        cout << "acc holder contact no\t" << acc_holder_contactno << endl;
        cout << "saving acc balanace\t" << saving_acc_balance << endl;

        cout << "saving acc no\t" << saving_account_no << endl;
    }
    void withdrawsaving()
    {
        int remanbal, wamt;
        cout << "enter withdraw amount \n ";
        cin >> wamt;
        if (wamt > saving_acc_balance)
        {
            cout << "not enoughf balace\n";
        }
        else
        {
            remanbal = saving_acc_balance - wamt;
            saving_acc_balance = remanbal;

            if (saving_acc_balance < 2000)
            {

                cout << "service charge 500RS imposed\n";
            }
        }
    }
};
class current : public account
{
protected:
    int current_acc_balance;
    char current_account_no[10];

public:
    void currentaccept()
    {
        cout << "enter current acc balance\n";
        cin >> current_acc_balance;
        cout << "enter current acc no\n ";
        cin >> current_account_no;
    }
    void currentdisplay()
    {

        cout << "current  acc balanace\t" << current_acc_balance << endl;

        cout << "current acc no\t" << current_account_no << endl;
    }

    void withdrawcurrent()
    {
        int cremanbal, swamt;
        cout << "enter withdraw amount \n ";
        cin >> swamt;
        if (swamt > current_acc_balance)
        {
            cout << "not enoughf balace\n";
        }
        else
        {
            cremanbal = current_acc_balance - swamt;
            current_acc_balance = cremanbal;

            if (current_acc_balance < 5000)
            {

                cout << "service charge 1000RS imposed\n";
            }
        }
    }
};
int main()
{

    int n, ch;
    current obj;
    saving obj2;
    while (1)
    {
        cout << "enter 1 for accepting acc details\n";
        cout << "enter 2 for withra from saving\n";
        cout << "enter 3 for withra from current\n";
        cout << "enter 4 for cal interest as 10%\n";
        cout << " enter 5display detais of saving  and currentacc\n";
        cout << "ente 6 for exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj2.accept();
            obj.currentaccept();
            break;
        case 2:
            obj2.withdrawsaving();
            break;
        case 3:
            obj.withdrawcurrent();
            break;
        case 4:
            obj2.calintrest();
            break;
        case 5:
            obj2.display();
            obj.currentdisplay();
            break;

        case 6:
            exit(0);
            break;
        default:
            cout << "invalid\n";
        }
    }
    return 0;
}
