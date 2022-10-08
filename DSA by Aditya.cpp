//
//  DSA by Aditya.cpp
//  C++ course
//
//  Created by Kunal Dutta on 18/09/22.
//

//
//  Assignment_1.cpp
//  CS261
//  Declaring of class function in line way
//  Created by Aditya kumar on 05/09/22.
//

#include <iostream>
#define MAX 1000
using namespace std;

class node{
public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
    }
};

class linkedList{
     node* head;
public:
    void insertAtFirst(int x);
    void insertAtEnd(int x);

    void deleteElement(int x);
    bool search(int x);
    void printNodesData();
    int size();
    
};

// All linked list function definition

void linkedList::insertAtFirst(int x){
    if(head == NULL){
        head = new node(x);
        return;
    }
    else{
        node* temp = new node(x);
        temp->next = head;
        head = temp;
    }
}

void linkedList:: insertAtEnd(int x){
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node* ptr  = new node(x);
    temp->next = ptr;
}

void linkedList:: deleteElement(int x){
    if(head == NULL){
        cout << "Linked list is empty. No element available to delete." << endl;
        return;
    }
   
    if (head->next == NULL && head->data == x){
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    
       node* temp = head;
       while (temp->next->data != x) {
           temp = temp->next;
       }
       node* todelete = temp->next;
       temp->next = temp->next->next;
       
       delete todelete;
    
}

bool linkedList:: search(int x){
    node* temp =  head;
    while (temp != NULL) {
        if(temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}

void linkedList:: printNodesData(){
    node* temp = head;
    if(head == NULL){
        cout << "Linked list is empty" << endl;
        return;
    }
    while (temp!= NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int linkedList:: size(){
    if(head == NULL)
        return 0;
    else{
        int counter = 1;
        node* temp = head;
        
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
}



class Array{
    int arr[MAX];
    int ptr;
    
public:
    Array(){
        ptr = 0;
    }
    void insert(int x);
    void remove(int x);
    int size();
    void search(int x);
    void printElement();
};

class stack{
private:
    int arr[MAX];
    int top;
    
public:
    stack(){
        top = -1;
   }
    void push(int x);
    void pop();
    int Top();
    bool empty();
};

class queue{
    int arr[MAX];
    int front;
    int back;
    
public:
   queue(){
       front = -1;
       back = -1;
    }
    void enqueue(int x);
    void dequeue();
    int peek();
    bool isEmpty();
    bool isFull();
    int queue_size();
};

// All stack class function definition

void stack :: push(int x){
    if(top == MAX-1){
        cout << "Stack overflow" <<  endl;
        return;
    }
    top++;
    arr[top] = x;
}

void stack :: pop(){
    if (top == -1){
        cout << "Stack is empty" << endl;
        return;
    }
    top--;
}

int stack :: Top(){
    if(top == -1){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return arr[top];
}
bool stack :: empty(){
    return top == -1;
}

// All queue class function definition


void queue::enqueue(int x){
    if (back == MAX-1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    back ++;
    arr[back] = x;
    
    if(front == -1)
        front ++;
}

void queue:: dequeue(){
    if (front == -1 || front >  back){
        cout << "Queue Underflow" << endl;
        return;
    }
    front++;
}

int queue:: peek(){
    if (front == -1 || front >  back){
        cout << "Queue Underflow" << endl;
        return -1;
    }
    return arr[front];
}

bool queue:: isEmpty(){
    if(front == -1 || front > back)
        return true;
    else
        return false;
}

bool queue:: isFull(){
    if((back + 1) % MAX == front)
        return true;
    else
        return false;

}

// All array class function definition

void Array:: insert(int x){
    if(ptr == MAX)
        cout << "Array has reached to its maximum limit." << endl;
    else{
        arr[ptr] = x;
        ptr++;
        
    }
}

void Array :: remove(int x){
    if(ptr){
        cout << "Array is empty"<< endl;
        return;
    }
    else{
        for (int i = 0; i < ptr; i++) {
            if (arr[i] == x) {
                for (int j = i; i < ptr -1; j++) {
                    arr[ptr] = arr[j+1];
                }
                ptr--;
                return;
            }
            cout << "Element not found" << endl;
        }
    }
}

int Array:: size(){
    return ptr;
}

void Array:: search(int x){
    for (int i = 0; i < ptr; i++) {
        if(arr[i] == x)
            cout << "Element is available" << endl;
    }
    cout << "Element is available" << endl;
}

void Array::printElement(){
    for (int i = 0; i < ptr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}






int main(){
    cout << "Name the data structure which you want to use: " << endl;
    cout << "1. Array" << endl;
    cout << "2. Stack" << endl;
    cout << "3. Queue" << endl;
    cout << "4. Linked List" << endl;
    
    
    cout << "Enter the sequence of data structures: " << endl;
    
    int ds;
    cin >> ds;
    
    switch (ds) {
        case 1:
            {
                cout << "You have chosen array. Now automatically an array is created."<< endl;
                Array arr;
                
                cout << "Which operation do you want to perform?" << endl;
                cout << "1. Insert an element" << endl;
                cout << "2. Remove an element" << endl;
                cout << "3. Check the element that it is available or not" << endl;
                cout << "4. Printing the elements of array" << endl;
                cout << "5. Exit" << endl;
                
                int operation = 0;
                
                while (operation != 5) {
                    cout << "Enter the operation sequence: "<< endl;
                    cin >> operation;
                    
                    switch (operation) {
                        case 1:
                        {
                            cout << "Enter the element you want to insert" << endl;
                            int n;
                            cin >> n;
                            arr.insert(n);
                        }
                            break;
                            
                        case 2:
                        {
                            cout << "Enter the element you want to remove" << endl;
                            int n;
                            cin >> n;
                            arr.remove(n);
                        }
                            break;
                            
                        case 3:
                        {
                            cout << "Enter the element you want to check whether it is available or not" << endl;
                            int n;
                            cin >> n;
                            arr.search(n);
                        }
                            break;
                            
                        case 4:
                        {
                            cout << "The elements present in an array are :" << endl;
                            arr.printElement();
                            
                        }
                            break;
                            
                        default:
                            break;
                    }
                }
            }
            break;
            
        case 2:
        {
            cout << "You have chosen stack. Now automatically a stack is created." << endl;
            stack st;
            cout << "Which operation do you want to perform?" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Get Topmost element" << endl;
            cout << "4. Printing the elements of stack" << endl;
            cout << "5. Exit" << endl;
            
            int operation = 0;
            
            
            while(operation != 5){
                cout << "Enter the operation sequence." << endl;
                cin >> operation;
            switch (operation) {
                case 1:
                    {cout << "Enter the element you want to push: " << endl;
                    int n;
                    cin >> n;
                    st.push(n);
                        
                    }
                    break;
                    
                case 2:
                {
                    if(st.empty())
                        cout << "No element available" << endl;
                    else{
                        st.pop();
                        cout << "Element has been poped out from stack" << endl;
                    }
                }
                    break;
                    
                case 3:
                {
                    if(st.empty())
                        cout << "No element available" << endl;
                    else
                        cout <<"The topmost element of the stack is "<< st.Top() << endl;
                }
                    break;
                    
                case 4:
                {
                    if(st.empty())
                        cout << "No element available" << endl;
                    else{
                        cout << "The elements of stack are ";
                        while (!st.empty()) {
                            cout << st.Top() << " ";
                            st.pop();
                        }
                        cout << endl;
                    }
                    
                }
                    
                    
                default:
                    break;
            }
        }
            
        }
            break;
            
        
            
        case 3:
        {
            cout << "You have chosen queue. Now automatically a queue is created" << endl;
            queue q;
            cout << "Which operation do you want to perform?" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Get Topmost element" << endl;
            cout << "4. Printing the elements of queue" << endl;
            cout << "5. Exit" << endl;
            
            int operation = 0;
            
            while (operation != 5) {
                cout << "Enter the operation sequence: " << endl;
                cin >> operation;
                
                switch (operation) {
                    case 1:
                    {
                        int n;
                        cout << "Enter the element you want to push: " << endl;
                        cin >> n;
                        q.enqueue(n);
                    }
                        break;
                        
                    case 2:
                    {
                        if(!q.isEmpty()){
                            q.dequeue();
                            cout << "Element has been dequeued" << endl;
                        }
                        else
                            cout << "Queue is empty and no element to dequeue" << endl;
                    }
                        break;
                        
                    case 3:
                    {
                        if(!q.isEmpty())
                            cout << "The front element of the queue is " << q.peek() << endl;
                        else
                            cout << "Queue is empty and you need to insert an element" << endl;
                    }
                        break;
                        
                    case 4:
                    {
                        if(!q.isEmpty()){
                            cout << "The element of queue is ";
                            while(!q.isEmpty()){
                                cout << q.peek() << " ";
                                q.dequeue();
                            }
                            cout << endl;
                        }
                        else
                            cout << "Queue is empty and you need to insert the elements" << endl;
                    }
                        break;
                        
                    default:
                        break;
                }
                
            }
            
            }
            break;
            
        case 4:
        {
            cout << "You have chosen linked list. Now automatically a node is created." << endl;
            linkedList ll;
            
            cout << "Which operation do you want to perform?" << endl;
            cout << "1. Insert a node at head" << endl;
            cout << "2. Insert a node at end" << endl;
            cout << "3. Delete any node" << endl;
            cout << "4. Searching an element in linked list" << endl;
            cout << "5. Printing the data stored in the node in linked list" << endl;
            cout << "6. Number of nodes present in linked list" << endl;
            cout << "7. Exit" << endl;
            
            int operation = 0;
            
            while (operation != 7) {
                cout << "Enter the operation sequence" << endl;
                cin >> operation;
                
                switch (operation) {
                    case 1:{
                        cout << "Enter the elements you want to insert at head" << endl;
                        int n;
                        cin >> n;
                        ll.insertAtFirst(n);
                        cout << "Number inserted" << endl;
                    }
                        break;
                        
                    case 2:
                    {
                        cout << "Enter the elements you want to insert at end" << endl;
                        int n;
                        cin >> n;
                        ll.insertAtEnd(n);
                        cout << "Number Inserted" << endl;
                    }
                        break;
                        
                    case 3:
                    {
                        cout << "Enter the number stored in node which you want to delete" << endl;
                        int n;
                        cin >> n;
                        ll.deleteElement(n);
                        cout << "Node Deleted" << endl;
                    }
                        break;
                        
                    case 4:
                    {
                        cout << "Enter the element you want to search in linked list" << endl;
                        int n;
                        cin >> n;
                        if(ll.search(n))
                            cout << "Element is available" << endl;
                        else
                            cout << "Element not found" << endl;
                    }
                        break;
                        
                    case 5:
                    {
                        cout << "The number stored in linked list is " << endl;
                        ll.printNodesData();
                    }
                        break;
                        
                    case 6:
                    {
                        cout << "The number of nodes in linked list is " << ll.size() << endl;
                    }
                        break;
                        
                    default:
                        break;
                }
            }
            
        }
            
            
            break;
            
        default:
            break;
    }
    

}

