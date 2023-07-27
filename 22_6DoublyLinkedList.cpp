#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertatHead(node *&head, int val)
{
    node *n = new node(val);

    n->next = head;
    if (head != NULL)
        head->prev = n;

    head = n;
}

void insertatTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        insertatHead(head, val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    cout << "NULL<- ";
    while (temp != NULL)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void todeleteHead(node *&head){
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    
    delete todelete;
}
void deleteNode(node *&head, int pos)
{
    if (pos == 1)
    {
        todeleteHead(head);
        return;
    }
    
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

   
    temp->prev->next = temp->next;       
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main()
{
    node *head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    display(head);
    insertatHead(head, 5);
    display(head);
    deleteNode(head, 1);
    display(head);
    deleteNode(head, 4);
    display(head);
    return 0;
}