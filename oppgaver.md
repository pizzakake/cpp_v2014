Oppgaver, C++ 2014
===========================


## Uke 3-4: Datatyper
  1. **Innebygde (primitive) typer**
     * I et nytt program med kun `main`, opprett  følgende variabler: `float f`, `int i`, `char c`, `double d` - uten å initialisere. Bruk funksjonen `sizeof(x)` til å skrive ut størrelsen på alle sammen.      
     * Lag to pekere, `int* iptr` og `char* cptr`. Hvor store blir disse? Skriv ut størrelsen på disse også, med sizeof.
     * Skriv nå ut innholdet i alle variablene. Hva er de? Forsøk å flytte alle variablene hhv. inn i og ut av main. Endrer dette verdiene? PS: Legg merke til at utskrift av `char*` kanskje har litt uventet oppførsel. Dette er fordi en char-pointer er det samme som en string i C (mer om dette under). Kan du forklare oppførselen? Hvis den skaper problemer, kommentér den ut, i resten av denne deloppgaven.
     * Forsøk konvertere implisitt, fra hhv. `float` til `int`, `char` til `int` og `int` til `char`. Legg merke til hvor du får feilmeldinger. Har feilmeldingene noe med størrelsen på objektene å gjøre?
     * Lag en funksjon `void print_ascii_table()` som skriver ut hele ascii-tabellen. Dette gjør du ved å lage en for-løkke som itererer over alle mulige verdier av char (0-255), konverterer den til hhv. både char og  int og skriver ut nummeret på tegnet, et kolon, og selve tegnet. (Feks. `65: 'A'`). Det er lurt å skrive ut et anførselstegn rett før og rett etter tegnet, slik at det blir tydelig hvilke tegn som er "tomme".

  2. **Arrayer og c_string**  
     * Opprett to funksjoner, hhv. `void stackmess()` og `void int_arr()`. Funksjonen `stackmess` skal opprette tre arrayer, á 20 int'er (`int arrx[20]`), og fylle disse tre med tilfeldige tall, via en løkke (`arrx[i]=rand()`). Funksjonen `int_arr` skal opprette et nytt array, med 20 int'er, uten å initialisere, og så skrive ut innholdet i arrayet. 
        * La main kalle `int_arr`. Hva skrives ut? Blir det noen forskjell hver gang du kjører programmet? 
        * La main kalle `stack_mess` før du kaller int_arr. Hva er det som skjer her? Har det noe å si om du kaller `srand(time(0))` før du kjører stackmess? Forsøk å forklare hva som skjer. Hvis det er vanskelig, don't worry, det kommer mer om dette.
     * Lag en funksjon `void c_strings()` som oppretter et char-array og initialiserer det slik: `char* str=string("Hello world").c_str()`. Skriv ut `str` direkte. `str` er en peker, men er det en adresse som skrives ut?
       * Lag nå en løkke der `int i` itererer fra 0 til `sizeof(str)` og skriver ut `str[i]` (ikke legg linjeskift etter hver tegn, bare ett linjeskift etter løkken). Hva blir skrevet ut? Endre strengen til å være "Hello world - C is dangerous!". Hvor mange tegn blir skrevet ut nå? Forklar hva som skjer. Skriv så ut `sizeof(str)` med ulike strenger i `str` og se om du finner noen forskjell. 
       * Opprett en variabel `int strsize=20`. Endre initialiseringen av `str` til `char str[20]={'H','e','l','l','o',' ','w','o','r','l','d','!'}`. Forsøk løkken med `sizeof(str)` nå. Noen forskjell? Skriv også ut `sizeof(str)` igjen, og forsøk med ulikt innhold i strengen. Hva er forskjellen på det `sizeof` returnerer nå?
       * La funksjonen `c_strings` returnere `str` (du må da endre returtype til `char*`). I `main` skriv ut `sizeof(c_strings())`. Er størrelsen alltid den samme? Hva har skjedd? Kompilatoren har kanskje skrevet ut et hint for deg.
       * Forsøk å skrive ut det `c_strings` returnerer, i `main`. Er strengen der? Hvis ja, Lagre pekeren som returneres fra `c_strings` i main (`char* str1=c_strings()) og kjør så `stackmess`, før du igjen skriver ut. Er strengen der nå? Verifisér at adressen du leser fra er den samme, både i main og i `c_strings` og forsøk å forklare hva som skjer.
       * Tilbake i `c_strings`, Endre løkken til å la `int i` løpe fra 0 til `sizeof(str)+5`. Hva skrives ut? Endre videre og la `i` løpe til hhv. `sizeof(str)+100`, `+1000`, `+10000` osv. Hva skrives ut, eller hva skjer? Forklar hvorfor.
       * Plasser en `0` midt i arrayet som initialiserer `str` (feks. erstatt mellomrommet  ' ' med 0). Skriv nå ut `str` både direkte og via løkken som før. Hva skjer?
       * Opprett en peker, `char* str2=str`. Kjør deretter følgende løkke: `while(*str2) cout << str2++[0]; cout << endl;`. Hva skjer? Du skjønner nå hvilken funksjon `0` har i en c-string. Hva mangler i initialiseringen av `str`?

  3. **Type (un)safety**
       * Opprett en funksjon `void type_danger()` som gjør En C-style cast slik: `int i=256; char c=(char)i;`. En C-style cast blir også kalt `type coersion` (*coersion* betyr *tvang*), fordi en variabel tvinges til å overta data fra en variabel av en annen type. Skriv ut hhv. `i` og `c` direkte. Hva skjer? Gjør en c-style cast til, når du skriver ut, der `c` tvinges tilbake til `int`, i det du skriver ut (`(int)c`). Forklar hva som skjer her, hhv. med og uten den cast av c til int. Forklar også tallverdien som skrives ut. Var det som forventet?
       * I samme funksjon, opprett en peker til char, `char* cptr=(char*)&i;`. Skriv ut hhv `(int*)cptr` og `(int)*cptr`. Hva er forskjellen?
       * Endre `i` til 257. Blir resultatet av utskriftene som forventet?
       * Endre det `cptr` peker på, til å være 2, ved å bruke *dereference-operatoren* riktig. Hva blir utskriften av `i` etter dette? Er det som forventet?
       * Endre `cptr` til å peke på `&i+1`. Hvilken effekt har dette på `i`? Er det som forventet?
       * I samme funksjon, opprett en c-string `char str[30]="Noo! C++ is not type safe!";`. Skriv så følgende: `int* iptr=(int*)str;` og så `*iptr=560031065;`. Skriv ut `str` og forklar hva som skjer:-)

Flere oppgaver: Alle oppgavene i kap.3 i læreboken.


## Uke 3: Basics

  1. **I/O**: 
     * Implementer et program som teller ord i C++. Programmet skal kunne kjøres fra terminal og ta imot tekst på `stdin`, og skrive ut antall ord på `stdout`. 
     * Programmet skal kunne kjøres i linux/unix kommandolinje slik: `$cat myfile.txt | wordcount` (der `cat` er et standard unix-program som sender innholdet fra tekstfilen `myfile.txt` til `stdout`. I dette tilfellet går dette videre i en pipe til `stdin` i programmet wordcount, med `| wordcount`). 
  2. **Vector, map eller array**: 
    * Implementer et program som trekker n antall vilkårlige tall, og lagrer dem i hhv. en array, en map og en vector (For map, bruk string som nøkkel, så `s1`,`s2`,`s3`...`sn`) Ta tiden; hva går raskest?
    * I en ny løkke, på n runder, velg et vilkårlig tall i datastrukturen, og endre det til et nytt vilkårlig tall. Ta tiden; hva går raskest?
    * Forsøk med ulike n, for eksempel 100 000, 101 000, 102 000, 103 000, opp til 1 000 000. Plott tiden det tar, for hver av datastrukturene,feks. Excel, pyplot, mathematica, R el., gjerne i samme graf. Er fordelingen lineær? Forsøk å plotte både med og uten den første for-løkken. Er forholdet det samme?
   

## Uke 2: Roulette

Du skal implementere et program som simulerer et antall runder roulette. Målet med programmet er å finne ut (på en helt ikke-matematisk måte) om det at det har kommet samme farge flere ganger på rad, minsker sjansen for at samme farge kommer igjen. Programmet skal ha følgende egenskaper:

  * En variabel/konstant *n* skal bestemme hvor mange runder som skal spilles
  * Vi ignorerer det grønne feltet, og antar at det er 50% sjanse for sort og 50% for rød, hver gang
  * Programmet skal kjøre *n* runder, og hver runde skal det trekkes et tilfeldig tall mellom 0 og 1 der 0 betyr sort, 1 rødt.
  * Det som skal lagres underveis er:
    * Antall ganger hhv. rødt og sort ble trukket, totalt
    * Hvor mange ganger det ble trukket hhv. 1, 2, 3, ... osv. av samme farge etter hverandre (sekvenslengder)
    * **Eksempel**: Hvis det ble trukket [*rød*, *rød*, **sort**, *rød*, **sort**,**sort**,**sort**] har vi 2x sekvenslengde 1, 2x sekvenslengde 2, 1x sekvenslengde 3. 
  * Til slutt skal det skrives ut en ordnet liste over hvor mange ganger hver sekvenslengde forekom

**Praktisk:**

  1. Implementér først programmet i et annet, valgfritt programmeringsspråk slik at du får grep om hvordan algoritmen fungerer. Se gjerne på python-versjonen som er lagt ut på github, under `f1`
  3. Forsøk å skrive det samme programmet i C++
  4. Ta tiden på de to ulike programmene, feks. med `$time python roulette.py` i linux/mac. Noen forskjell?

**Tilleggsfunksjonalitet:**

  * La *n* leses inn som argument fra kommandolinjen

