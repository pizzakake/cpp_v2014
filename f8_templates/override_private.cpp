#include <iostream>

using namespace std;

class stringable{
  virtual string formatted()=0;
public:
  virtual string toString()=0;
};

class candy : public stringable{
  string name;

public:
  string formatted() override {return "Candy name: "+name;};
  candy(string s):name(s){};
  string toString() override{
    return formatted();
  }
};

int main(){

  candy lollypop("Lollypop");
  stringable* lolly=&lollypop;
  
  cout << lolly->toString() << endl;
  //cout << lolly->formatted() << endl  Not possible; 
  cout << lollypop.formatted() << endl; //Possible!

}
