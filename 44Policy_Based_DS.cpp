#include <iostream>
#include <vector>
#include <limits.h>
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
/*
Ordered Set
Based on Red Black Trees

Included in:
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
null_type : it is a mapped policy. it is null policy used here to get set, if we want to get map but not set, then the second argument 
            must be mapped type

less : it is basis for comparision of two function. use less_equal for multiset(if you want to arrange duplicate numbers)

rb_tree_tag : type of tree used

tree_order_statistics_node_update : included in tree_policy.hpp and contains various operation for uopdatingt the node variant
                                    of tree based container, so we can keep track of metadata, like number of nodes in a subtree
*/
int main(){
int q; cin>>q;
oset<int> s;
while(q--){
    int c; cin>>c;
    int t; cin>>t;
    if(c == 1)
        s.insert(t);
    if(c == 2)
        cout<<*(s.find_by_order(t))<<endl; //gives the Kth largest element(from 0) //O(log(n))
    if(c == 3)
        cout<<s.order_of_key(t)<<endl; //gives number of numbers smaller than t in the set(t doesnt have to belong to set) //O(log(n))
}

return 0;
}