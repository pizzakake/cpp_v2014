#include <iostream>

#include "class_fileFormatValidator.h"

using namespace std;

class privateFileFormatValidator : public fileFormatValidator{
  string fileType;
  string filename;
 public:
  privateFileFormatValidator(string _filename):
    filename(_filename),fileType(){/*...*/};
};

enum HTML_version{HTML2_0,HTML3_2,HTML4_0,HTML4_1,HTML5,XHTML};

class HTMLvalidator : public privateFileFormatValidator{
public:
  HTMLvalidator(string filename,HTML_version) 
    : privateFileFormatValidator(filename){/*...*/}
  bool valid() override {cout << "Probably not. "; return false;}
};

int main(){
  HTMLvalidator validator("index.html",HTML5);
  cout << "Valid HTML5: " << validator.valid() << endl;
  //fileFormatValidator v("myFile.ext"); //ERROR: Abstract!
}
