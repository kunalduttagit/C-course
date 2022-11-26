//
//  StackCPP.cpp
//  C++ course
//
//  Created by Kunal Dutta on 16/11/22.
//

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

class stack
{
private:
    node *top;
public:
    stack(){top=NULL;}
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    node *temp = new node(x);
    if(temp == NULL)
        cout << "Stack Overflow\n";
    else{
        temp->next = top;  
        top = temp;
    }
}

int stack:: pop(void)
{
    int delval = -1;
    if(top == NULL)
        cout << "Stack is Empty\n";
    else{
        delval = top->data;
        node *toDelete = top;
        top = top->next;
        delete toDelete;
    }
    return delval;
}

void stack::display(void)
{
    if(!top)
    {
        cout << "Stack is Empty\n";
    }
    node *trav = top;
    while(trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
    cout << '\n';
}

int main()
{
    stack s;
    s.display();
    s.push(4);
    s.push(7);
    s.push(2);
    cout << s.pop() << endl;
    s.display();
}
