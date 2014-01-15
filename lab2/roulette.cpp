/*
En implementasjon av roulette, basert på map (key-value). 
- Dette skal gå vesentlig tregere enn array- og vector-baserte løsninger (kommer)

*/
#include <iostream>
#include <vector>
#include <map>

//C standardbibliotek
#include <stdlib.h>


using namespace std;

int n=10000000; //1000000

int seq=1;

enum{RED,BLACK}; //myArr[RED] == myArr[0], myArr[BLACK]==myArr[1]
map <int,int> vals;
map <int,int> seqs;
vector <int> keys;

int main(){
  
  cout << "Roulette!" << endl;
  
  vals[RED]=0;
  vals[BLACK]=0;
    
  srand(time(0));
  cout << "Time: " << time(0) << endl;
  
  int rnd=rand()%2;
  cout << "First random number: " << rnd << endl;
  int prevRand=0;

  cout << "Previous random number: " << prevRand << endl;

  for(int i=0; i<n; i++)
    { 
      prevRand=rnd;
      vals[rnd]++; 

      rnd=rand()%2;
      
      if(rnd==prevRand)	
	seq++;      
      else{
	if(seqs[seq]==0) keys.push_back(seq);
	seqs[seq]==0 ? seqs[seq]=1 : seqs[seq]++;
	seq=1;
      }
      
      //cout << "Random number " << i << ": " << rnd << endl;
      
    }
    
  sort(keys.begin(),keys.end());
  for(int i=0; i<keys.size(); i++)
    cout << keys[i]  << "\t" << seqs[keys[i]] << endl;
    
  cout << "Number of black: " << vals[BLACK] << endl;
  cout << "Number or red: " << vals[RED] << endl;
    

}
