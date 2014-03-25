#include <iostream>

using namespace std;

class fileFormatValidator{
  string filename;
 public:
  fileFormatValidator(string filename):filename(){};
  virtual bool valid()=0;
};

enum HTML_version{HTML2_0,HTML3_2,HTML4_0,HTML4_1,HTML5,XHTML};

class HTMLvalidator : public fileFormatValidator{
public:
  HTMLvalidator(string filename,HTML_version) 
    : fileFormatValidator(filename){/*...*/}
  virtual bool valid(){cout << "Probably not. "; return false;}
};

int main(){
  HTMLvalidator validator("index.html",HTML5);
  cout << "Valid HTML5: " << validator.valid() << endl;
  //  fileFormatValidator v("myFile.ext"); //ERROR: Abstract!
}
