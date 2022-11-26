//
//  CircularLInkedLIstC.c
//  C++ course
//
//  Created by Kunal Dutta on 28/10/22.
//

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void create (int A[], int n)
{
    struct node *temp, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;
    
    for(int i=1; i<n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = A[i];
        temp->next = head; // or temp->next = last->next
        last->next = temp;
        last = temp;
    }
}

//last-next always point on head only, it carries with it the next pointer of head, as at beg, headnext was at head and head is equal to last, so it makes last->next as head, whcih it passes to all and then changes itself. DIY to check

void display(struct node *trav)
{
    if(!head)
    {
        printf("List is Empty ");
        return;
    }
    do
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }while(trav != head);
}

int size(struct node *trav)
{
    if (!head)
        return 0;
    int count = 0;
    do {
        count++;
        trav =  trav->next;
    }while(trav != head);
    return count;
}

void reccursiveDisplay(struct node *trav)
{
    static int flag = 0;
    if(trav != head || flag == 0)
    {
        printf("%d ", trav->data);
        flag = 1;
        reccursiveDisplay(trav->next);
    }
    flag = 0;
}

void insert(int val, int index)
{
    struct node *trav = head;
    if(index < 0 || index > size(trav))
    {
        printf("Invalid Index ");
        free(trav); return;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node*));
    temp->data = val;
    if(index == 0)
    {
        if(head == NULL)
        {
            head = temp;
            head->next = head;
            return;
        }
        while(trav->next != head)
            trav = trav->next;
        temp->next = head;  //trav->next should be head
        trav->next = temp;
        head = temp;
        return;
    }
    for(int i=0; i<index-1; i++)
        trav = trav->next;
    temp->next = trav->next;
    trav->next = temp;
    return;
}

void delete(int pos)
{
    if(pos < 1 || pos > size(head))
    {
        printf("Invalid Index ");
        return;
    }
    struct node *trav = head;
    if(pos == 1)
    {
        while(trav->next != head)
            trav = trav->next;
        
        if(head == trav)
        {
            free(head);
            head = NULL;
            return;
        }
        trav->next = head->next;
        free(head);
        head = trav->next;
        return;
    }
    for(int i=0; i<pos-2; i++)
        trav = trav->next;  //trav act as tail pointer to the one step forward pointer toDelete
    struct node *toDelete = trav->next;
    trav->next = toDelete->next;
    free(toDelete);
    return;
}

int main()
{
    int A[] = {1, 2, 3, 4};
    create(A, 4);
    insert(11, 1);  //insert at index (starts from 0)
    delete(2);      //delete at certain position (starts from 1)
    display(head);
}
