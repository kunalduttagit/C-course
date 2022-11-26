//
//  DoublyCircularLinkedListC.c
//  C++ course
//
//  Created by Kunal Dutta on 07/11/22.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node{
    node *prev;
    int data;
    node *next;
}*head=NULL;

void create(int a[], int n)
{
    node *temp, *last;
    head = (node *)malloc(sizeof(node));
    head->prev = head->next = head;
    head->data = a[0];
    last = head;
    for(int i=1; i<n; i++)
    {
        temp = (node*)malloc(sizeof(node));
        temp->prev = last;
        last->next=temp;
        temp->data = a[i];
        temp->next = head;
        head->prev = temp;
        last = temp;
    }
}

void display(void)
{
    if(!head)
    {
        printf("List is Empty\n");
        return;
    }
    node *trav = head;
    do
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }while(trav != head);
    printf("\n");
    return;
}

int size(void)
{
    int count = 0;
    node *trav = head;
    do{
        count++;
        trav = trav->next;
    }while(trav != head);
    return count;
}

void insert(int index, int value)
{
    if(index < 0 || index > size())
    {
        printf("Invalid Index\n");
        return;
    }
    if(!head)
    {
        head = (node *)malloc(sizeof(node));
        head->prev = head->next = head;
        head->data = value;
        return;
    }
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    if(index == 0)
    {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
        return;
    }
    node *trav = head;
    for(int i=0; i<index-1; i++) trav = trav->next;
    temp->prev = trav;
    temp->next = trav->next;
    trav->next->prev = temp;
    trav->next = temp;
}

void delete(int index)
{
    if(index < 0 || index > size()-1)
    {
        printf("Invalid Index\n");
        return;
    }
    node *toDelete = head;;
    if(index == 0)
    {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        free(toDelete);
        return;
    }
    for(int i=0; i<index; i++) toDelete = toDelete->next;
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    free(toDelete);
    return;
}

void reverse(void)
{
    node *trav = head;
    do{
        node *temp = trav->next;
        trav->next = trav->prev;
        trav->prev = temp;
        trav = trav->prev;
    }while(trav != head);
    head = head->next;
    return;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    create(a, 5);
    insert(2,11);
    display();
    delete(2);
    display();
    reverse();
    display();
}
