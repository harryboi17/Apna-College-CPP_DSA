#include <iostream>
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

Node *BSTSortArray(Node *root, int arr[], int start, int end){
    if (start<end)
    {
    int mid = (start+end)/2;
    root = new Node(arr[mid]);
    root->left = BSTSortArray(root->left, arr, start, mid);
    root->right = BSTSortArray(root->right, arr, mid+1, end);
    }
    return root;
}

void inorder(Node *root){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
int arr[] = {1,2,3,4,5,6};
int n = sizeof(arr)/sizeof(arr[0]);
Node *root = NULL;
Node* node = BSTSortArray(root, arr, 0, n);
inorder(node);


return 0;
}