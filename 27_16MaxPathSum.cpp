#include <bits/stdc++.h>
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

int MaxPathsumFromNode(Node *root, int sum, int maxi){
    if (root == NULL)
    {
        return maxi;
    }
    
    sum += root->data;
    maxi = max(maxi, sum);
  
    return max(MaxPathsumFromNode(root->left, sum, maxi), MaxPathsumFromNode(root->right, sum, maxi));
}

int MaxPath(Node *node, int &ans){
    if (node == NULL)
    {
        return 0;
    }

    int left = MaxPath(node->left, ans);
    int right = MaxPath(node->right, ans);

    int nodeMax = max(max(node->data, node->data+left+right), max(node->data + left, node->data + right));
    ans = max(ans, nodeMax);

    int SinglePathSum = max(node->data, max(node->data + left, node->data + right));
    return SinglePathSum;
}

int main(){
Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);
root->right->left->left = new Node(8);
root->right->left->right = new Node(9);

cout<<MaxPathsumFromNode(root, 0, 0)<<endl;
int ans = INT_MIN;
MaxPath(root, ans);
cout<<ans<<endl;
return 0;
}