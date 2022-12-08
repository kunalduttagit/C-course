//
//  QueueUsingStack.hpp
//  DSA
//
//  Created by Kunal Dutta on 09/12/22.
//

#ifndef QueueUsingStack_hpp
#define QueueUsingStack_hpp

#include <iostream>
using namespace std;

template <class T>
class node
{
public:
    T data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

template <class T>
class stack
{
private:
    node<T> *top;
public:
    stack(){top=NULL;}
    void push(T x);
    T pop();
    void display();
    bool isEmpty();
};

template <class T>
void stack<T>::push(T x)
{
    node<T> *temp = new node<T>(x);
    if(temp == NULL)
        cout << "Stack Overflow\n";
    else{
        temp->next = top;
        top = temp;
    }
}

template <class T>
T stack<T>:: pop(void)
{
    T delval = -1;
    if(top == NULL)
        cout << "Stack is Empty\n";
    else{
        delval = top->data;
        node<T> *toDelete = top;
        top = top->next;
        delete toDelete;
    }
    return delval;
}

template <class T>
void stack<T>::display(void)
{
    if(!top)
    {
        cout << "Stack is Empty\n";
    }
    node<T> *trav = top;
    while(trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
    cout << '\n';
}

template <class T>
bool stack<T>::isEmpty()
{
    return top == NULL;
}


#endif /* QueueUsingStack_hpp */
