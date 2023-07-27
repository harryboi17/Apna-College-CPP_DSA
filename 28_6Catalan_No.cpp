#include <iostream>
#include <vector>
using namespace std;
/*
*********CATALAN SEQUENCE*********
C0 = 1, C1 = 1, Cn = summation(Ci*C(n-i)) [i = 0 to n-1] 
*/
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

void Catalan(int n){
    int arr[n];
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += arr[j]*arr[i-j-1];
        }
        arr[i] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    } 
}

int catalan(int n){
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

int countBST(Node *root){
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    static int count = 1;
    return count + countBST(root->left) + countBST(root->right);
}

vector<Node*> Constructtrees(int start, int end){
    vector<Node*> Trees;
    if (start>end)
    {
        Trees.push_back(NULL);
        return Trees;
    }
    
    for (int i = start; i <= end; i++)
    {
        vector<Node*> LeftSubTree = Constructtrees(start, i-1);
        vector<Node*> RightSubTree = Constructtrees(i+1, end);

        for (int j = 0; j < LeftSubTree.size(); j++)
        {
            Node *left = LeftSubTree[j];
            for (int k = 0; k < RightSubTree.size(); k++)
            {
                Node *right = RightSubTree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                Trees.push_back(node);
            }     
        }
    }
    return Trees;
}

void preorder(Node *root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
int n; cin>>n;

Catalan(n); cout<<endl;
for (int i = 0; i < 7; i++)
{
    cout<<catalan(i)<<" ";
} 
cout<<endl;

Node *root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7); 

Node *notBst = new Node(4);
notBst->left = new Node(2);
notBst->right= new Node(7);
notBst->right->left= new Node(3);
notBst->right->right= new Node(8);
notBst->left->left = new Node(1);

cout<<countBST(root)<<endl<<countBST(notBst)<<endl<<endl;

vector<Node*> TotalTrees = Constructtrees(1,3);
for (int i = 0; i < TotalTrees.size(); i++)
{
    cout<<i+1<<" : ";
    preorder(TotalTrees[i]);
    cout<<endl;
}



return 0;
}