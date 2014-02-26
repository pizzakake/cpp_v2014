#include <iostream>
using namespace std;

class int_pair{
  int left;
  int right;
public:
  int_pair(int l,int r):
    left(l),right(r){}
  int operator[](unsigned int i){
    if(i==0)
      return left;
    return right;
  }
  
  friend ostream& operator<<(ostream&,int_pair);
};


ostream& operator<<(ostream& s,int_pair p){
  s << "(" << p.left << "," << p.right << ")"; //<< endl?
  return s;
}


int main(){
  int_pair p1(1,42);
  cout << p1[0] << endl;
  cout << p1[985] << endl;
  cout << p1 << endl;
}
