//
//  stack.h
//  C++ course
//
//  Created by Kunal Dutta on 26/11/22.
//

#ifndef stack_h
#define stack_h
#include <stdlib.h>

typedef struct node node;
struct node {
    char data;
    node *next;
}*top = NULL;

void push(char x)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    if(temp == NULL)
        printf("Stack Overflow\n");
    else {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

char pop(void)
{
    char x = -1;
    if(!top)
        printf("Stack is Empty\n");
    else {
        node *toDelete = top;
        top = top->next;
        x = toDelete->data;
        free(toDelete);
    }
    return x;
}

void display(void)
{
    node *trav = top;
    while(trav)
    {
        printf("%c ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

char stackTop(void)
{
    return (top==NULL ? -1 : top->data);
}

#endif /* stack_h */
