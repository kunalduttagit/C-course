//
//  QueueArrayCPP.cpp
//  DSA
//
//  Created by Kunal Dutta on 07/12/22.
//

#include <iostream>
using namespace std;

class queue
{
    int size;
    int front;
    int rear;
    int *Q;
public:
    queue() {front = rear = -1; size=10; Q=new int[size];}
    queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[size];
    }
    void enqueue(int);
    int dequeue();
    void display();
};

void queue::enqueue(int value)
{
    if(rear == size-1){
        cout << "Queue is Full\n";
        return;
    }
    rear++;
    Q[rear] = value;
}

int queue::dequeue()
{
    int deleted = -1;
    if(front == rear)
        cout << "Queue is Empty\n";
    else {
        front++;
        deleted = Q[front];
    }
    return deleted;
}

void queue::display()
{
    if(front == rear){
        cout << "Queue is Empty\n";
        return;
    }
    for(int i = front+1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << '\n';
}

int main(void)
{
    queue q(5);
    q.enqueue(2);
    q.enqueue(7);
    q.enqueue(13);
    cout << "Deleted " << q.dequeue() << endl;
    q.display();
}
