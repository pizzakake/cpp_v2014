#include <iostream>

using namespace std;

template <class key,class value>
class myHash{
  key k;
  value v;
 public:
  myHash(key nk, value nv):k(nk),v(nv){}
  void toString(){cout << k << ":" << v << endl;};
};

int main(){
  myHash<int,int> h1(4,5);
  myHash<string,int> h2("age",12);
  h1.toString();
  h2.toString();
}
