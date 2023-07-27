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

void search(Node *root, int key){
    if (root == NULL)
    {
        cout<<"Key not found"<<endl;
        return;
    }
    
    if (root->data == key)
    {
        cout<<"Key Found"<<endl;
        return;
    }

    if (root->data>key)
    {
        search(root->left, key);
    }
    else{
        search(root->right, key);
    } 
}

Node *search2(Node *root, int key){
     if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == key)
    {
        return root;
    }

    if (root->data>key)
    {
        return search2(root->left, key);
    }
    
    return  search2(root->right, key);
}

Node *inorderSucc(Node *root){
    Node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deleteBst(Node *root, int key){
    if (root == NULL)
    {
        return root;
    }

    if (key<root->data)
    {
        root->left = deleteBst(root->left, key);
    }
    else if (key>root->data)
    {
        root->right = deleteBst(root->right, key);
    }
    else{
        if (root->left == NULL)
        {
            Node *temp = root->right; 
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node *temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteBst(root->right, temp->data);
        }   
    }
    return root;
}

void inorder(Node *head){
    if (head == NULL)
    {
        return;
    }
    
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}


int main(){
int arr[] = {5,1,4,3,2,7};
Node *root = NULL;
int n = sizeof(arr)/sizeof(arr[0]);
for (int i = 0; i < n; i++)
{
     root = insertBst(root,arr[i]);
}
inorder(root); cout<<endl;

search(root, 2);
search(root, 8);
if (search2(root, 2) == NULL)
{
    cout<<"Key not found"<<endl;
}
else{
    cout<<"Key found"<<endl;
}

deleteBst(root, 2);
inorder(root);

return 0;
}