#include <iostream>
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

int CountNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

int SumofNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return SumofNodes(root->left) + SumofNodes(root->right) + root->data;
}

int Sumofnext(Node *root){
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else if(root->left == NULL && root->right != NULL){
        return root->right->data + root->data;
    }
    else if(root->left != NULL && root->right == NULL){
        return root->left->data + root->data;
    }
    
    return root->left->data + root->right->data + root->data;
}

Node *replaceWithSum(Node *node)
{
    if (node == NULL)
    {
        return node;
    }

    replaceWithSum(node->left);
    replaceWithSum(node->right);
    node->data = Sumofnext(node);

    return node;
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    /*
    struct Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(2);
    root->right->left->right = new Node(6);
    root->right->left->right->right = new Node(7);
    root->right->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(1);
    root->left->right->left = new Node(2);
    root->left->right->left->left = new Node(3);
    root->left->right->left->right = new Node(5);
    cout << CountNodes(root)<<endl;
    cout << SumofNodes(root)<<endl;
    */

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inorder(root); cout << endl;
    Node *newnode = replaceWithSum(root);
    inorder(newnode);

    return 0;
}