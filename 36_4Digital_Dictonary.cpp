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

class Tries{
    public:
    class Node{
        public:
        Node *next[26];
        bool end;
        Node(){
            end = false;
            forr(i,0,26)
                next[i] = NULL;
        }
    };

    Node *trie;
    Tries(){
        trie = new Node();
    }

    void insert(string &s){
        Node *it = trie;
        for(auto c : s){
            if(it->next[c - 'a'] == NULL)
                it->next[c - 'a'] = new Node();
            it = it->next[c - 'a'];
        }
        it->end = true;
    }

    void find(string &s){
        Node *it = trie;
        for(auto c : s){
            if(!it->next[c - 'a']){
                cout<<"No suggestions"<<endl;
                insert(s);
                return;
            }
            it = it->next[c - 'a'];
        }
        vector<string> res;
        printall(it, s, res, "");
        for(auto c : res)
            cout<<s<<c<<endl;
    }

    void printall(Node *it, string &s, vector<string> &res, string curr){
        if(it == NULL)
            return;
        if(it->end)
            res.push_back(curr);
        
        forr(i,0,26)
            if(it->next[i])
                printall(it->next[i], s, res, curr + char('a' + i));
    }
};

int main(){
Tries t;
int n; cin>>n;
vector<string> a(n);
for(auto &i : a){
    cin>>i;
    t.insert(i);
}

int q; cin>>q;
while(q--){
    string s; cin>>s;
    t.find(s);
}

return 0;
}