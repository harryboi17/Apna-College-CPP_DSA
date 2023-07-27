#include <iostream>
using namespace std;
/*
string substring(string s, int size)
{
    if (size == s.size() + 1)
    {
        return "";
    }

    for (int j = 0; j <= s.size() - size; j++)
    {
        for (int i = j; i < size + j; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    substring(s, size+1);
}
*/

void subseq(string s, string ans){
    if (s.size() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    
    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros, ans);
    subseq(ros, ans+ch);
}

int main()
{
    subseq("ABCDE","");
    return 0;
}