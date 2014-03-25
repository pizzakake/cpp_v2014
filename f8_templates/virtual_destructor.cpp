#include <iostream>

using namespace std;

class has_wings{
public:
  virtual void flap()=0;
  //virtual ~has_wings()=0; //Not possible!
  virtual ~has_wings(){};
};


class horse : public has_wings{
public: 
  void flap() override{
    cout << "Horse flapping wings!" << endl;
  }
  
  ~horse(){};
};


int main(){
  has_wings* winged_creature=new horse();
  winged_creature->flap();
  
}
