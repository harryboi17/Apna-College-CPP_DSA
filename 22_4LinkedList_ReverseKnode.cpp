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

node *ReverseKNode(node *&head, int k)
{
    node *prev = NULL;
    node *currentptr = head;
    node *nextptr;
    int count = 0;
    while (currentptr != NULL && count < k)
    {
        nextptr = currentptr->next;
        currentptr->next = prev;
        prev = currentptr;
        currentptr = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = ReverseKNode(nextptr, k);
    }

    return prev;
}

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool detectcycle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void remove_cycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next == fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // insertAtTail(head, 6);
    display(head);

    node *newnode = ReverseKNode(head , 3);
    display(newnode);

    cout << detectcycle(head) << endl;
    makecycle(head, 4);
    cout << detectcycle(head) << endl;
    remove_cycle(head);
    cout << detectcycle(head) << endl;


    return 0;
}