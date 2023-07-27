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

int HeightNode(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int lHeight = HeightNode(node->left);
    int RHeight = HeightNode(node->right);

    return max(lHeight, RHeight) + 1;
}

int DiameterNode(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int lheight = HeightNode(node->left);
    int rheight = HeightNode(node->right);
    int currentDiameter = lheight + rheight + 1;

    int lDiameter = DiameterNode(node->left);
    int rDiameter = DiameterNode(node->right);

    return max(currentDiameter, max(lDiameter, rDiameter));
}

int calcDiameter(Node *node, int &height)
{
    if (node == NULL)
    {
        height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(node->left, lh);
    int rDiameter = calcDiameter(node->right, rh);

    int curDiameter = lh + rh + 1;
    height = max(lh, rh) + 1;

    return max(curDiameter, max(lDiameter, rDiameter));
}

bool balancedHeightTree(Node *root, int &height)
{
    if (root == NULL)
    {   
        height = 0; 
        return true;
    }

    int lh = 0; int rh = 0;

    if (balancedHeightTree(root->left, lh) == false)
    {
        return false;
    };
    if (balancedHeightTree(root->right, rh) == false)
    {
        return false;
    }

    height = max(lh,rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
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
    root2->right = new Node(3);
    root2->right->left = new Node(4);
    root2->right->left->left = new Node(5);

    struct Node *root3 = new Node(1);
    root3->left = new Node(2);
    root3->left->left = new Node(3);

    cout << HeightNode(root) << endl;
    cout << DiameterNode(root) << endl;
    int height = 0;
    cout << calcDiameter(root, height) << endl;
    int h1= 0, h2 = 0, h3 = 0;
    cout<<balancedHeightTree(root,h1)<<endl;
    cout<<balancedHeightTree(root2,h2)<<endl;
    cout<<balancedHeightTree(root3,h3)<<endl;

    return 0;
}