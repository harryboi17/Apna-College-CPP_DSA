#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
/*
here n is first converted into bit, like for 5 it is converted into 0101
then we created another number using left shift operator '<<' 
1<<pos represents 0100 for pos = 2, and 0001 for pos 0;
then we used & operator to find out common number, for number 5 and pos 2,
0101 & 0100 we get 0100, then we return it such that if its 1 then return 1 else return 0;
*/

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}
/*
here we used or function
for number like 0101 and 1000(1<<pos) we used or to get 1101 which
we will get in return
*/

int clearBit(int n, int pos){
     return (n & ~(1<<pos)); 
}
/*
here for number 0101 and 0100(1<<pos)
we used negation of 0100 which is 1011 and used & so that we get
0001 such that we cleared the bit at desired position
*/

int updateBit(int n, int pos){
   setBit(clearBit(n,pos), pos);
}

int main()
{
    int n;
    int pos;
    cin >> n >> pos;
    cout << getBit(n, pos) << endl;
    cout << setBit(n, pos) << endl;
    cout << clearBit(n, pos) << endl;
    cout<<updateBit(n, pos)<<endl;

    return 0;
}