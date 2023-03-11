#include <iostream>
using namespace std;
class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    friend istream &operator>>(istream &input, Time &t)
    {
        input >> t.hours >> t.minutes >> t.seconds;
        return input;
    }
    friend ostream &operator<<(ostream &output, const Time &t)
    {
        output << t.hours << " hours " << t.minutes << " minutes " << t.seconds << " seconds";
        return output;
    }
    void displayTotalSeconds() const
    {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        cout << "Total seconds: " << totalSeconds << endl;
    }
};
int main()
{
    Time t;
    cout << "Enter the time in hours, minutes, and seconds: ";
    cin >> t;
    cout << "The time you entered is: " << t << endl;
    t.displayTotalSeconds();
    return 0;
}
