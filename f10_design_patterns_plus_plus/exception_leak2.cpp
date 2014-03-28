/*
  The same example, also with a memory leak - but notice how the destructor gets called anyway...
  This is the key to the RAII -pattern (Resource Acquizition Is Initialization) in raii.cpp
*/
#include <iostream>

using namespace std;


class exception_proof{
public:
  ~exception_proof(){
    cout << "Calling destructor of exception-proof!" << endl;
  }
};


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
  exception_proof variable{};
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
