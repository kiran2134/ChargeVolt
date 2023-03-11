#include <iostream>
using namespace std;

class Simple_interest
{
public:
    float si, amount, r;

    void calculate(float amt, float rate)
    {
        amount = amt;
        r = rate;
    }

    void calculate(float time)
    {
        si = (amount * r * time) / 100;

        cout << "Simple interest is:" << si;
    }
};

int main()
{
    float amt, rate, time;
    cout << "Enter amount:";
    cin >> amt;
    cout << "Enter rate:";
    cin >> rate;
    cout << "Enter time:";
    cin >> time;
    Simple_interest obj;
    obj.calculate(amt, rate);
    obj.calculate(time);
    return 0;
}