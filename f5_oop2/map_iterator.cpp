#include <iostream>
#include <map>

using namespace std;

class computer{
  int id;
public:
  computer(int _id):id(_id){}
  string to_string(){return string("Computer ")+std::to_string(id);};
  ~computer(){cout << "Computer "<<id<<"shut down"<<endl;}
  /*
  computer(computer&&)=default;
  computer(computer&)=default;
  computer& operator=(computer& c)=default;//{move(c.id);}
  computer& operator=(computer&& c)=default;//{move(c.id);}*/
};




int main(){
  map<int,computer> computers=map<int,computer>();  
  for(int i=0;i<10;i++){
    computers.emplace(i,computer(i));
    //computers[i]=computer(i); funker ikke (!)
  }  
  
  computers.begin()->second=computer(100); // (!)Lekkasje?

  for(auto it= computers.begin();it!=computers.end();it++)
    cout << it->first << ": " << it->second.to_string()<< endl; 
}



