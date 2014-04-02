#include <iostream>

using namespace std;

class has_wings{
  int* i;
public:
  virtual void flap()=0;
  //virtual ~has_wings()=0; //Not possible!
  has_wings():i(new int(5)){}
  ~has_wings(){
    cout << "Has wings deleted" << endl;
    delete i;
  };
};


class horse : public has_wings{
  int* i;
public: 
  horse():i(new int(7)){};
  void flap() override{
    cout << "Horse flapping wings!" << endl;
  }
  
  ~horse(){
    delete i;
    cout << "Horse deleted" << endl;
  };
};


int main(){
  has_wings* winged_creature=new horse();
  winged_creature->flap();

  //  horse* pony=new horse();

  delete winged_creature;
  //delete pony;
}
