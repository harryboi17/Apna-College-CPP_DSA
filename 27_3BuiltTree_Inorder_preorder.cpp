#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data =val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }  
    }
    return -1;
}

Node *BuildTreePre(int preorder[], int inorder[], int start, int end){

    
    static int idx = 0;
    if (start>end)
    {
        return NULL;
    }
    
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }
    

    int pos = search(inorder, start, end, curr);
    node->left = BuildTreePre(preorder, inorder, start, pos-1);
    node->right = BuildTreePre(preorder, inorder, pos+1, end);

    return node;
}

Node *BuildTreePost(int postorder[], int inorder[], int start, int end){

    
    static int idx = end;
    if (start>end)
    {
        return NULL;
    }
    
    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }
    

    int pos = search(inorder, start, end, curr);
    node->right = BuildTreePost(postorder, inorder, pos+1, end);
    node->left = BuildTreePost(postorder, inorder, start, pos-1);

    return node;
}

void inorderPrint(Node *root){
    if (root == NULL)
    {
        return;
    } 

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    int postorder[] = {4,5,2,6,7,3,1};

    Node *root = BuildTreePre(preorder, inorder, 0, 6);
    Node *root2 = BuildTreePost(postorder, inorder, 0, 6);
    inorderPrint(root);
    cout<<endl;
    inorderPrint(root2);

return 0;
}