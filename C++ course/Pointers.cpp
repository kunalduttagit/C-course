#include <iostream>
using namespace std;
int main()
{
    //a normal interger a
    int a=10;
    // prints value of a
    cout<<a<<endl;
    
    //& or ampersand references the address of interger a
    // &a prints the address without declaring a pointer (independent of pointer)
    cout<<&a<<endl;
    
    //initializing a pointer named ptr
    int* ptr;
    
    //storing the address of integer a so that ptr points towards a
    ptr = &a;
    
    /*
     the above code can also be written as
      ----------------
     | int* ptr = &a; |
      ----------------
     
     &->reference
     *->dereference
     
     */
    
    //should print address of 'a' which is referenced to prt
    cout<<ptr<<endl;
    
    //should print value of 'a' which is deferenced to ptr
    cout<<*ptr<<endl;
    
    //should print address of ptr which is Different from address of 'a' which is referenced to ptr
    cout<<&ptr<<endl;
    
    //modifying integer 'a' with help of pointer (inderectly)
    * ptr = 20;
    
    //checking if the value is updated in both pointer pointing variable and variable itself
    cout<<*ptr<<endl;
    cout<<a<<endl;
    
    return 0;
}

/*
 Conclusion :-
 a = *ptr (values)
 &a = ptr (address)
 
 Q: Why use pointers?
 A: To access Heap Memory, allows dyanamic allocation of memory. Allows in system control like keyboard, mouse, other hardware, further creates jagged arrays, etc.
 
 Q: Dot(.) Vs Arrow(->)
 
 A: Dot operator can access members of structure/union/class
 Arrow operator access same thing but for pointers pointing to the strucrue varialble
 
 eg Struct Something {
        int ont ; int *two;
    }
 struct Something say;
 say.one = 100;
 int *ptr = say;
 now ptr.say doesnt work though ptr is pointing at say, its pointing at its address
 so as above, we use Deferencing operator, (*ptr).one
 [brackets bc dot operator has higher precedence and ptr.one (as disscussed) doent makes sense]
 
 instead of (*ptr).say we can use
  ------------     ------------
 | ptr -> say | = | (*ptr).say |
  ------------     ------------


 */


