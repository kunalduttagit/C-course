//
//  QueueUsingStack.cpp
//  DSA
//
//  Created by Kunal Dutta on 09/12/22.
//

#include "stack.hpp"

void enqueue(stack<int> *s, int value)
{
    s->push(value);
}

int dequeue(stack<int> *s1, stack<int> *s2)
{
    int deleted = -1;
    if(s2->isEmpty()){
        if(s1->isEmpty()){
            cout << "Queue is Empty\n";
            return deleted;
        }
        while(!s1->isEmpty())
            s2->push(s1->pop());
    }
    return s2->pop();
}

int main()
{
    stack<int> s1, s2;
    enqueue(&s1, 5);
    enqueue(&s1, 7);
    cout << "Deleted: " << dequeue(&s1, &s2) << endl; //FIFO, 5 first, deleted first
}
