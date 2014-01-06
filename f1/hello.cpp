#include <iostream>

using namespace std;

int square(int n){
  return n*n;
}

int n=8;

int main(){
  //i C ville vi skrevet: printf("%i squared is %i",n,square(n));
  cout << n << " squared is " << square(n) << endl;
  
}
