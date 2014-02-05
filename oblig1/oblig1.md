Obligatorisk oppgave 1
========================================

*Effektiv kode med C og C++ vår 2014*

**Innlevering:** 

  * En mappe kalt "oblig1" må ligge i ditt private github-repository, der kun du og jeg (`alfred-bratterud`) har tilgang, innen **06.02.2014 kl.23:59**. Mappen kan være tom, men må legges ut 1 uke før den endelige fristen, for at jeg skal kunne sjekke at alle er med, og på github.
  * Link til ditt private github-repository må være levert inn i Fronter, innen dette tidspunktet.
  * De ferdige `.cpp`-filene må ligge i den samme mappen på github inen **14.02.2014 kl.23:59**
  * Det er to oppgaver, der **begge** skal løses. Nøttene i oppgave 1 er frivillige og kan droppes. Konkurransen i oppgave 2 må alle levere inn et `verdig forsøk` til, uten alvorlige feil, men den trenger ikke være perfekt.

**Generelle retningslinjer:**

  * Det er lov å snakke med hverandre om løsningen, men det å dele kode med andre, på noen som helst måte, blir betraktet som juks. Oppgaven er **individuell** så det er du alene som skal skrive koden, og du skal kunne redegjøre for innholdet.
  * Spesielt er det viktig at ingen åpner sitt github-repository for noen andre enn meg (alfred-bratterud)
  * Manglende innlevering gjør at man mister muligheten til å få karakter i kurset, med mindre man har *fått innvilget utsettelse før fristen.* 
  * Man vil få tilbakemelding på det man har gjort, og kan da evt. få beskjed om ting som må endres, for at oppgaven skal bli godkjent. Endringer må være levert innen 2 uker fra varsel.
  * *Alle steg i koden som ikke er helt trivielle skal kommenteres*

## 1) Oppvarming: Strenger som tall

**Filer å lage:** `stringlong.cpp`, evt. `compress.cpp` for "nøttene"

Du skal skrive et program med to funksjoner + main, som oversetter en streng til et 64-bits tall, og tilbake igjen. Programmet skal ha følgende funksjoner:

  1. `xx string_to_ulong(string s)` som tar en `std::string` som argument, og returnerer et tall, med de *64 første bit'ene* i stringen, i riktig rekkefølge, der `xx` er en passende datatype. De bitene som ikke får plass ignoreres.
  2. `string ulong_to_string(xx nr)` som tar et 64-bits tall som input, og returnerer en `std::string` bygget fra de 64 bitene. 
  3. `main` skal opprette et 64-bits tall, som skal inneholde returverdien fra funksjon 1. slik: `xx longstr=string_to_ulong("I love C++")`. Deretter skal tallet konverteres tilbake til string, og skrives ut.

Du kan skrive all den koden du mener du trenger, men forsøk å være konsis. Det er i alle fall mulig å løse oppgaven på 23 linjer (uten kommentarer), uten at det er noe mål i seg selv å få det spesielt kort.

###Nøtter (frivillig)
  1. 8 bit pr. tegn? For no' sløseri! Det er mer enn nok med 5 bit hvis vi kun tillater tegn med ascii-kode 32 tom. 96. Klarer du å lage en løsning som frakter 8 slike tegn i et array på 5 byte? 
  2. Skriv løsningen over, med støtte for strenger av vilkårlig lengde. 

