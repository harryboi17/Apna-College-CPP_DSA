#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (prec(st.top()) >= prec(s[i])))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

string reverse(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    string news;
    while (!st.empty())
    {
        news += st.top();
        st.pop();
    }

    return news;
}

string infixtoPrefix(string str)
{
    string s = reverse(str);

    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && (prec(st.top()) >= prec(s[i])))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    string finals = reverse(res);
    return finals; 
}

int main()
{
    int t; cin>>t;
    while(t--){
    string s;
    cin >> s;
    cout <<"Inflix to PostFlix : "<< InfixToPostfix(s) << endl;
    // cout<<reverse(s)<<endl;
    cout << "Inflix to PreFix : "<< infixtoPrefix(s) << endl;
    }
    return 0;
}