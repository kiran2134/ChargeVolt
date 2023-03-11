#include <iostream>
using namespace std;
#include <string.h>
class Cstring
{
    char s[10];
    int l;

public:
    void accept();
    void display();
    void findl();
    void concate(Cstring s1, Cstring s2);
    void compare(Cstring s1, Cstring s2);
};
void Cstring::accept()
{
    cout << "\nEnter the string:";
    cin >> s;
}
void Cstring::display()
{
    cout << "\nString:" << s;
}
void Cstring::findl()
{
    l = strlen(s);
    cout << "\nString length:" << l;
}
void Cstring::concate(Cstring s1, Cstring s2)
{
    char d[20];
    strcpy(d, s1.s);
    strcat(d, s2.s);
    cout << "\nConcatination:" << d;
}
void Cstring::compare(Cstring s1, Cstring s2)
{
    int i, n;
    n = strcmp(s1.s, s2.s);
    cout << "\nString compare:" << n;
}
int main()
{
    Cstring s1, s2, s3;
    s1.accept();
    s1.display();
    s1.findl();
    s2.accept();
    s2.display();
    s3.compare(s1, s2);
    s3.concate(s1, s2);
    return 0;
}