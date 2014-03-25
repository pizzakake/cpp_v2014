#include <iostream>
#include <vector>


using namespace std;


template <class key,class value>
class keyValue{
  vector<key> k;
  vector<value> v;
public:
  void insert(key newKey,value newValue){
    k.push_back(newKey);
    v.push_back(newValue);
  }
  
  value get(key myKey){

    //class vector<key>::iterator it;
    auto it=k.begin(); //Compile with g++ key_value.cpp -std=c++0x -o key_value
    int i=0;
    for(it=k.begin();it!=k.end();it++)
      {
	if(*it==myKey)
	  return v[i];       
	i++;
      }
    throw string(myKey+" does not"+" exist ");

  };
  
};


int main(){
  keyValue<string,float> wallets;
  wallets.insert("Alfred",50000);
  wallets.insert("John",90);
  wallets.insert("Gunnar",2.40);
  
  cout << "John has " << wallets.get("John") << " in cash" << endl;
  try{
    cout << "Adam has " << wallets.get("Adam") << " in cash" << endl;
  }catch(string error){
    cout << error << endl;
  }
  
}
