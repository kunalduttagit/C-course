//
//  DEQueue.cpp
//  DSA
//
//  Created by Kunal Dutta on 09/12/22.
//

#include "queue.hpp"

void queue::enqueueFront(int value)
{
    if(front > -1)
        Q[front--] =  value;
    else
        cout << "Unable to enqueue " << value << " from front\n";
}
void queue::enqueueRear(int value)
{
    if(rear < size-1)
        enqueue(value);
    else
        cout << "Unable to enqueue " << value << " from rear\n";
}

int queue::dequeueFront()
{
    int deleted = -1;
    if(! isEmpty())
        deleted = dequeue();
    else
        cout << "Unable to dequeue from front\n";
    return deleted;
}

int queue::dequeueRear()
{
    int deleted = -1;
    if(rear < size-1)
        deleted = Q[rear--];
    else
        cout << "Unable to dequeue from rear\n";
    return deleted;
}

int main()
{
    queue q(5);
    q.enqueueRear(2);
    q.enqueueRear(5);
    q.enqueueRear(7);
    q.dequeueRear(); //del 7
    q.enqueueRear(12);
    q.enqueueRear(11);
    q.dequeueFront(); // 2, one space empty
    q.enqueueFront(15);
    q.display();
}
