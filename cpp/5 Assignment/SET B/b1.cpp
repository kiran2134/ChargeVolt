#include <iostream>
using namespace std;
class Twod
{
public:
    int **a, m, n, **t;
    Twod(int r, int c)
    {
        m = r;
        n = c;
        a = new int *[m];
        t = new int *[m];
        for (int i = 1; i <= m; i++)
        {
            a[i] = new int[n];
            t[i] = new int[n];
        }
    }
    void accept()
    {
        cout << "Enter the element: ";
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void display()
    {
        cout << "\nElement are:\n";
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void transpose()
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                t[j][i] = a[i][j];
            }
        }
    }
    void tdisplay()
    {
        cout << "\nTranspose of matrix:\n";
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << t[i][j] << "\t";
            }
            cout << endl;
        }
    }
    ~Twod()
    {
        delete[] * a;
        delete[] * t;
        cout << "\nObject is deleted";
    }
};
int main()
{
    Twod t1(2, 2);
    t1.accept();
    t1.display();
    t1.transpose();
    t1.tdisplay();
    return 0;
}
