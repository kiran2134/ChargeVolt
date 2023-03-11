#include <iostream>
using namespace std;

class Item
{
public:
    int id;
    char name[20];
    int price;

    void accept()
    {
        cout << "Enter item deets: ";
        cin >> id >> name >> price;
    }

    void display()
    {
        cout << id << " " << name << " " << price << " " << endl;
    }
};

class Discount : Item
{
public:
    float discount_in_per;
    void input()
    {
        cout << "Enter item deets and discount%: ";
        cin >> id >> name >> price >> discount_in_per;
    }
    void show()
    {
        // cout << "Discount %: " << discount_in_per;
        int discount_in_rs = 0;
        discount_in_rs = price * discount_in_per / 100;
        int discount_price = price - discount_in_rs;
        cout << id << " " << name << " " << price << " "
             << " " << discount_in_per << " " << discount_price << endl;
    }
};
int main()
{
    Item obj1;
    Discount obj2;
    obj1.accept();
    obj1.display();
    obj2.input();
    obj2.show();
    return 0;
}