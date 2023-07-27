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

void PrintLevelOrder(Node *root, int k){
    if (root == NULL)
    {
        return;
    }
    
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0; int sum = 0;
    cout<<"LEVEL: "<<level<<endl;
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            
            cout<<node->data<<" ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }   
        }    
        else if(!q.empty()){
            cout<<endl;
            level++;
            cout<<"LEVEL: "<<level<<endl;
            q.push(node);
        }
    }
    cout<<endl<<"SUM at the Kth level = "<<sum<<endl;
}

int main()
{
    int k; cin>>k;
    
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    PrintLevelOrder(root, k);
    
    /*
    struct Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->left->right = new Node(6);
    root->right->left->right->right = new Node(7);
    root->right->right= new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(1);
    root->left->right->left = new Node(2);
    root->left->right->left->left = new Node(3);
    root->left->right->left->right = new Node(5);
    PrintLevelOrder(root, k);
    */

    return 0;
}