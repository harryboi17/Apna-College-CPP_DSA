#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

bool IdenticalBST(Node *root1, Node *root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 != NULL && root1->data == root2->data )
    {
        if(IdenticalBST(root1->left, root2->left) &&  IdenticalBST(root1->right, root2->right)){
            return true;
        }   
    }  
    return false;
}

int main(){
Node *root1 = new Node(1);
root1->left = new Node(2);
root1->right= new Node(3);
root1->left->left = new Node(4);
root1->right->left = new Node(5);
root1->right->right= new Node(6);

Node *root2 = new Node(1);
root2->left = new Node(2);
root2->right= new Node(3);
root2->left->left = new Node(4);
root2->right->left = new Node(5);
root2->right->right= new Node(8);

cout<<IdenticalBST(root1, root2)<<endl;

return 0;
}