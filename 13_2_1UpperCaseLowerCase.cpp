#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
string str = "HARSHIT bansal";

/*
for (int i = 0; i < str.size(); i++)
{
    if (str[i] >= 'a' && str[i] <= 'z')
    {
        str[i] -= 32;
    }   
}
cout<<str<<endl;

for (int i = 0; i < str.size(); i++)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
    {
        str[i] += 32;
    }   
}
cout<<str<<endl;
*/

transform(str.begin(), str.end(), str.begin(), ::toupper);
cout<<str<<endl;
// 1st input takes from where u have to take the string
// 2nd input takes from where u have to end the string
//3rd input takes from where you have to start working on the string
//3th input is the function

transform(str.begin(), str.end(), str.begin(), ::tolower);
cout<<str<<endl;
return 0;
}