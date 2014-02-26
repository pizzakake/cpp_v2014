#include <iostream>

using namespace std;

class counter{
  int i;  
  
public:
  counter():i(){}

  //Prefix increment
  counter& operator++(){
    i++;
    return *this;
  }
  
  //Postfix increment  
  counter operator++(int i){ //Ikke en referanse!
    counter c=*this;
    ++(*this);
    return c;
  }
  
  friend ostream& operator<<(ostream& s,counter c);
};
  
ostream& operator<<(ostream& s,counter c){
  s << c.i; return s;
};



int main(){

  counter c;  
  cout << "Initialized c" << endl << c << endl;
  
  cout << "Prefix increment" << endl;
  cout << ++c << endl;
  cout << c << endl;

  cout << "Postfix increment" << endl;
  cout << c++ << endl;
  cout << c << endl;


}
