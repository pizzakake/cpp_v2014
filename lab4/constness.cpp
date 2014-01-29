#include <iostream>

using namespace std;




int main(){
  const int i=42;
  const int* const j=&i;
  //*(j++); //Ikke lov
  cout << *j << endl;
  cout << i << endl;
  
  /*
    Hva skjer her???
   */
  int* k=(int*)(&i);
  (*k)=43;
  
  cout << k << endl;
  cout << &i  << endl;
  
  cout << i << endl;
  cout << *k << endl;
}
