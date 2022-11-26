//
//  Stack using LL.c
//  C++ course
//
//  Created by Kunal Dutta on 09/11/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
}*top = NULL;    //one global pointer, iff one stack is to be created

void push(int x)
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

int pop(void)
{
    int x=-1;
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
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

int main()
{
    push(2); push(4); push(1); push(10);
    pop();
    display();
}
