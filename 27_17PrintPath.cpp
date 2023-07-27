#include <iostream>
#include <vector>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

bool hasPath(Node *root, vector<int> &v, int x)
{
    if (!root)
        return false;

    v.push_back(root->data);

    if (root->data == x)
        return true;

    if (hasPath(root->left, v, x) || hasPath(root->right, v, x))
    {
        return true;
    }

    v.pop_back();
    return false;
}

void PrintPath(Node *root, int x)
{
    vector<int> v;

    if (hasPath(root, v, x))
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "NO Path" << endl;
}

void printPathsRecur(Node *node, int path[], int pathLen)
{
    if (node == NULL)
        return;

    path[pathLen] = node->data;
    pathLen++;

    if (node->left == NULL && node->right == NULL)
    {
        for (int i = 0; i < pathLen; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

int main()
{
    Node *root = new Node(2);
    root->left = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right = new Node(9);
    root->right->right = new Node(2);
    root->right->right->left = new Node(6);

    PrintPath(root, 8);
    PrintPath(root, 4);

    int path[100];
    printPathsRecur(root, path, 0);


    return 0;
}