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

class Node{
    public:
    Node *next[2];
    Node(){
        next[0] = NULL;
        next[1] = NULL;
    }
};

Node *trie;
void insert(int num){
    Node *it = trie;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        if(!it->next[bit])
            it->next[bit] = new Node();
        it = it->next[bit];
    }
}

int query(int num){
    Node *it = trie;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        int opp = bit xor 1;
        if(it->next[opp]){
            ans |= 1<<i;
            it = it->next[opp];
        }
        else
            it = it->next[opp xor 1];
    }
    return ans;
}

int main(){
    int arr[] = {6, 15, 7, 15, 3};
    int n = arrSize(arr);
    
    trie = new Node();
    insert(0);
    vi rmax(n+1, 0);
    int R = 0;
    
    for (int i = n-1; i >= 0; i--)
    {
        R = R xor arr[i];
        if(i != n-1)
            rmax[i] = max(rmax[i+1], query(R)); //dry run 1 7 4 0 as example to understand this line
        else
            rmax[i] = query(R);
        insert(R);
    }
    
    free(trie);
    trie = new Node();
    insert(0);
    int L = 0;
    int ans = 0;
    
    forr(i,0,n){
        L = L xor arr[i];
        ans  = max(ans, rmax[i+1] + query(L));
        insert(L);
    }
    cout<<ans<<endl;
return 0;
}