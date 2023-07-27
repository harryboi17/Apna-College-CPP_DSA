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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void GivePtr(Node *root, Node **prev, Node **first, Node **mid, Node **last){
    if (root == NULL)
    {
        return;
    }
    
    GivePtr(root->left, prev, first, mid, last);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;   
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    GivePtr(root->right, prev, first, mid, last);
}

void Recover(Node *  root){
    Node *prev = NULL;
    Node *first = NULL;
    Node *mid = NULL;
    Node *last = NULL;

    GivePtr(root, &prev, &first, &mid, &last);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    } 
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
    /*
                6
               / \
              9   3
             / \   \
           1  4     13
    */
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right= new Node(3);
    root->right->right= new Node(13);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    inorder(root); cout<<endl;
    Recover(root);
    inorder(root);cout<<endl;

return 0;
}