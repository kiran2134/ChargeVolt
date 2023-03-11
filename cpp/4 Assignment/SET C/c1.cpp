#include <iostream>
#include <stdlib.h>
using namespace std;
class article
{
public:
    int aid, aq, ap;
    char aname[20];
    void accept();
    void display();
    void ape(article a[20], int n);
    void aqe(article a[20], int n);
};
void article::accept()
{
    cout << "\nEnter article id : ";
    cin >> aid;
    cout << "\nEnter article name :  ";
    cin >> aname;
    cout << "\nEnter article quantity : ";
    cin >> aq;
    cout << "\nEnter the article price : ";
    cin >> ap;
}
void article ::display()
{
    cout << "\nArticle id : " << aid << "\nArticle name : " << aname << "\nArticle Quantity : " << aq;
    cout << "\nArticle price : " << ap;
}
void article::ape(article a[20], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i].ap > 500)
        {
            cout << "\nArticle id : " << a[i].aid << "\nArticle name : " << a[i].aname << "\nArticle Quantity : " << a[i].aq;
            cout << "\nArticle price : " << a[i].ap;
        }
    }
}
void article::aqe(article a[20], int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i].aq > 50)
        {
            cout << "\nArticle id : " << a[i].aid << "\nArticle name : " << a[i].aname << "\nArticle Quantity : " << a[i].aq;
            cout << "\nArticle price : " << a[i].ap;
        }
    }
}
int main()
{
    article a1[20], a2;
    int i, n, ch;
    cout << "Enter the number of articles : ";
    cin >> n;
    while (1)
    {
        cout << "\n1.accept \n2.display \n3.More than 500 rs\n4.more than 50 quantity \n 5.exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            for (i = 1; i <= n; i++)
            {
                cout << "\nEnter article[" << i << "] information : \n";
                a1[i].accept();
            }
            break;
        case 2:
            for (i = 1; i <= n; i++)
            {
                cout << "\nArticle [" << i << "] information :\n";
                a1[i].display();
            }
            break;
        case 3:
            a2.ape(a1, n);
            break;
        case 4:
            a2.aqe(a1, n);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Wrong input";
            break;
        }
    }
    return 0;
}
