#include <iostream>

using namespace std;


const int i_glob=42;
const int* const j_glob=&i_glob;


int main(){
  const int i=42;
  const int* const j=&i;
  //*(j++); //Ikke lov
  cout << *j << endl;
  cout << i << endl;
  
  /*
    Hva skjer her?
   */
  int* i_glob_ptr=(int*)(&i_glob);
  (*i_glob_ptr)=43;
    

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
