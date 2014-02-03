#include <iostream>

using namespace std;

class student{
  int nr;  //int nr=0; //C++11
  string name;
public:
  //student():nr(),name(){}  //Initialisér alltid!
  int get_nr(){return nr;}
  string get_name(){return name;}
};
  
int main(){
  cout << "C with Classes!"<< endl;
  
  student s1;//=student();
  cout << "S1: '" << s1.get_name() <<"'" <<endl;
  cout << "S1: '" << s1.get_nr() <<"'" <<endl;  

}
