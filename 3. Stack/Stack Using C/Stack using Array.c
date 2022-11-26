//
//  Stack using Array.c
//  C++ course
//
//  Created by Kunal Dutta on 09/11/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(stack *s)
{
    printf("Enter size ");
    scanf("%d", &s->size);
    s->top = -1;
    s->s = (int *)malloc(s->size*sizeof(int));
}

void display(stack s)
{
    if(s.top == -1)
    {
        printf("Stack is Empty");
        return;
    }
    for(int i=s.top; i>=0; i--)
        printf("%d ", s.s[i]);
    printf("\n");
}

void push(stack *s, int x)
{
    if(s->top == s->size - 1)
    {
        printf("Stack Overflow");
        return;
    }
    s->top++;
    s->s[s->top] = x;
}

int pop(stack *s)
{
    int x = -1;
    if(s->top == -1)
        printf("Stack Underflow");
    else
        x = s->s[s->top--];
    return x;
}

int peek(stack s, int pos)
{
    int x=-1;
    if(s.top - pos + 1 < 0)
        printf("Invalid Index");
    else
        x = s.s[s.top-pos+1];
    return x;
}

int isEmpty(stack s)
{
    if(s.top == -1)
        return 1;
    return 0;
}

int isFull(stack s)
{
    return s.top == s.size-1;
}

int stackTop(stack s)
{
    if(!isEmpty(s))
        return s.top;
    return -1;
}

int main()
{
    stack sa;
    create(&sa);
    push(&sa, 1);
    push(&sa, 2);
    push(&sa, 3);
    push(&sa, 4);
    //printf("%d\n",peek(sa, 5));
    pop(&sa);
    display(sa);
}
