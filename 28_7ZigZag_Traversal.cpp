#include <iostream>
#include <deque>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

void ZigZag(Node *root)
{   
    stack<Node *> currlvl;
    stack<Node *> nextlvl;

    bool lefttoright = true;

    currlvl.push(root);
    while (!currlvl.empty())
    {
        Node *temp = currlvl.top();
        currlvl.pop();

        if (temp)
        {
            cout<<temp->data<<" ";
            if (lefttoright)
            {
                if (temp->left)
                    nextlvl.push(temp->left);
                if (temp->right)
                    nextlvl.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlvl.push(temp->right);
                if (temp->left)
                    nextlvl.push(temp->left);
            }
        }

        if (currlvl.empty())
        {
        cout<<endl;
        lefttoright = !lefttoright;
        swap(currlvl, nextlvl);
        }
    }
}

void zigzag(Node *root)
{
    deque<Node *> dq;
    deque<int> intdq;
    dq.push_back(root);
    dq.push_back(NULL);
    int level = 0;

    Node *node = dq.front();
    while (!dq.empty())
    {
        while (node != NULL)
        {
            dq.pop_front();
            intdq.push_back(node->data);

            if (node->left != NULL)
                dq.push_back(node->left);
            if (node->right != NULL)
                dq.push_back(node->right);

            node = dq.front();
        }
        dq.pop_front(); 

        if (level % 2 == 0)
            while (!intdq.empty())
            {
                cout << intdq.front() << " ";
                intdq.pop_front();
            }
        else
            while (!intdq.empty())
            {
                cout << intdq.back() << " ";
                intdq.pop_back();
            }
        
        if (!dq.empty())
        {
            cout << endl;
            level++;
            dq.push_back(node);
            node = dq.front();
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(9);
    root->right = new Node(3);
    root->right->right = new Node(5);
    root->left->right = new Node(4);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    zigzag(root); cout<<endl<<endl;;
    ZigZag(root); cout<<endl;

    return 0;
}