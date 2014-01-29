#include <iostream>

using namespace std;

/*Noen eksempler på bruk av const...
  ... og eksempler på merkelig oppførsel når vi prøver å "bryte" const
  Noen av eksemplene hadde jeg ikke løsning på i lab'en, de er kommentert
*/


/*
  Denne fant jeg løsning på ved bruk av "readelf" i linux, et verktøy for undersøke innhold i binærfiler med elf-format (dette er formatet på alle linux binærfiler). Det var som jeg skisserte på forelesningen: Konstante variabler deklarert i det globale navnerommet havner i en egen seksjon i binærfila, kalt .rodata for "read only data". Ved å kalle "readelf -S constness" får man en liste over alle seksjonene i binærfila. En av dem heter .rodata - hos meg er det nr.14. "readelf -x 14 constness" trekker da ut innholdet av seksjon 14, og viser det heksadecimalt. Jeg fikk ut 0x2a i den ene variablen her, som er ... hex for meningen med livet:-) Den andre er en "virtuell adresse" i elf-terminologi.
 */
const int i_glob=42;
const int* const j_glob=&i_glob;


int main(){
  const int i=42;
  const int* const j=&i;
  //*(j++); //Ikke lov
  cout << *j << endl;
  cout << i << endl;
  
  /*
    Hva skjer her?
   */
  int* i_glob_ptr=(int*)(&i_glob);
  (*i_glob_ptr)=43;
    

  /*
    Hva skjer her???
    Jeg fant løsningen ved å disassemble binærfila ;-) Den ligger i "constness_simple.cpp"
   */
  int* k=(int*)(&i);
  (*k)=43;
  
  cout << k << endl;
  cout << &i  << endl;
  
  cout << i << endl;
  cout << *k << endl;
}
