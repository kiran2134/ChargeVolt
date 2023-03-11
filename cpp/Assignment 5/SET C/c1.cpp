#include <iostream>
using namespace std;
#include <string.h>
class Bookshop
{
public:
    char *aname, *title, *pub;
    int sp, p, n, m;
    Bookshop(int size1, int size2)
    {
        n = size1;
        m = size2;
        aname = new char[n];
        title = new char[n];
        pub = new char[n];
        for (int i = 1; i <= m; i++)
        {
            strcpy(aname, "\0");
            strcpy(title, "\0");
            strcpy(pub, "\0");
        }
        sp = 0;
        p = 0;
    }
    void accept()
    {
        for (int i = 1; i <= m; i++)
        {
            cout << "\n Enter info[" << i << "] : \n";
            cout << "\n Enter the author name : ";
            cin >> aname;
            cout << "\n Enter the title : ";
            cin >> title;
            cout << "\n Enter the Publisher : ";
            cin >> pub;
            cout << "\n Enter the Price : ";
            cin >> p;
            cout << "\n Enter the Stock position : ";
            cin >> sp;
        }
    }
    void request()
    {
        char name[20], t[20], p1[20];
        int cp;
        cout << "\n Enter the Author Name : ";
        cin >> name;
        cout << "\n Enter the Title : ";
        cin >> t;
        cout << "\n Enter the Publisher : ";
        cin >> p1;
        cout << "\n Enter the Number of copy : ";
        cin >> cp;
        for (int i = 1; i <= m; i++)
        {
            if (strcmp(aname, name) == 0 && strcmp(title, t) == 0 && strcmp(pub, p1) == 0 && sp <= cp)
            {
                int y;
                y = cp * p;
                cout << "\n Total Cost : " << y;
            }
            else
            {
                cout << "\n Required Copies are not in stack";
            }
        }
    }
    ~Bookshop()
    {
        delete[] aname;
        delete[] title;
        delete[] pub;
        cout << "\n Object is Deleted.";
    }
};
int main()
{
    Bookshop B(20, 3);
    B.accept();
    B.request();
    return 0;
}
