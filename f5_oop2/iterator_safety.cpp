#include <iostream>
#include <list>
#include <sstream>
#include <stdlib.h>
using namespace std;

class computer{
  int id;
  float ghz;
  float memsize;
  float disksize;
  string vendor;
public:
  computer(int _id):
  id(_id),ghz(),memsize(),disksize(),vendor(){}
  string to_string(){
    stringstream s;
    s << "Computer "<<id << ": "
      << ghz << " ghz CPU, " << memsize << "Gb ram ";
    return s.str();
  }
  ~computer(){
    //cout << "Computer " << id << " says good night" << endl;
    id=-1;    
  }
};

int main(){
  
  //Ingen grunn til å bruke peker her - bare for eksemplets skyld
  list<computer>* computers=new list<computer>;
  for(int i=0;i<10;i++)
    computers->push_back(computer(i));
  
  list<computer>::iterator it_first=computers->begin();

  list<computer>::iterator it;
  for(it=computers->begin();it!=computers->end();it++)
    cout << it->to_string() << endl;
  
  list<computer> list2=*computers;
  try{
    cout << "It, at first: " << it->to_string() << endl;
    for(int i=0;i<2000;i++)
      it++;
    
    cout << "It, after iteration: " << it->to_string() << endl;

    //computer* ptr=(computer*) it;
    //cout << "Ptr. cast from iterator: " << ptr->to_string() endl;
    list<computer>::iterator it2=it;    
    
    computers->clear();
    cout << "it after clear : " << it->to_string() << endl;
    cout << "it2 after clear : " << it2->to_string() << endl;


    //computers->clear(); 
    
    delete computers; //computers.clear(), for å bare ta innholdet.
    cout << "it after delete : " << it->to_string() << endl;
    cout << "it2 after delete : " << it->to_string() << endl;

    void* alot=malloc(100000000);
    free(alot);

    cout << "it after malloc: " << it->to_string() << endl;
    cout << "it2 after malloc: " << it2->to_string() << endl;    
    
    for(int i=0;i<10;i++)
      computers->push_back(computer(i+10));
    
    //    it2++;
    cout << "it after refill: " << it->to_string() << endl;
    cout << "it2 after refill: " << it2->to_string() << endl;    
    cout << "Iterator begin: " << it_first->to_string() << endl;



    
  }catch(exception e){
    cout << "Exception! "<< e.what() << endl;
  }
}
