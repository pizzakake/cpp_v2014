#include <iostream>

//Vi kan enten slå sammen navnerommet "std" med vårt eget slik:
//using namespace std;
//Eller vi kan bruke namespace-operatoren :: , til å referere til navn i navnerommet (se under)


//Vi kan fint definere egne namespaces slik:
namespace roulette{
  int i=10;
}


/*
  Valg av datastruktur for roulette...
  
  Et array, på JSON-notasjon, ser slik ut.
  Her brukes en index, mellom 0 og lengden på arrayet, som nøkkel for å referere til verdiene
  arr=[1,2,2,2,3,3,3]; //Nå vil arr[2] => 2

  Et "objekt" på JSON-notasjon 
  Generelt kalt "key-value"; her brukes en "valgfri nøkkel" til å referere til verdi, i stedet for en index
  (tilsvarer assosiativt array i PHP, HashMap i Java, Dictionary i Python, Hash i perl etc., og map i C++)
  obj={"s1010110":"Alfred, 5:"fem", "calc"=function(x){return x*x;}} ; 
  // Nå vil obj["s1010110"]=> "Alfred" og  obj.calc(5)=>25

*/


int  j=20;

int main(){  
  //Her bruker vi std::cout og roulette::i for å referere til variable i andre namespaces
  // Vi kunne også brukt "using namespace std" eller "using namespace roulette" for å slå sammen namespaces
  std::cout << "Roulette" << j << roulette::i << std::endl;
}

