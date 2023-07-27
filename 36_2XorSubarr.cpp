#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;
// max Xor when you take 2 elements from an array.
//num right shift(<<) pos means removing starting n(pos) bits that
//is 1111 << 2 = 11 and 1011 << 2 = 10

class TrieNode{
    public:
        TrieNode *next[2];
        TrieNode(){
            next[0] = NULL;
            next[1] = NULL;
        }
};

TrieNode *buildTree(int arr[], int n){
    TrieNode *root = new TrieNode();
    forr(i,0,n){
        int num = arr[i];
        TrieNode *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) && 1; // can also use (num & (1<<i)) ? 1 : 0;
            if(curr->next[bit] == NULL)
                curr->next[bit] = new TrieNode();
            curr = curr->next[bit];
        }
    }
    return root;
}

int helper(TrieNode *root, int arr[], int n){
    int res = 0;
    forr(i,0,n){
        int num = arr[i];
        int cur_max = 0;
        TrieNode *it = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num >> i) & 1 ? 0 : 1;
            if(it->next[bit]){
                cur_max <<= 1;
                cur_max |= 1;
                it = it->next[bit];
            }
            else{
                cur_max <<= 1;
                cur_max |= 0;
                it = it->next[bit xor 1];
            }
        }
        res = max(res, cur_max);
    }
    return res;
}

int main(){
int arr[] = {3, 10, 5, 15, 2};
int n = arrSize(arr);

TrieNode *root = buildTree(arr, n);
int ans = helper(root, arr, n);
cout<<ans<<endl;
return 0;
}