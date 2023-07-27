#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    
    string s; cin>>s;
    vector<int> dict(256, -1);
    int maxlen = 0; int start = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if(dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxlen = max(maxlen, i-start);
    }
    cout<<maxlen<<endl;
    

   /*
    string s; cin >> s;
    unordered_map<char, int> m;
    unordered_map<char, int> m2;
    int ans = 0, j = 0;
    m2[s[j]] = -1;
    while (j < s.size())
    {
        int index = m2[s[j]];
        m.clear();
        m2.clear();
        for (j = index + 1; j < s.size(); j++)
        {
            m[s[j]]++;
            if (m[s[j]] > 1)
            {
                break;
            }
            m2[s[j]] = j;
        }
        int n = m.size();
        ans = max(ans, n);
    }
    cout << ans << endl;
    */
    return 0;
}