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

class car : public vehicle{
public:
  car(string _model, float _weight): vehicle(_model,_weight){
    if(_weight>2500)
      throw runtime_error("Way too heavy: "+std::to_string(_weight));
  }
};

class bus : vehicle{
  
};


int main(){
  try{
    car myVolvo("Volvo v50",3000);
  }catch(exception& err){
    cout << err.what() << endl;
  }
  
  car myVolvo("Volvo v50",1900);
  cout << myVolvo.to_string() << endl;
  
}
