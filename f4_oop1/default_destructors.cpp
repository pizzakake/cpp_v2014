#include <iostream>

using namespace std;

class student{
  int nr;  //int nr=0; //C++11
  string name;
  student* next;
public:
  student():nr(),name("N/A"),next(0){}
  void make_next(){next=new student();}
  int get_nr(){return nr;}
  string get_name(){return name;}  
  ~student(){
    cout << "Deleting next" << endl;
    delete next;
  }
};
  
int main(){
  cout << "C with Classes!"<< endl;

  
  student s1;//=student();
  cout << "S1: '" << s1.get_name() <<"'" <<endl;
  cout << "S1: '" << s1.get_nr() <<"'" <<endl;  
  //s1.~student(); //Ikke når denn ikke er kalt med new!
  
  //Destructor kalles når main går ut av skop
 
  student* s2=new student();
  cout << "S2: '" << s2->get_name() <<"'" <<endl;
  cout << "S2: '" << s2->get_nr() <<"'" <<endl;  
 
  //Dennes destructor kalles ikke når main går ut...

  s2->make_next(); //Destructor kalles "rekursivt"
  delete s2; 

  //Gi constructor name, og la alle destructorer skrive ut navnet sitt

  //Ouch!
  /*
  cout << "S2: '" << s2->get_name() <<"'" <<endl;
  cout << "S2: '" << s2->get_nr() <<"'" <<endl;  
  */


  
}
