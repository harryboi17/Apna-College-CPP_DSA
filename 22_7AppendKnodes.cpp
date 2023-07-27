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

int nodelenght(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

node *AppendKnodes(node *&head, int k)
{

    if (k >= nodelenght(head) || k == 0)
    {
        return head;
    }

    node *newhead;
    node *newtail;
    node *tail = head;
    int pt = nodelenght(head) - k;
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == pt)
        {
            newtail = tail;
            newhead = tail->next;
        }
        tail = tail->next;
        count++;
    }
    tail->next = head;
    newtail->next = NULL;

    return newhead;
}

void intersectheads(node *&head1, node *&head2, int k){
    node *temp1 = head1;
    while (--k)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection(node *&head1, node *head2){
int l1 = nodelenght(head1);
int l2 = nodelenght(head2);

int d;
node *ptr1;
node *ptr2;

if (l1>l2)
{
    d = l1-l2;
    ptr1 = head1;
    ptr2 = head2;
}
else{
      d = l2-l1;
    ptr1 = head2;
    ptr2 = head1; 
}

while (d--)
{
    ptr1 = ptr1->next;
    if (ptr1 == NULL)
    {
        return -1;
    }
}

while (ptr1 != NULL && ptr2 != NULL)
{
    if (ptr1 == ptr2)
    {
        return ptr1->data;
    }
    
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
}
return -1;
}

int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    display(head);
    node *newnode = AppendKnodes(head, 3);
    display(newnode);

    node *head1 = NULL;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        insertAtTail(head1, arr1[i]);
    }

    node *head2 = NULL;
    int arr2[] = {8, 9};
    for (int i = 0; i < 2; i++)
    {
        insertAtTail(head2, arr2[i]);
    }

    intersectheads(head1, head2, 5);
    display(head1);
    display(head2);
    cout<<intersection(head1, head2)<<endl;
    return 0;
}