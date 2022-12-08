//
//  CircularQueueArrayCPP.cpp
//  DSA
//
//  Created by Kunal Dutta on 07/12/22.
//

#include <iostream>
using namespace std;

template <class T>
class circularQueue
{
    int size;
    int front;
    int rear;
    T *Q;
public:
    circularQueue(){ front = rear = 0; size = 10; Q = new T[size];}
    circularQueue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new T[size];
    }
    void enqueue(T);
    T dequeue();
    void display();
};

template <class T>
void circularQueue<T>::enqueue(T value)
{
    if((rear + 1) % size == front)
        cout << "Queue is Full\n";
    else {
        rear = (rear + 1) % size;
        Q[rear] = value;
    }
}

template <class T>
T circularQueue<T>::dequeue()
{
    T deleted = -1;
    if(front == rear)
        cout << "Queue is Empty\n";
    else {
        front = (front + 1) % size;
        deleted = Q[front];
    }
    return deleted;
}

template <class T>
void circularQueue<T>::display()
{
    if(front == rear)
        cout << "Queue is Empty\n";
    else {
        int i = (front + 1) % size;
        do{
            cout << Q[i] << " ";
            i = (i + 1) % size;
        }while(i != (rear + 1) % size);
        cout << '\n';
    }
}

int main(void)
{
    circularQueue<char> q(5);
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('v');
    q.enqueue('d');
    q.enqueue('y'); //q full max elements size-1 = 4
    q.dequeue(); //del a
    q.enqueue('k');
    q.display();
}
