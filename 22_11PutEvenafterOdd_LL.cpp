#include <iostream>
using namespace std;
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

node *EvenafterOdd(node *&head)
{
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *tailtemp = tail;

    node *temp1 = head;
    while (temp1 != tail && temp1 != tail->next)
    {
        while((temp1->next->data) % 2 == 0 && temp1->next != tail->next)
        {
            tailtemp->next = temp1->next;
            tailtemp = tailtemp->next;
            temp1->next = temp1->next->next;
        }
        temp1 = temp1->next;
    }
    tailtemp->next = NULL;

    if (head->data%2 == 0)
    {
        node *temp = head;
        while (temp->next->data % 2 == 1)
        {
            temp = temp->next;
        }
        node *ptr = temp->next;
        node *store = head;
        head = head->next;
        temp->next = store;
        store->next = ptr;
    }
}

int main()
{
    int arr[] = {1,2,4,6,1,8,10,3,12,5,7,14};
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    node *head = NULL;
    for (int i = 0; i < arrsize; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
    EvenafterOdd(head);
    display(head);

    return 0;
}