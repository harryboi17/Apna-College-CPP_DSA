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

    void insert(string word){
        int i = 0;
        Node *it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new Node();
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word){
        int i = 0;
        Node *it = trie;
        while(i < word.size()){
            if(it->next[word[i] - 'a'] == NULL)
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main(){
    Tries *mytrie = new Tries();
    vector<string> v = {"harshit", "vanshika"};

    for(auto i : v)
        mytrie->insert(i);
    int n; cin>>n;
    forr(i,0,n){
        string s; cin>>s;
        if(mytrie->search(s))
            cout<<s<<" is found"<<endl;
        else
            cout<<s<<" not found"<<endl;
    }
return 0;
}