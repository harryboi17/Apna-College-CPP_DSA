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

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *LR = LCA2(root->left, n1, n2);
    Node *RR = LCA2(root->right, n1, n2);

    if (LR && RR)
    {
        return root;
    }

    if (LR != NULL)
    {
        return LR;
    }
    return RR;
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dist;
    }

    int left = findDist(root->left, k, dist + 1);
    if (left != -1)
    {
        return left;
    }
    return findDist(root->right, k, dist + 1);
}

int DistBtw2Nodes(Node *root, int n1, int n2)
{
    Node *lca = LCA2(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main()
{
    struct Node *root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->right->left = new Node(5);
    root3->right->left->left = new Node(7);
    root3->right->right = new Node(6);
    root3->left->left = new Node(4);

    cout<<DistBtw2Nodes(root3, 4,7);

    return 0;
}