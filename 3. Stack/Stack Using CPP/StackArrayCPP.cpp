//
//  StackArrayCPP.cpp
//  C++ course
//
//  Created by Kunal Dutta on 16/11/22.
//

#include <iostream>
using namespace std;

const unsigned int MAX = 10e2+7;

class stack
{
private:
    int arr[MAX];
    int top = -1;
public:
    stack(void) { top=-1; }
    void push(int);
    int pop(void);
    void display(void);
    int stackTop(void);
    bool isEmpty(void);
    bool isFull(void);
};

void stack:: push(int x)
{
    if(top == MAX-1){
        cout << "Stack OverFlow\n";
        return;
    }
    arr[++top] = x;
}

int stack:: pop(void)
{
    if(top == -1){
        cout << "Stack is Empty\n";
        return -1;
    }
    int delval = arr[top];
    top--;
    return delval;
}

void stack:: display(void)
{
    if(top == -1){
        cout << "Stack is Empty\n";
        return;
    }
    for(int i=top; i>=0; i--)
        cout << arr[i] << " ";
    cout << '\n';
}

int stack::stackTop(void)
{
    if(top == -1)
        return -1;
    return arr[top];
}

bool stack:: isEmpty(void)
{
    return top==-1;
}

bool stack:: isFull(void)
{
    return top == MAX-1;
}

int main()
{
    stack s;
    s.push(4);
    s.push(7);
    s.push(2);
    s.push(12);
    s.push(1);
    cout << s.pop() << endl;
    cout << s.stackTop() << endl;
    cout << (s.isEmpty() ?  "True\n" : "False\n");
    s.display();
}
