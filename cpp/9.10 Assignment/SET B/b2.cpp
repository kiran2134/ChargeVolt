#include <iostream>
using namespace std;
#define MAX_SIZE 10
class Stack
{
    int top;
    int arr[MAX_SIZE];

public:
    Stack()
    {
        top = -1;
    }
    void push(int num)
    {
        if (top == MAX_SIZE - 1)
        {
            throw "Stack Overflow Exception!";
        }
        arr[++top] = num;
    }
    int pop()
    {
        if (top == -1)
        {
            throw "Stack Underflow Exception!";
        }
        return arr[top--];
    }
};
int main()
{
    Stack myStack;
    int num;
    try
    {
        // Pushing 11 elements to the stack
        for (int i = 1; i <= 11; i++)
        {
            myStack.push(i);
            cout << "Pushed " << i << " to the stack" << endl;
        }
    }
    catch (const char *msg)
    {
        cerr << "Exception Caught: " << msg << endl;
    }
    try
    {
        // Popping 12 elements from the stack
        for (int i = 1; i <= 12; i++)
        {
            num = myStack.pop();
            cout << "Popped " << num << " from the stack" << endl;
        }
    }
    catch (const char *msg)
    {
        cerr << "Exception Caught: " << msg << endl;
    }
    return 0;
}
