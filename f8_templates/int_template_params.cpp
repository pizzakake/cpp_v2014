#include <iostream>

using namespace std;

template<class T, int  SIZE>
struct myArr{ 
  T elements[SIZE]; 
};


int main(){
  myArr<char,5> arr1;
  arr1.elements[4]='a';
  cout << arr1.elements[4] << endl;
  
  myArr<string,3> arr2;
  arr2.elements[2]="Hey!";
  cout << arr2.elements[2] << endl;
  
}
