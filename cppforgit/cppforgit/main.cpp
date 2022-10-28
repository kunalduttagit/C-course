//
//  main.cpp
//  cppforgit
//
//  Created by Kunal Dutta on 08/10/22.
//
/*
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
 */

//
//  Andmore.cpp
//  C++ course
//
//  Created by Kunal Dutta on 08/10/22.
//

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Array
{
public:
    int *A;
    int size;
    int length;
    friend void Initialize(Array *);
    friend void Display(Array);
};

void Initialize(Array *arr)
{
    cout << "Enter array size and length ";
    cin >> arr->size >> arr->length;
    arr->A = new int[arr->size];
    cout << "Enter nos. ";
    for(int i=0; i<arr->length; i++)
        cin >> arr->A[i];
}

void Display(Array arr)
{
    cout << "\nElement Are: \n";
    for(int i=0; i<arr.length; i++)
        cout << arr.A[i] << " ";
}

void Reverse(Array *arr)
{
    for(int i=0, j=arr->length-1; i<arr->length/2; i++, j--)
    {
        swap(arr->A[i], arr->A[j]);
    }
}

int main()
{
    Array arr;
    Initialize(&arr);
    Display(arr);
    Reverse(&arr);
    Display(arr);
    return 0;
}

