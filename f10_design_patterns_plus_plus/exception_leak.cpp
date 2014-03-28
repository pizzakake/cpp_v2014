/*
  Example to show how an exception causes a memory leak (From f5)
*/

#include <iostream>

using namespace std;

void fill(int* arr,int size){
  for(int i=0;i<size;i++){
    arr[i]=42;
    if(i>100)
      throw string("Aw... too tired"); //throw "Aw... too tired"; (!)
  }
}
  
void alloc(){
  const int size=1000;
  int* i=new int[size];
  fill(i,size);
  delete[] i;
}


int main(){
  try{
    alloc();
  }catch(string s){
    cout << "Exception caught: "<< s << endl;
  }
}
