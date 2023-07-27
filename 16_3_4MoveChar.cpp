#include <iostream>
using namespace std;

string MoveX(string s)
{

    if (s.size() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = MoveX(s.substr(1));

    if (ch == 'x')
    {
        return ans + ch;
    }
    else
    {
        return ch + ans;
    }
}

int main()
{
    cout << MoveX("xxaskbdxjskbaxxtjx");
    return 0;
}