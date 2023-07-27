#include <iostream>
using namespace std;

void reverse(string s){
    if (s.length() == 0)
    {
        return;
    }

    string ros = s.substr(1);// substr returns the string after index i(here 1)
    reverse(ros);
    cout<<s[0]; 
}

void replacePI(string s){
       if (s.length() == 0)
    {
        return;
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout<<"3.14";
        string sub = s.substr(2);
        replacePI(sub);
    }
    else{
        int i=0;
        while (s[i] != 'p' || s[i+1] != 'i')
        {
            cout<<s[i];
            i++;
        }
        string sub = s.substr(i);
        replacePI(sub);   
    }
    
}

int main(){
reverse("binod");
cout<<endl;
replacePI("pippxxppiixipi");

return 0;
}