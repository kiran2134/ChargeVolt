#include <iostream>
using namespace std;
class emp
{
protected:
    char name[10];
    char designation[10];
};
class project : public emp
{
protected:
    int project_id;
    char title[10];
};
class emp_proj : public project
{
    // protected:
    int duration;

public:
    void accept()
    {
        cout << "enter name designation  id title duration\n";
        cin >> name >> designation >> project_id >> title >> duration;
    }
    void display()
    {
        cout << name << "\t" << designation << "\t" << project_id << "\t" << title << "\t" << duration << "\n";
    }
    int get_duration()
    {
        return duration;
    }
    void disprojectdetails()
    {
        cout << project_id << "\t" << title << "\t" << duration << "\n";
    }
};
int main()
{
    int i, j, n;
    emp_proj obj[10], temp;
    cout << "enter n\n";
    cin >> n;
    int ch;

    while (1)
    {
        cout << "enter 1 for master table\n";
        cout << "enter 2 for project details table\n";
        cout << " enter 3 for exit\n";
        cin >> ch;
        switch (ch)
        {

        case 1:
            for (i = 1; i <= n; i++)
            {
                obj[i].accept();
            }
            cout << "name \t designation \t id\t title\t duration\n";

            for (i = 1; i <= n; i++)
            {
                obj[i].display();
            }
            break;
        case 2:

            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (obj[i].get_duration() > obj[j].get_duration())
                    {
                        temp = obj[i];
                        obj[i] = obj[j];
                        obj[j] = temp;
                    }
                }
            }

            cout << "Project Details in Ascending Order of Duration:";

            cout << "\t id\t title\t duration\n";

            for (i = 1; i <= n; i++)
            {

                obj[i].disprojectdetails();
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "invalid\n";
        }
    }
    return 0;
}
