#include <iostream>
using namespace std;

void Permutation(string s, string ans)
{
    if (s.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);

        Permutation(ros, ans + ch);
    }
}

int main()
{
    Permutation("ABC", "");

    return 0;
}