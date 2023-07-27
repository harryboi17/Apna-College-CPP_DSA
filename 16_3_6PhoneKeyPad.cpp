#include <iostream>
using namespace std;
string KeyPadArr[] = {"", "/.", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keyPad(string s, string ans){
    if (s.size() == 0)
    {
        cout<<ans<<" ";
        return;
    }

    char ch = s[0];
    string code = KeyPadArr[ch - '0'];
    string ros = s.substr(1);

    for (int i = 0; i < code.size(); i++)
    {
        keyPad(ros, ans + code[i]);
    }
}

int main(){
keyPad("234", "");

return 0;
}