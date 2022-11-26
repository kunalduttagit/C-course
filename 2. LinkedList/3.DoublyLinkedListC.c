//
//  DoublyLinkedListC.c
//  C++ course
//
//  Created by Kunal Dutta on 29/10/22.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first;

void create(int A[], int n)
{
    struct node *temp, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for(int i=1; i<n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        last->next = temp;
        temp->next = NULL;
        temp->prev = last;
        last = temp;
    }
}

void display(struct node *trav)
{
    if(!first)
    {
        printf("List is Empty");
        return;
    }
    while(trav)
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}

int length(struct node *trav)
{
    if(!first) return 0;  //not needed, still of asthetics
    int count = 0;
    while(trav)
    {
        trav = trav->next;
        count++;
    }
    return count;
}

void insert(int index, int val)
{
    if(index < 0 || index > length(first))
    {
        printf("Invalid Index\n");
        return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    if(!first)      //not needed, still for asthetics, see line 79, condition almost stisfy every case in line 73
    {
        temp->next = temp->prev = NULL;     //line 81 first is NULL, line 82 same
        first = temp;
        return;
    }
    if(index == 0)
    {
        temp->next = first;
        temp->prev = NULL;
        first->prev = temp;
        first = temp;
        return;
    }
    struct node *trav = first;
    for(int i=0; i<index-1; i++)
        trav = trav->next;
    temp->next = trav->next;
    temp->prev = trav;
    if(trav->next)
        trav->next->prev = temp;
    trav->next = temp;
    return;
}

void delete(int pos)
{
    if(!first || pos > length(first) || pos < 1)
    {
        printf("No elements to delete/ Invalid Index\n");
        return;
    }
    struct node *toDelete = first;
    if(pos == 1)
    {
        first = first->next;
        if(first)
            first->prev = NULL;
        free(toDelete);
        toDelete = NULL;
    }
    else
    {
        for(int i=0; i<pos-1; i++)
            toDelete = toDelete->next;
        toDelete->prev->next = toDelete->next;
        if(toDelete->next)
            toDelete->next->prev = toDelete->prev;
        free(toDelete);
        toDelete = NULL;
    }
    return;
}

int Max(struct node *p)
{
    int m = INT32_MIN;
    while(p)
    {
        if(p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

void reverse(struct node *p)
{
    struct node *temp;
    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && !p->next)
            first = p;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    //delete(1);
    reverse(first);
    display(first);
    printf("\n%d ", Max(first));
}
