#include <iostream>

using namespace std;


class user{
  string firstName;
  string lastName;
  string username;
public: 
  user(string first,string last):
    firstName(first),lastName(last),username(){/*...*/}
  virtual void ask(string s){
    cout << endl<< firstName << ": Yes " << s << " is good with donuts" << endl;
  };
  friend ostream& operator<<(ostream&,user);
  string shortname(){return firstName;};
};

ostream& operator<<(ostream&,user);

struct veteran: public user{
  veteran(string fn,string ln):
    user(fn,ln){}
  string giveHelp();
  void ask(string s) override {
    cout<< endl<<shortname() << ": Well, I did build "<<s << " into C++..." << endl;
  }
};

struct noob: public user{
  noob(string fn,string ln):
    user(fn,ln){}
  void requestHelp(veteran &s);
  void ask(string s){
    cout<< endl<<shortname() <<": You mean "<<s << ",like, in politics'n stuff?"<< endl;
  }
};

int main(){
  user& erna=*new noob("Erna","Solberg"); //Ikke gjør dette vanligvis?
  user* bjarne=new veteran("Bjarne","Stroustrup");
  
  cout << endl << "Do you know anything about polymorphism?" << endl;
  erna.ask("polymorphism");
  bjarne->ask("polymorphism");
  cout << endl << endl;
  
  delete &erna; 
  delete bjarne;
}


ostream& operator<<(ostream& o,user u){
  return o << u.firstName << " " << u.lastName;
}
