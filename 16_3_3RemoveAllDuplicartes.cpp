#include <iostream>
using namespace std;

void Duplicate(string s)
{
    if (s.size() == 0)
    {
        return;
    }
    
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[0])
        {
            s.erase(i, 1);
            i -= 1;
        }
    }
    cout << s[0];
    Duplicate(s.substr(1));
}

int main()
{
    Duplicate("aabaaccbbefdaf");
     return 0;
}