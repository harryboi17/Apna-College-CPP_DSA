#include <iostream>
using namespace std;
/*
*************BASIC DIFFERENCE BETWEEN HEAP AND STACK**********
1)stack automatically allocate and deallocate memory
  while in heap we have to allocate and deallocate the memory

2)stack have finite storing capacity
  while heap can store memory upto to the virtual memory of the computer
*/

int main(){
int a = 10; //this is will be stored in stack
int *p = new int(); // allocated memory in heap
*p = 10;
delete(p); //deallocation of memory

//now we can store new memory in p
p = new int[4]; //4 block of memory store in heap
delete[]p; // to delete those 4 block of memory

p = NULL; //p will get deleted after return 0

return 0;
}