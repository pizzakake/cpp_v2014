#include <iostream>

using namespace std;

struct big{
  int arr[1000];
};



void read(int& valuable){
  valuable++;
  cout << "Your int is: " << valuable << endl;
}


void change(big& data){
  data.arr[900]=43;
}


int main(){
  int i=42;
  read(i);
  cout << "The meaning of life is " << i << endl;

  big data;
  data.arr[900]=42;
  cout << "Data " << data.arr[900] << endl;
  change(data);
  cout << "Data " << data.arr[900] << endl;
}
