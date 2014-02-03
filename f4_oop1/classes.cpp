#include <iostream>

using namespace std;

class student{
  int nr;
  string name;
public: 
  student(string name): nr(10),name(name) {};
  student(): nr(10),name("N/A") {};
  int get_nr(){return nr;}
  string get_name(){return name;}
  string dont_care;
};
  
int main(){
  cout << "C with Classes!"<< endl;
  
  student s1("Alfred");
  cout << "S1: " << s1.get_name() << endl;
  
  student* s2=new student("Yoda");
  cout << "S2: " << s2->get_name() << endl;

  student s3;
  cout << "S3: " << s3.get_name() << endl;
  
  
  //Forsøk å få malloc til å opprette et studentobjekt... ikke lett (og ikke meningen)
  student* s4=(student*)malloc(sizeof(student));

  //*s4=student("Alfred");

  /*
  s4->dont_care=42;
  cout << s4->get_name() << endl;
  cout << s4->dont_care << endl;      
  */

  /*
  (*s4)=s3;
  s4->dont_care=42;
  cout << s4->get_name() << endl;
  cout << s4->dont_care << endl; 
  */
  
  /*
  s4=&s3;  
  s4->dont_care=42;
  cout << s4->get_name() << endl;
  cout << s4->dont_care << endl; 
  */
  
  /*  student* s5=s2;
  cout << s5->get_name() << endl;
  cout << s5->dont_care << endl; 
  
  */

  int* i=(int*)&s3;
  cout << *i << endl;

}
