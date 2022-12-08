//
//  QueueArrayC.c
//  DSA
//
//  Created by Kunal Dutta on 07/12/22.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct queue queue;

struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(queue *q, int value)   //O(1)
{
    if(q->rear == q->size-1)    //queue is Full
    {
        printf("Queue is Full\n");
        return;
    }
    q->rear++;
    q->Q[q->rear] = value;
    return;
}

int dequeue(queue *q)               //O(1)
{
    int x = -1;
    if(q->front == q->rear)         //queue is empty
        printf("Queue is Empty");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(queue q)
{
    if(q.front == q.rear){
        printf("Queue is Empty\n");
        return;
    }
    for(int i = q.front+1; i <= q.rear; i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}

int main(void)
{
    queue q;
    create(&q, 5);
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 11);
    dequeue(&q);
    enqueue(&q, 23);
    printf("Deleted %d\n", dequeue(&q));
    display(q);
}
