//
//  CircularQueueArrayC.c
//  DSA
//
//  Created by Kunal Dutta on 07/12/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueue circularQueue;

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(circularQueue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q =(int *)malloc(q->size * sizeof(int));
}

void enqueue(circularQueue *q, int value)
{
    if((q->rear + 1) % q->size == q->front){
        printf("Queue is Full\n");
        return;
    }
    q->rear = (q->rear + 1)%q->size;
    q->Q[q->rear] = value;
}

int dequeue(circularQueue *q)
{
    int deleted = -1;
    if(q->rear == q->front)
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1)%q->size;
        deleted = q->Q[q->front];
    }
    return deleted;
}

void display(circularQueue q)
{
    if(q.rear == q.front){
        printf("Queue is Empty\n");
        return;
    }
    int i = (q.front + 1) % q.size;
    do{
        printf("%d ", q.Q[i]);
        i = (i+1) % q.size;
    }while(i != (q.rear + 1) % q.size);
}

int main(void)
{
    circularQueue q;
    create(&q, 5);
    
    enqueue(&q, 2);
    enqueue(&q, 7);
    enqueue(&q, 11);
    enqueue(&q, 14);
    
    dequeue(&q); //del 2
    
    enqueue(&q, 13);
    
    dequeue(&q); //del 7
    
    display(q);

}
