//
//  DynamicAllocation.cpp
//  C++ course
//
//  Created by Kunal Dutta on 13/01/22.
//

#include <iostream>
using namespace std;
int main()
{
    /*
     taking size first time. Can also be replicated in the sence that we can create in code logic to get size or build it
    */
    
    int size;
    cin>>size;
    
    /*
     initializing a pointer of type int and then dynamically creating an array in heap.
     the pointer as created in main funtion is stored in static memory in stack.
     new is keyword to the the same and then int type of array is created of any size.
     the array can normally be used in the name of pointer, here 'arr'.
    */
    int *arr = new int[size];
    
    //say array of size>3 so we will try to manipulate index 2 of array
    
    arr[2]=4;
    
    for(int i=0; i<size; i++) //ranged based loops can't be used for pointer array, like for each loop
    {
        //other elements should be zero except for index 2
        cout<<i[arr]<<" ";
    }
    cout<<'\n';
    
    /*
     Now, if the size of the same array has to be changed, there exits no syntax for doing that mid code
     so now if we deallocate the pointer after using it, we can reallocate a new memory for the same array and the old one gets deleted
     */
    
    delete []arr;
    //if we don't delete, it can cause memory leak
    
    //say we don't take user input and specify a random size ourselfs
    
    arr = new int[10];
    
    arr[6]=4;
    arr[7]=5;
    arr[8]=arr[6]+arr[7];
    
    for(int i=2; i<10; i++){
        cout<<i[arr]<<" ";
    }
    
    cout<<'\n';
    
    delete [] arr;
    
    //nullptr (earlier used NULL) will make pointer point nowhere
    //never nullify a pointer before deleting it or the allocated memory of heap will stay there with no one to point to it, it can't be accessed again.
    arr = nullptr;
    
    return 0;
}

/*
 It helps to use the same array with differnt size.
 VECTORS are better to use for dynamically allocating an array as it's easy to understand
 VECTORS automatically manage deallocation of memory as soon as it is out of scope just like any other variable in stack
 
 README : I don't know why but if I take inital size of array in odd numbers, the next array even after deleting the first one has weird values of other elements except for the one already declared/initiallized
 After debuging, it was found that it takes value 0xhexadecimal adress and prints weird values.
 Again after debugging, it was fount that any number, odd or even reproduces same problem and might run correctly the next time. 
 */
