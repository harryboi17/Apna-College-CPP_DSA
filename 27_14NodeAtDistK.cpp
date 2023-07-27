#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data; 
    Node *right;
    Node *left;

    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

Node *findNode(Node *root,int val){
    if (root == NULL)
    {
        return NULL;
    } 
    if (root->data == val)
    {
        return root;
    }

    Node *LT = findNode(root->left, val);
    Node *RT = findNode(root->right, val);

    if (LT != NULL)
    {
        return LT;
    }
    return RT;
}

void PrintSubTreeNode(Node *node, int k){
    if (node == NULL || k<0)
    {
        return;
    }    

    if (k == 0)
    {
        cout<<node->data<<" ";
    }

    PrintSubTreeNode(node->left, k-1);
    PrintSubTreeNode(node->right, k-1);    
}

int PrintnodeDistK(Node *root, Node *target, int k){
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        PrintSubTreeNode(root,k);
        return 0;
    }
    
    int dl = PrintnodeDistK(root->left,target,k);
    if (dl != -1)
    {
        if (dl+1 == k)
        {
            cout<<root->data<<" ";
        }
        else{
            PrintSubTreeNode(root->right, k-dl-2);
        }
        return 1+dl;
    }

    int dr = PrintnodeDistK(root->right,target,k);
    if (dr != -1)
    {
        if (dr+1 == k)
        {
            cout<<root->data<<" ";
        }
        else{
            PrintSubTreeNode(root->left, k-dr-2);
        }
        return 1+dr;
    }
    return -1; 
}

int main(){
Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
root->right->left->left = new Node(8);
root->right->left->right = new Node(9);

Node *search = findNode(root,3);
PrintnodeDistK(root, search, 2);

return 0;
}