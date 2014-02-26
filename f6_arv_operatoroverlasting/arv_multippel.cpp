#include <iostream>
#include <stdexcept>
using namespace std;

class vehicle{
  //protected:
  string model;
  int regnr;
  string owner;
  float weight;  
public:
  vehicle(string _model,float _weight):
    model(_model),weight(_weight){}
  string to_string(){return model;}
};

class with_color{
  int _color=0xff0000;
 public:
  int color(){return _color;}
  //string to_string(){return std::to_string(_color);} Oups!
};

class car_with_color : public vehicle, public with_color{
public:
  car_with_color(string _model, float _weight): vehicle(_model,_weight){
    if(_weight>2500)
      throw runtime_error("Way too heavy: "+std::to_string(_weight));
  }
};

int main(){
  try{
    car_with_color myVolvo("Volvo v50",3000);
  }catch(exception& err){
    cout << err.what() << endl;
  }
  
  car_with_color myVolvo("Volvo v50",1900);
  cout << myVolvo.to_string() << endl;
  cout << hex << "Color 0x" << myVolvo.color() << endl;
}
