#include <iostream>
using namespace std;

/*
1) Size can be modified
2) Non- continguos memory
3) Insertion and Deletion at any point is easier
*/

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *head){
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;   
}

node* reverse(node *&head){
    node *previous = NULL;
    node *current = head;
    node *nextptr;

    while(current != NULL){
        nextptr = current->next;
        current->next = previous;
        previous = current;
        current = nextptr;
    }
    return previous;
}

node *ReverseRecursive(node *&head){

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node *newhead  = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead; 
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // insertAtHead(head, 4);
    // display(head);
    // cout << search(head, 4) << endl;
    // cout << search(head, 5) << endl;
    // cout << search(head, 3) << endl;
    // deletion(head, 3);
    display(head);
    // node *newnode = reverse(head);
    node *newnode = ReverseRecursive(head);
    display(newnode);
    

    return 0;
}