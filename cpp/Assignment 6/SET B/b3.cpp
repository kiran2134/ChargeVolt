#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
    char *data;

public:
    String()
    {
        data = new char[1];
        *data = '\0';
    }
    String(const char *s)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }
    String(const String &s)
    {
        data = new char[strlen(s.data) + 1];
        strcpy(data, s.data);
    }
    ~String()
    {
        delete[] data;
    }
    String operator!()
    {
        String result(*this);
        for (int i = 0; i < strlen(data); i++)
        {
            if (isupper(data[i]))
            {
                result.data[i] = tolower(data[i]);
            }
            else
            {
                result.data[i] = toupper(data[i]);
            }
        }
        return result;
    }
    char &operator[](int i)
    {
        if (i < 0 || i >= strlen(data))
        {
        }
        return data[i];
    }
    bool operator<(const String &s) const
    {
        return strlen(data) < strlen(s.data);
    }

    bool operator==(const String &s) const
    {
        return strcmp(data, s.data) == 0;
    }

    String operator+(const String &s)
    {
        String result;
        delete[] result.data;
        result.data = new char[strlen(data) + strlen(s.data) + 1];
        strcpy(result.data, data);
        strcat(result.data, s.data);
        return result;
    }

    void display()
    {
        cout << data << endl;
    }
};
int main()
{
    String s1("Hello");
    String s2("RV");
    String s3 = s1 + s2;
    s3.display();
    String s4 = !s1;
    s4.display();
    if (s1 < s2)
    {
        cout << "s1 is shorter than s2" << endl;
    }
    else
    {
        cout << "s1 is longer than or equal to s2" << endl;
    }
    if (s1 == s2)
    {
        cout << "s1 and s2 are equal" << endl;
    }
    else
    {
        cout << "s1 and s2 are not equal" << endl;
    }
    return 0;
}
