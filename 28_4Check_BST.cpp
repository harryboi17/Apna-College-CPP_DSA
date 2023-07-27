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

Node *insertBst(Node *root, int val){
    if (root == NULL)
    {
        return new Node(val);
    }
    
    if (val<root->data)
    {
        root->left = insertBst(root->left, val);
    }
    else{
        root->right = insertBst(root->right, val);
    }
    return root;
}

bool checkBst(Node *root, int min, int max){
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        if (checkBst(root->left, min, root->data) && checkBst(root->right, root->data, max))
        {
            return true;
        }    
    } 
    return false;
}
int main(){
int arr[] = {5,1,4,3,2,7};
Node *root2 = NULL;
int n = sizeof(arr)/sizeof(arr[0]);
for (int i = 0; i < n; i++)
{
     root2 = insertBst(root2,arr[i]);
}
cout<<checkBst(root2, INT_MIN, INT_MAX)<<endl;

Node *notBst = new Node(4);
notBst->left = new Node(2);
notBst->right= new Node(7);
notBst->right->left= new Node(3);
notBst->right->right= new Node(8);
notBst->left->left = new Node(1);
cout<<checkBst(notBst, INT_MIN, INT_MAX)<<endl;

Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);   
cout<<checkBst(root, INT_MIN, INT_MAX)<<endl;
return 0;
}