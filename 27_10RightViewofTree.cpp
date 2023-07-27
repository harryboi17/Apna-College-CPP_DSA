#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void RightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n-1)
            {
                cout<<curr->data<<" ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }       
        }
    }
}

void LeftView(Node *root){
     if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout<<curr->data<<" ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }       
        }
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->left->right = new Node(8);
    root2->left->right->left = new Node(5);
    root2->left->right->left->right = new Node(6);
    root2->left->right->left->left = new Node(7);

    struct Node *root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->right->left = new Node(5);
    root3->right->left->left = new Node(7);
    root3->right->right = new Node(6);
    root3->left->left = new Node(4);

    RightView(root); cout << endl;
    RightView(root2); cout << endl;
    RightView(root3); cout << endl;
    LeftView(root); cout<<endl;
    LeftView(root2); cout<<endl;
    LeftView(root3 ); cout<<endl;
    return 0;
}