Hvis du vil gjøre en av disse, lag funksjonene `string decompress(char* str,int size=5)` og `void compress(string s, char* result,int size)`, der `char*` er et array av komprimerte tegn (i den generelle løsningen vil det være noen ekstra bits på slutten).  Noen mulige hjelpemidler:

  * [std::bitset](http://www.cplusplus.com/reference/bitset/bitset/)
  * bitshifting: `<<` og `>>`
  * `malloc` / `free`

## 2) Word Cloud

**Filer å lage:** `wordcloud_stl.cpp`,`wordcloud_fast.cpp`, `wordcloud.pdf`/`wordcloud.jpg`

**Filer å inkludere:** `stop.h`

**Tilleggsfiler:** `rebup13.txt`
	  
Nettstedet [wordle.net](http://www.wordle.net) har en tjeneste som genererer en grafisk ordsky for deg. Denne er nyttig for å gi en visualisering av innholdet i en tekst. Problemet med å generere ordskyer direkte fra tekst, er at meningsløse ord som `er, i, på` etc. ofte kan bli veldig fremtredende. Disse kalles `stopp-ord`, og bør filtreres bort før man genererer en ordsky. Du skal lage et program `wordcloud` som genererer en liste av de mest brukte ordene i en tekst (En veldig god og veldig gammel tekst er lagt ved, i`rebup13.txt` og vil bli brukt i rettingen, men det skal naturligvis være en generell løsning) 

  * Alle ord skal gjøres om til lowercase før de lagres i datastrukturen
  * Skilletegn og stoppord er definert i `stop.h`, som skal inkluderes med `#include "./stop.h"` (du skal ikke endre denne filen). Skilletegn skal fjernes fra ordet og stopp-ord skal ignoreres. 
  * `wordcloud` skal ta et tall, `n` som argument. De `n` ordene som forekommer flest ganger i teksten skal skrives ut, på et format som støttes av [wordle.net/advanced](http://www.wordle.net/advanced)
  * Når du er ferdig, bruk [wordle.net/advanced](http://www.wordle.net/advanced) til å generere en ordsky. Lagre resultatet i `wordcloud.jpg` eller `wordcloud.pdf` (pdf kan lages ved å skrive ut til PDF. I mac er dette et standardvalg, men det finnes gratis verktøy for dette også for windows). Evt. bruk `.jpg` - dette kan du lagre ved å ta en screendump, og klippe det til i et bildebehandlingsprogram som feks. [Gimp](http://www.gimp.org/).

*Eksempel på output (OBS: Dette er IKKE reelle tall):*

      $cat repub13.txt | ./wordcloud 300
      ...
      soul	: 211
      question 	: 102
      harmony  	: 29
      notions  	: 16
      ...

Kommandoen `$cat repub13.txt | ./wordcloud 100 > wordle.txt` vil lagre outputen i tekstfila `wordle.txt`, så du slipper for mye tekst i terminalen din.

**Du skal implementere denne løsningen to ganger:**

  1. Med datastrukter fra standard template library: [STL containers](http://www.cplusplus.com/reference/stl/). I denne implementasjonen skal det ikke legges vekt på hastighet. Programmet skal ligge i `wordcloud_stl.cpp`.
  2. Uten å bruke noen av datastrukturene i STL. Dette betyr at du må lage dine egne datastrukturer, eller bare bruke arrays. Programmet skal ligge i `wordcloud_fast.cpp`.
    * Datatypene du bruker i datastrukturene må være gyldige i C, altså structer, pekere, arrayer, etc. C++ `string` er tillatt..
    * Dataene som leses inn må legges i "dynamic memory"/"free store". Utover dette står du fritt.
    * både `new` / `delete` og `malloc`/`free` er lov
    * Stopp-ord og annet tilbehør som ikke lastes inn fra fila, og som ikke er en datastruktur for ordtelling, kan legges i statisk minne om ønskelig. 

**OBS:** Programmet vil bli testet for minnelekkasjer med valgrind. Unngå dette ved å teste programmet ditt i valgrind på `studssh`
    
**Konkurranse**: De tre raskeste implementasjonene av `wordcloud_fast` blir kåret og havner på en (mer eller mindre) permanent high-score liste på hioa's github. Studenter i senere kull vil bli oppfordret til å forsøke å havne over dere på listen ;-)

  * Konkurransen har ingen effekt på karakteren - dette er bare ment å motivere dere til å øve på C.
  * Kun de tre beste blir kåret; det er ingen skam å ikke klare lista, og ingen får vite din tid, med mindre du er blandt de tre beste.
  * Klarer du ikke å lage en god løsning med egne datastrukturer kan du allikevel få obligen godkjent, men det må være gjort et ærlig forsøk, uten grove feil.


#Lykke til!
