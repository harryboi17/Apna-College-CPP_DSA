#include <iostream>
#include <climits>
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

struct INFO{
    int size;
    int min;
    int max;
    int ans;
    bool Bst;
};

INFO largestBST(Node *root){
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }

    INFO lefttree = largestBST(root->left);
    INFO righttree = largestBST(root->right);

    INFO curr;
    curr.size = (1 + lefttree.size + righttree.size);
    if (lefttree.Bst && righttree.Bst && lefttree.max < root->data && righttree.min > root->data)
    {
        curr.min = min(lefttree.min, min(root->data, righttree.min));
        curr.max = max(righttree.max, max(root->data, lefttree.max));

        curr.ans = curr.size;
        curr.Bst = true;
        return curr;
    }

    curr.ans = max(lefttree.ans, righttree.ans);
    curr.Bst = false;
    return curr;
}

int main(){
/*
              22
            /   \ 
          20    30
         /  \  /  \
        14  21 23 29
*/

Node *root = new Node(22);
root->left = new Node(20);
root->left->left = new Node(14);
root->left->right = new Node(21);
root->right = new Node(30);
root->right->left = new Node(23);
root->right->right= new Node(29);

INFO curr = largestBST(root);
cout<<curr.ans<<endl;
return 0;
}