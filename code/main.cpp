// more pointers
#include <iostream>
using namespace std;
int main () {
  int num[]={1,2,3};
  int *myptr=num;
  cout<< "num[0]: " << *myptr <<endl; // 1
  cout<< "num[0]:" << *myptr++ <<endl; // 1
  cout<< "num[1]: " << *myptr <<endl; // 2
  cout<< "num[2]:" << *++myptr <<endl; // 3
  cout<< "num[2]+1: " << ++*myptr <<endl; // 4
  cout<< "num[2]: " << (*myptr)++ <<endl; // 4 先取值再修改值
  cout<< "num[2]: " << *myptr <<endl; // 5 得到修改後的值
  cout<< "num[2]: " << *(num+2) <<endl;
  return 0;
}