#include <iostream>
#include <sstream>

using namespace std;


struct student{
  string snr;
  string name;
};

struct node{
  node* next;
  student s;
};


int main(){
  node* studentList=new node;
  
  const int studcount=5;
  string names[studcount]={"Vidar","Trine","Rocky","Rambo","Kåre"};
  
  cout << "Size of string: " << sizeof(string) << endl;
  
  node* temp=studentList;
  cout << "Filling student list with " 
       << sizeof(names) 
       << " elements" <<  endl;
  
  for(int i=0;i<studcount;i++){
    stringstream s;
    s << "s" << "10"  << i;    
    temp->s.snr=s.str();         //I C++11, prøv to_string(i); //(*temp).s == temp->s
    temp->s.name=names[i];
    if(i<studcount-1){
      temp->next=new node;
      temp=temp->next;
    }    
  }
  
  temp=studentList;
  while(temp){
    cout << temp->s.snr << " : " << temp->s.name << endl;
    temp=temp->next;
  }
  
  delete studentList;
}
