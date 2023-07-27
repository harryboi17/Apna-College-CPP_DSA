#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); //the function will not cin the getline function if this is
                  //not used after a normal cin function

    char arr[n + 1];
    cin.getline(arr, n);
    
    int i = 0;
    int currentlen = 0;
    int maxlen = 0;
    int st=0; int maxst = 0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currentlen > maxlen)
            {
                maxlen = currentlen;
                maxst = st;
            }
            currentlen = 0;
            st = i+1;
        }
        else
        {
            currentlen++;
        }

        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << maxlen << endl;
    for (int i = 0; i < maxlen; i++)
    {
        cout<<arr[i+maxst];
    }
    cout<<endl;
    return 0;
}