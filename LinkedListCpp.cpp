//
//  LinkedListCpp.cpp
//  C++ course
//
//  Created by Kunal Dutta on 27/10/22.
//

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class linkedList
{
private:
    node *head;
public:
    linkedList()
    {
        head = NULL;
    }
    linkedList(int [], int);
    ~linkedList();
    void create(int [], int);
    void display();
    void insert(int, int);
    void insertAtHead(int);
    void pushback(int);
    void Delete(int);
    int length();
    bool search(int);
};

linkedList :: linkedList (int A[], int n)
{
    node *temp, *tail;
    head = new node(A[0]);
    tail = head;
    
    for(int i = 1; i<n; i++)
    {
        temp = new node(A[i]);
        tail->next = temp;
        tail = temp;
    }
}

void linkedList:: create(int A[], int n)
{
    node *temp, *tail;
    head = new node(A[0]);
    tail = head;
    
    for(int i = 1; i<n; i++)
    {
        temp = new node(A[i]);
        tail->next = temp;
        tail = temp;
    }
}

linkedList :: ~linkedList()
{
    node *temp = head;
    while(head)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void linkedList::display()
{
    node *temp = head;
    if(head == NULL)
    {
        cout << "Linked List doesn't exists\n";
    }
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void linkedList:: insert(int index, int x)
{
    if(index < 0 || index > length())
    {
        cout << "Not a valid Index";
        return;
    }
    node *temp;
    temp = new node(x);
    if(index == 0)
    {
        temp->next = head;
        head = temp;
        return;
    }
    node *trav = head;
    for(int i = 0; i<index-1; i++)
        trav = trav->next;
    temp->next = trav->next;
    trav->next = temp;
    return;
}

void linkedList:: insertAtHead(int x)
{
    node *temp = new node(x);
    temp->next = head;
    head = temp;
}

void linkedList:: pushback(int x)
{
    node *temp = new node(x);
    if(!head)
    {
        head = temp;
        return;
    }
    node *trav = head;
    while(trav->next)
    {
        trav = trav->next;
    }
    trav->next = temp;
}

int linkedList:: length()
{
    int count = 0;
    node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void linkedList:: Delete(int index)
{
    if(index < 0 || index > length()-1)
    {
        cout << "Invalid Index\n";
        return;
    }
    node *temp = head;
    if(index == 0)
    {
        head = head->next;
        delete temp;
        temp = NULL;
        return;
    }
    node *trav = head;
    for(int i=0; i<index && temp; i++)
    {
        trav = temp;
        temp = temp->next;
    }
    trav->next = temp->next;
    delete temp;
    temp = NULL;
    return;
}

bool linkedList:: search(int x)
{
    node *temp = head;
    while(temp)
    {
        if(temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    linkedList l;
    
    cout << "--Enter Preference--\n";
    cout << "1. Create a Linked List\n";
    cout << "2. Create using array of elements\n";
    cout << "3. Delete from List\n";
    cout << "4. Search in List\n";
    cout << "5. Find number of Elements\n";
    cout << "6. Display All\n";
    cout << "7. Exit\n";
    
    int choice = 0;
    while(choice != 7)
    {
        cout << "\n--Enter Preference-- ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "1. Insert at Head\n";
                cout << "2. Pushback Values\n";
                cout << "3. Insert at Specefic Index\n";
                int ins; cin >> ins;
                switch(ins)
                {
                    
                    case 1:
                    {
                        cout << "Enter Value ";
                        int val; cin >> val;
                        l.insertAtHead(val);
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter Value ";
                        int val; cin >> val;
                        l.pushback(val);
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter index and Value ";
                        int index, val;
                        cin >> index >> val;
                        l.insert(index, val);
                        break;
                    }
                    default: break;
                }
                break;  //break of global case 1
            }
            case 2:
            {
                cout << "Enter Size ";
                int n; cin >> n;
                cout << "Enter Elements ";
                int A[n];
                for(int i=0; i<n; i++) cin >> A[i];
                l.create(A, n);
                break;
            }
            case 3:
            {
                cout << "Enter Index ";
                int index; cin >> index;
                l.Delete(index);
                break;
            }
            case 4:
            {
                cout << "Enter value to be serached ";
                int val; cin >> val;
                l.search(val) ? cout << "Found " : cout << "Not Found ";
                break;
            }
            case 5:
            {
                cout << "Length of list is: " << l.length();
                break;
            }
            case 6:
            {
                l.display();
                break;
            }
            default:
                break;     //Global switch case break
        }
    }
}
