//
//  LinkedListC.c
//  C++ course
//
//  Created by Kunal Dutta on 16/10/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first, *second, *third, *last;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

void ReccursiveDisplay(struct Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        ReccursiveDisplay(p->next);
    }
}

void ReverseDisplay(struct Node *p)
{
    if(p)
    {
        ReverseDisplay(p->next);
        printf("%d ", p->data);
    }
}

int Count(struct Node *p)
{
    int c = 0;
    while(p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int ReccursiveCount(struct Node *p)
{
    if(p)
    {
        return ReccursiveCount(p->next) + 1;
    }
    return 0;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int ReccursiveSum(struct Node *p)
{
    if(p == 0)
        return 0;
    return ReccursiveSum(p->next) + p->data;
}

int Max(struct Node *p)
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

int ReccursiveMax(struct Node *p)
{
    int x = 0;
    if(!p)
        return INT32_MIN;
    x = ReccursiveMax(p->next);
    return x > p->data ? x : p->data;
}

int Min(struct Node *p)
{
    int m = INT32_MAX;
    while(p)
    {
        if(p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

struct Node * LinearSearch(struct Node *p, int key)
{
    while(p)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node * ReccursiveLinearSearch(struct Node *p, int key)
{
    if(!p)
        return NULL;
    if(key == p->data)
        return p;
    return ReccursiveLinearSearch(p->next, key);
}

struct Node * MoveToHeadLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(struct Node *p, int index, int x)
{
    if(index < 0 || index > Count(p))
        return;
    
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    if(index == 0)
    {
        t->next = first;
        first = t;
        return;
    }
    p = first;
    for(int i=0; i<index-1; i++)
        p = p->next;
    t->next = p->next;
    p->next = t;
}

void pushback(struct Node *p, int x)
{
    //struct Node *last;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(!first)
    {
       first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void pushback2(struct Node *p, int x)
{
    //struct Node *last;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(!second) {
       second = last = t;
    }
    else {
        last->next = t;
        last = t;
    }
}

void insertSorted(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(!first)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if(p == first)  //i.e. smallest element
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if(index < 0 || index > Count(p))
    {
        printf("\nUnderflow or Not a valid Index\n");
        return x;
    }
    if(index == 0)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        q = NULL;
        return x;
    }
    for(int i=0; i<index && p; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    p = NULL;
    return x;
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p)
    {
        if(p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void removeDublicate(struct Node *p)    //O(n)
{
    struct Node *q = p->next;
    while(q)
    {
        if(p->data != q->data) {
            p = q;
            q = q->next;
        }
        else {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
    return;
}

void reverseUsingArray(struct Node *p)
{
    int *A, i=0;
    struct Node *q = p;
    A = (int *)malloc(sizeof(int)*(Count(first)));
    while(q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;  //again point to first node
    i--;  // the last i++ took it outside scope of array size
    while(q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse(struct Node *p)
{
    struct Node *r, *q;
    r = q = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reccursiveReverse(struct Node *q, struct Node *p)
{
    if(p)
    {
        reccursiveReverse(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void concante(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct Node *p, struct Node *q)
{
    //for the head part
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    //for nodes in between, not running out of either linked list
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    //for remaining elements in any linked list
    if(p) last->next = p;
    if(q) last->next = q;
    
}

int isLooping(struct Node *head)    //floyd's algorithm
{
    struct Node *p, *q;  //p is slow, q is fast
    p = q = head;
    do
    {
        p = p->next;    //p only one step
        q = q->next;    //q one step and one conditional step
        q = (q)? q->next : q;  // check if q is already NULL q = elif condt
    }while(p && q && p!=q);
    
    return p==q ? 1 : 0;
}

int main()
{
    //int A[] = {3, 5, 1, 25, 15};
    //create(A, 5);
    pushback(first, 5);
    pushback(first, 8);
    pushback(first, 10);
    pushback(first, 11);
    pushback(first, 15);
    
    pushback2(second, 5);
    pushback2(second, 8);
    pushback2(second, 14);
    pushback2(second, 20);
    pushback2(second, 23);
    
    struct Node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    printf("%d and %d  ", isLooping(first), isLooping(second));
    
    /*
    struct Node *temp;
    temp = MoveToHeadLinearSearch(first, 25);
    temp ? printf("Key Found at %x ", temp) : printf("Key Not Found ");
    Insert(first, Count(first), 12);
    Display(first);
    printf("Deleted element is %d\n",Delete(first, -2));
     */
}
