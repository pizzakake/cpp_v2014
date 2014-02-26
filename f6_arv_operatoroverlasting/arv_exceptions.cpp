#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

class file_not_found_exception : public exception {
  string reason;
public: 
  string what(){
    return reason;
  }
    
  file_not_found_exception(string _reason): reason(_reason){}
  //~file_not_found_exception() throw() {}
};
 

int main(){
  string filename="arv_er_kult.cpp";
  try{
    ifstream f(filename.c_str());
    if(!f.is_open())
      throw file_not_found_exception(filename);
  }catch(file_not_found_exception fnfe){
    cout << "File not found: " << fnfe.what() << endl;
  }catch(exception e){
    cout << "Exception: " << e.what() << endl;
  }
}
