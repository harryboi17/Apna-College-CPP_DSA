#include <iostream>
#include <limits.h>
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

Node *constructBstPre(int preorder[], int *preorderIdx, int key, int min, int max, int n){
    if (*preorderIdx >= n)
    {
        return NULL;
    }
    
    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBstPre(preorder, preorderIdx, preorder[*preorderIdx], min , key, n);
        }
        if (*preorderIdx < n)
        {
            root->right = constructBstPre(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }  
    }
    return root;
}

void PrintPreorder(Node *root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

int main(){
int preorder[] = {10,2,1,13,11};
int n = sizeof(preorder)/sizeof(preorder[0]);
int preorderIdx = 0;

Node *root = constructBstPre(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
PrintPreorder(root);

return 0;
}