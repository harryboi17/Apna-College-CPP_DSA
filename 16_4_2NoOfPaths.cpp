#include <iostream>
using namespace std;

int path(int s, int end)
{
    if (s == end)
    {
        return 1;
    }
    if (s > end)
    {
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += path(s + i, end);
    }
    return count;
}

int main()
{

    cout << path(0, 4);

    return 0;
}