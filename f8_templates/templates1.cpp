#include <iostream>
using namespace std;


template <class MyGenericType>
void print(MyGenericType t){
  cout << t << endl;
}

template <class MyGenericType,class T>
void print2(MyGenericType t,T t2){
  cout << t << " " << t2 << endl;
}



int main(){
  print(5);
  print("a");
  print2("Run","for your life");
}
