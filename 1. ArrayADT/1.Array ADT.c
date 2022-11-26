//
//  Array ADT.c
//  C++ course
//
//  Created by Kunal Dutta on 11/09/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Initialize(struct Array *arr)
{
    printf("Enter Size of Array ");
    scanf("%d", &arr->size);
 
    arr->A = (int *)malloc(arr->size * sizeof(int));
    
    arr->length =  0;  //initialize length, bc no elements
    
    printf("Enter How many numbers ");
    int n;
    scanf("%d", &n);
    
    printf("Enter Elements\n");
    
    for(int i=0; i<n; i++)
        scanf("%d", &arr->A[i]);
    arr->length = n;
}

void Display(struct Array arr)
{
    printf("\nElements are\n");
    for(int i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append (struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++] = x;
    else printf("Array Overflow");
}

void Insert (struct Array *arr, int index, int x)
{
    //if(arr->length < arr->size)
    if(index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    if(index <= arr->length && index >= 0)
    {
        for(int i=index; i<arr->length-1; i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int LinearSearch (struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}
int TranspositionLinearSearch (struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}
int MoveToHeadLinearSearch (struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key) //best O(1) Worst O(log n) same for successful/unsuccesful
{                                           //ends at last nodes of tree 1 node 2 dead ends - unsucces
    int low, mid, high;
    low = 0; high = arr.length-1;           //exactly O(log(n+1))
    while(low <= high)
    {
        mid = (low+high)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int RecursiveBinarySearch(int a[], int low, int high, int key) //best O(1) Worst O(log n) same for successful/unsuccesful
{
    int mid;
    if(low <= high)
    {
        mid = (low+high)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RecursiveBinarySearch(a, low, mid-1, key);
        else
            return RecursiveBinarySearch(a, mid+1, high, key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if(index >= 0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int val)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = val;
    printf("After change ");
    Display(*arr);
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i=0; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int RecursiveSum(int a[], int n)
{
    if(n < 0)
        return 0;
    return RecursiveSum(a, n-1) + a[n];
}

int Sum(struct Array arr)
{
    int total=0;
    for(int i=0; i<arr.length; i++)
        total += arr.A[i];
    return total;
}

float Average(struct Array arr)
{
    return (float)Sum(arr)/arr.length ;
}


int main()
{
    struct Array arr;
    
    int opt=0;
    printf("Enter the operation you want to do");
    printf("\n1. Initialize an array");
    printf("\n2. Insert an element");
    printf("\n3. Remove an element");
    printf("\n4. Append element");
    printf("\n5. Printing the elements of array");
    printf("\n6. Searching");
    printf("\n7. Arithmetic Operations");
    printf("\n8. Exit\n");
    
    while(opt !=8)
    {
        printf("\nEnter the sequence of operation\n");
        scanf("%d", &opt);
        
        switch(opt)
        {
            case 1:
            {
                Initialize(&arr);
                break;
            }
            case 2:
            {
                printf("Insert Index and the Element ");
                int val, index;
                scanf("%d %d", &index, &val);
                Insert(&arr, index, val);
                break;
            }
            case 3:
            {
                printf("Which Index should be deleted ");
                int index;
                scanf("%d", &index);
                Delete(&arr, index);
                break;
            }
            case 4:
            {
                printf("Value to be appended ");
                int val;
                scanf("%d", &val);
                Append(&arr, val);
                break;
            }
            case 5:
            {
                Display(arr);
                break;
            }
            case 6:
            {
                printf("Choose Search Type ");
                printf("\n1. Linear Search\n2. Transposition LS\n3. Move to Head LS\n4. Binary Search\n5. Recursive Binary Search\n(Note: 2 and 3 might affect your array\n");
                int s; scanf("%d", &s);
                switch(s)
                {
                    case 1:
                    {
                        printf("Enter Key to be found ");
                        int key; scanf("%d", &key);
                        int x = LinearSearch(arr, key);
                        x != -1 ? printf("\nFound at Index %d", x) : printf("\nKey Not Found");
                        break;
                    }
                    case 2:
                    {
                        printf("Enter Key to be found ");
                        int key; scanf("%d", &key);
                        int x = TranspositionLinearSearch(&arr, key);
                        x != -1 ? printf("\nFound at Index %d", x) : printf("\nKey Not Found");
                        break;

                    }
                    case 3:
                    {
                        printf("Enter Key to be found ");
                        int key; scanf("%d", &key);
                        int x = MoveToHeadLinearSearch(&arr, key);
                        x != -1 ? printf("\nFound at Index %d", x) : printf("\nKey Not Found");
                        break;
                    }
                    case 4:
                    {
                        printf("Enter Key to be found ");
                        int key; scanf("%d", &key);
                        int x = BinarySearch(arr, key);
                        x != -1 ? printf("\nFound at Index %d", x) : printf("\nKey Not Found");
                        break;
                    }
                    case 5:
                    {
                        printf("Enter Key to be found ");
                        int key; scanf("%d", &key);
                        int x = RecursiveBinarySearch(arr.A, 0,arr.length, key);
                        x != -1 ? printf("\nFound at Index %d", x) : printf("\nKey Not Found");
                        break;
                    }
                    
                    default: break;
                        
                }
                break;
            case 7:
                {
                    printf("\n1. Get Element by Index\n2. Change value at some Index\n3. Find Maximum\n4. Find Minimum\n5. Find Sum of all Elements\n6. Find Average of all Elements\n7. Recursive Sum\n");
                    int ao; scanf("%d", &ao);
                    switch(ao)
                    {
                        case 1:
                        {
                            printf("\nEnter Index for the element ");
                            int x; scanf("%d", &x);
                            x != -1 ? printf("The Element at %d is %d", x, Get(arr, x)) : printf("Element Not Found!");
                            break;
                        }
                        case 2:
                        {
                            printf("\nEnter Index and the new value ");
                            int index, val; scanf("%d %d", &index, &val);
                            Set(&arr, index, val);
                            break;
                        }
                        case 3:
                        {
                            printf("\nMaximum is %d", Max(arr));
                            break;
                        }
                        case 4:
                        {
                            printf("\nMinimum is %d", Min(arr));
                            break;
                        }
                        case 5:
                        {
                            printf("\nSum is %d", Sum(arr));
                            break;
                        }
                        case 6:
                        {
                            printf("\nAverage is %f", Average(arr));
                            break;
                        }
                        case 7:
                        {
                            printf("\nSum using Reccursion is %d", RecursiveSum(arr.A, arr.length));
                            break;
                        }
                        default: break;
                            
                    }
                }
            }
            default:
                break;
        }
    }
    
    
    return 0;
}
//checking if cloned project can be pushed using git
