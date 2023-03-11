#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Queue
{
private:
    T *queueArray;
    int queueSize;
    int front;
    int rear;
    int numItems;

public:
    Queue(int size)
    {
        queueArray = new T[size];
        queueSize = size;
        front = -1;
        rear = -1;
        numItems = 0;
    }

    ~Queue()
    {
        delete[] queueArray;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            rear++;
            queueArray[rear] = value;
            numItems++;
            if (front == -1)
            {
                front = 0;
            }
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Dequeued element: " << queueArray[front] << endl;
            front++;
            numItems--;
            if (numItems == 0)
            {
                front = -1;
                rear = -1;
            }
        }
    }

    bool isFull() const
    {
        return (numItems == queueSize);
    }

    bool isEmpty() const
    {
        return (numItems == 0);
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++)
            {
                cout << queueArray[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue<int> intQueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);
    intQueue.enqueue(50);
    intQueue.display();
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.dequeue();
    intQueue.display();
    return 0;
}
