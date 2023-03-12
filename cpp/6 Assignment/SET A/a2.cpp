#include <iostream>
using namespace std;
class Employee
{
private:
    float salary;

public:
    void accept(){
        cout<<"Enter the employee Salary:\n";
        cin>>salary;
    }
    void operator --(){
        ++salary;
    }
    void operator --(int){
        --salary;
    }
    void display(){
        cout<<salary;
    }
};
int main(){
    Employee e;
    e.accept();
    e--;
    cout<<"Pre Increment is \n";
    e.display();
    --e;
    cout<<"\n Post Increment is \n";
    e.display();
    return 0;
}