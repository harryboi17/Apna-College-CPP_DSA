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

void preorder(Node *root){
    if (root == NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void convertBinarytoLL(Node *root){
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    if (root->left != NULL)
    {
        convertBinarytoLL(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        
        t->right = temp;
    }
    convertBinarytoLL(root->right);
}

void PrintFlattentree(Node *root){
    if (root == NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    if (!root->left)
    {
        cout<<"NULL"<<" ";
    }
    PrintFlattentree(root->right);
}

int main(){
Node *root = new Node(1);
root->left = new Node(2);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right = new Node(3);
root->right->left = new Node(6);
root->right->right = new Node(7);
root->right->left->left = new Node(8);
root->right->left->right = new Node(9);

preorder(root); cout<<endl;
convertBinarytoLL(root);
preorder(root); cout<<endl;
PrintFlattentree(root); cout<<endl;

return 0;
}