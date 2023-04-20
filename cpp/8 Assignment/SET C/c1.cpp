#include<iostream>
using namespace std;
class List{
    public:
    virtual void store()=0;
    virtual void retrieve()=0;
};
class Stack:virtual public List{
    int n;
    public:
    void store()
    {
         cout<<"Enter the values in a stack: ";
         cin>>n;
    }
    void retrieve()
    {
         cout<<"Retrieve data from stack is: "<<n<<endl;
    }
};
class Queue:virtual public List{
    int n;
    public:
    void store()
    {
        cout<<"Enter the values in a queue is: ";
        cin>>n;
    } 
    void retrieve()
    {
        cout<<"Retrieve data from queue: "<<n; 
    }
};
int main()
{
     List *l;
     Stack s;
     Queue q;

     l=&s;
     l->store();
     l->retrieve();

     l=&q;
     l->store();
     l->retrieve();
     return 0;
}