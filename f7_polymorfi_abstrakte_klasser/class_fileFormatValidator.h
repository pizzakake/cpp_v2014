#ifndef CLASS_FILE_FORMAT_VALIDATOR_H
#define CLASS_FILE_FORMAT_VALIDATOR_H
#include <iostream>

/*
  Et Offentlig interface for noe veldig privat. 
  - vi har kun med det som er public
  - alt annet ligger i implementasjonen
*/

class fileFormatValidator{
 public:
  virtual bool valid()=0;
};


#endif
