//
//  DEQueue.hpp
//  DSA
//
//  Created by Kunal Dutta on 09/12/22.
//

#ifndef DEQueue_hpp
#define DEQueue_hpp

#include <iostream>
using namespace std;

template <class T>
class queue
{
    int size;
    int front;
    int rear;
    T *Q;
public:
    queue() {front = rear = -1; size=10; Q=new T[size];}
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new T[size];
    }
    void enqueue(T);
    T dequeue();
    void display();
    bool isEmpty();
    bool isFull();
    
    void enqueueFront(T);
    void enqueueRear(T);
    T dequeueFront();
    T dequeueRear();
};

template <class T>
void queue<T>::enqueue(T value)
{
    if(rear == size-1){
        cout << "Queue is Full\n";
        return;
    }
    rear++;
    Q[rear] = value;
}

template <class T>
T queue<T>::dequeue()
{
    T deleted = -1;
    if(front == rear)
        cout << "Queue is Empty\n";
    else {
        front++;
        deleted = Q[front];
    }
    return deleted;
}

template <class T>
void queue<T>::display()
{
    if(front == rear){
        cout << "Queue is Empty\n";
        return;
    }
    for(int i = front+1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << '\n';
}

template <class T>
bool queue<T>::isEmpty()
{
    return front == rear;
}

template <class T>
bool queue<T>::isFull()
{
    return rear == size-1;
}

#endif /* DEQueue_hpp */
