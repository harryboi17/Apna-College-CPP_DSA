#include <iostream>
#include <vector>
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

bool Getpath(Node *root, int key, vector<int> &path){
    if (root == NULL)
    {
        return false;
    }
    
    path.push_back(root->data);

    if (root->data == key)
    {
        return true;
    }
    if (Getpath(root->left, key, path) || Getpath(root->right, key, path))
    {
        return true;
    }
    
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2){
    vector<int> path1, path2;
   
    if (!Getpath(root, n1, path1) || !Getpath(root, n2, path2) )
    {
        return -1;
    }
    
    int pc;
    for(pc = 0; pc<path1.size() && path2.size(); pc++){
        if (path1[pc] != path2[pc])
        {
            break;
        }   
    }

    return path1[pc-1];
}

Node *LCA2(Node *root, int n1, int n2){
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *LR = LCA2(root->left, n1, n2);
    Node *RR = LCA2(root->right, n1, n2);

    if (LR && RR)
    {
        return root;
    }
    
    if (LR != NULL)
    {
        return LR;
    }
    return RR;
    
}

int main(){
 struct Node *root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(3);
    root3->right->left = new Node(5);
    root3->right->left->left = new Node(7);
    root3->right->right = new Node(6);
    root3->left->left = new Node(4);

    cout<<LCA(root3, 4, 7);

return 0;
}