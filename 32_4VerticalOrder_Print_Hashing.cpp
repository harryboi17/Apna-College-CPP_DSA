#include <iostream>
#include <vector>
#include <map>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;

    Node(int val){
        data = val;
        right = NULL;
        left = NULL;
    }
};

void verticalOrder(Node *root, int Pos, map<int, vi> &m){
    if (root == NULL)
        return;
    
    m[Pos].push_back(root->data);
    verticalOrder(root->left,  Pos - 1, m);
    verticalOrder(root->right,  Pos + 1, m);

}

int main(){
Node *root = new Node(10);
root->left = new Node(7);
root->right = new Node(4);
root->left->left = new Node(3);
root->left->right = new Node(11);
root->right->left = new Node(14);
root->right->right = new Node(6);

map<int, vi> m;
verticalOrder(root, 0, m);

for(auto i : m){
    for(auto j : i.second)
        cout<<j<<" ";
    cout<<endl;
}    
return 0;
}