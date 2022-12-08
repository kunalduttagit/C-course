//
//  QueueLLC.c
//  DSA
//
//  Created by Kunal Dutta on 08/12/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct queue queue;
typedef struct node node;

struct node
{
    int data;
    node *next;
}*front = NULL, *rear = NULL;

void enqueue(int value)
{
    node *t;
    t = (node *)malloc(sizeof(node));
    if(t == NULL)
        printf("Queue is Full\n");
    else {
        t->data = value;
        t->next = NULL;
        if(front == NULL)   //means first node OR queue empty condn
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(void)
{
    int deleted = -1;
    if(front == NULL)
        printf("Queue is Empty\n");
    else {
        node *toDelete = front;
        front = front->next;
        deleted = toDelete->data;
        free(toDelete);
    }
    return deleted;
}

void display(void)
{
    if(front == NULL)
        printf("Queue is Empty\n");
    else {
        node *trav = front;
        while(trav)
        {
            printf("%d ", trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

int main()
{
    enqueue(7);
    enqueue(9);
    dequeue();
    printf("Deleted %d\n",dequeue());
    enqueue(8);
    display();
    
}
