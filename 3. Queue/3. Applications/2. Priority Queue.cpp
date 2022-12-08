//
//  PriorityQueue.cpp
//  DSA
//
//  Created by Kunal Dutta on 09/12/22.
//

#include "queue.hpp"

void priority(queue<char> q[], int value, int priority)
{
    q[priority-1].enqueue(value);
}

void dequeueall(queue<char> q[], int priorities)
{
    for(int i=0; i<priorities; i++)
    {
        while(!q[i].isEmpty())
            cout << q[i].dequeue() << " ";
        cout << endl;
    }
}

int main(void)
{
    int priorities;
    priorities = 3;
    queue<char>* q = new queue<char>[priorities];
    priority(q ,'a', 1);
    priority(q ,'b', 1);
    priority(q ,'c', 2);
    priority(q ,'d', 3);
    priority(q ,'e', 2);
    priority(q ,'f', 1);
    priority(q ,'g', 2);
    priority(q ,'h', 3);
    priority(q ,'i', 2);
    priority(q ,'j', 2);
    dequeueall(q, priorities);
}
