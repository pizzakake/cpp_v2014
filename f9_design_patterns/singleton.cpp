#include <iostream>
#include <fstream>

using namespace std;

class logfile{
  
private:
  static logfile* instance;
  ofstream f;
  static const string filename;
  logfile(){
    f.open(filename.c_str()); //here, or in printLine
  };

public:
  void printLine(string s){
    //if(!f.good())
    //f.open(filename.c_str());
    f << s << endl;
    //    f.close();
  };

  static logfile& getInstance(){
    if(!instance)
      instance=new logfile;
    return *instance;
  };
  
      
  /*
  ~logfile(){
    cout << "Closing logfile" << endl;
    f.close();
  }
  - A destructor does not make much sense - there will never be an instance going out of scope
  - How about manually destroying it? Well, we have returned pointers to it... they will break if we delete.
  - "Resouce acquisition is initialization" (TC++PL3 section 14.4)
  
  
  */
};

//initialize static members
logfile* logfile::instance=0;
const string logfile::filename="uniqueLogfile.txt";


void printToLog(string s){
  logfile& lf=logfile::getInstance();
  lf.printLine(s);
}

int main(){
  //logfile lf;
  logfile& lf=logfile::getInstance();
  lf.printLine("Made a singleton!");
  printToLog("...And used it twice!");
  

}
