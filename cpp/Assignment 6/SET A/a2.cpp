#include <iostream>
using namespace std;
class Employee
{
private:
    float salary;

public:
    Employee(float s = 0)
    {
        salary = s;
    }
    Employee operator--()
    {
        ++salary;
        return *this;
    }
    Employee operator--(int)
    {
        Employee temp(*this);
        --salary;
        return temp;
    }
    float getSalary() const
    {
        return salary;
    }
};
int main()
{
    Employee emp(5000.0);
    cout << "Salary: " << emp.getSalary() << endl;
    emp--; // post-decrement
    cout << "Salary after decrement: " << emp.getSalary() << endl;
    --emp; // pre-decrement
    cout << "Salary after decrement: " << emp.getSalary() << endl;
    return 0;
}
