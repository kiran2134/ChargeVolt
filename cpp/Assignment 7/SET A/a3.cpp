#include <iostream>
#include <string.h>
using namespace std;
class flight
{
    int flight_no;
    char flight_name[20];

public:
    void get()
    {
        cout << "\nenter the number and name : ";
        cin >> flight_no >> flight_name;
    }
    void put()
    {
        cout << endl
             << flight_no << flight_name;
    }
};
class route : public flight
{
    char source[10], dest[10];

public:
    void get()
    {
        flight::get();
        cout << "\nenter source and destination :";
        cin >> source >> dest;
    }
    void put()
    {
        flight::put();
        cout << source << dest;
    }
};
class reservation : public route
{
    int number_of_seats, fare;
    char cls[7];
    char travel_date[10];

public:
    void get()
    {
        route::get();
        cout << "\nenter the number _of_seats,fare,class,travel_date" << endl;
        cin >> number_of_seats >> fare >> cls >> travel_date;
    }
    void put()
    {
        route::put();
        cout << endl
             << number_of_seats << fare << cls << travel_date;
    }
    friend void display(reservation R[], int n);
};
void display(reservation R[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nclass is" << R[i].cls;
        if (strcmp(R[i].cls, "business") == 0)
            R[i].put();
    }
}
int main()
{
    reservation R[3];
    for (int i = 0; i < 2; i++)
        R[i].get();
    for (int i = 0; i < 2; i++)
        R[i].put();
    display(R, 2);
    return 0;
}
