#include <iostream>



void my_print(int x){
  std::cout << x << std::endl;
}


int main(){
  /*  

  push   %rbp
  //Husk base-pointer (Bunnen av stack, for forrige funksjon)

  mov    %rsp,%rbp
  //Sett "min" base pointer til å være stackpointer (toppen av stack nå, er bunnen av "min stack")

  sub    $0x20,%rsp
  //Sett av to plasser paa stack, dvs. 8 byte *4 
  //(i, k, j pluss... ett ekstra ord. why? det viser seg)

   */

  const int i=42; 
  /*  Blir til:
	//flytt 0x2a inn i stack (rbp+ec)	
  	movl   $0x2a,0xffffffffffffffec(%rbp)
	
	lea    0xffffffffffffffec(%rbp),%rax
	mov    %rax,0xfffffffffffffff0(%rbp)
	//sett adressen herfra inn i 'i' (rbp+0)

  //Effektivt sett skjer dette:
  rbp+ec := 42   //42 får en egen plass på stack
  &i rbp+0 :=    //i blir en egen peker på stack
  *i := &42      //i peker på 42

  */  


  const int* const j=&i;
  /*
  //Effektivt: 
  j := rbp+ec  //j settes til å peke på 42 (der 42 ligger på stack)
  */

  int* k=(int*)(&i);
  /*
    //Effektivt: k := &42 (ikke gyldig c, men k får adressen til 42 ligger)
    // eller, &k := rbp+8, og k := rbp+ec (adressen til 42)

    I Assembler:

    lea    0xffffffffffffffec(%rbp),%rax
    //Flytt adressen til 42 inn i rax
    
    mov    %rax,0xfffffffffffffff8(%rbp)
    //Flytt rax (adressen til 42) inn i rbp+8 

    */



  //Så endrer vi
  (*k)=43;

  /*
    Assembler:

    mov    0xfffffffffffffff8(%rbp),%rax   
    //Flytt adressen til k, inn i rax (rbp+8)
    
    movl   $0x2b,(%rax)
    //Flytt 43 inn i det rax (adressen til k) peker på (som før det er 42)
    
   */

  my_print(*k);
  /*
    Print. Ingen overraskelser

    mov    0xfffffffffffffff8(%rbp),%rax
    //Flytt adressen til k inn i rax

    mov    (%rax),%edi
    //Flytt det k peker paa inn i edi
    
    callq  400814 <_Z8my_printi>
    //Print

    */
  
  //SÅ KOMMER CLUET: 
  my_print(i);
  
  /*  
    mov    $0x2a,%edi
    //Flytt 43 inn i edi, direkte! Altså, ikke det i - som er en peker bak kulissene - peker på, men de faktiske *verdien* til i.

    //Konklusjon: i er en peker til et sted på stack, bak kulissene. 
    // Vi endret det i pekte på, fra 42 til 43, som forventet.
    // Men, når vi ber om å få skrevet ut i, jukser den, og skriver ikke ut det i peker på, men bare verdien. 
    // Hvordan? Kompilatoren har skiftet ut alle referanser til i, med verdien, hardkodet inn i binærfila. (assemblerkoden er det jeg fikk av å disassemble binærfila - så det ligger der)
    
    //JUKS! Men OK, jeg prøvde å jukse først, så jeg ba vel om det:-)

    */

  /*
    Deretter kaller vi print, og returnerer som normalt.
    callq  400814 <_Z8my_printi>
    //Print 

    mov    $0x0,%eax
    //Flytt 0 inn i eax (exit-verdi)

    leaveq     
    //return

   */
  

    
}


