Oppgaver, C++ 2014
===========================
## Uke 11: Fyrverkeri
Oblig2 vil gå ut på å implementere fyrverkeri, basert på et klassehierarki dere vil få utdelt. Dere skal bruke `fltk 1.3.2`, som dere finner [dokumentert her](http://www.fltk.org/doc-1.3/index.html). Som en forberedelse til dette, kan disse oppgavene være nyttige, i tillegg til forrige ukes oppgaver:
  * Hvis du har løst forrige ukes oppgaver vil du være i stand til å tegne ulike former i et vindu. Forsøk nå å få en liten fargelagt dott til å bevege seg over skjermen. Gjør dette så ukomplisert og enkelt som mulig.
    * Undersøk de statiske funksjonene `Fl::add_timeout` og `Fl::repeat_timeout` i klassen `Fl`. Bruk gjerne utskrift til terminal til å sjekke at du får til å "fyre av en timeout-event" regelmessig før du begynner å tegne
    * Undersøk de ulike tegnefunksjonene beskrevet i "FLTK Programming Manual", [her](http://www.fltk.org/doc-1.3/drawing.html). 
    * Hvis du tegner en ny dott hver gang et timeout-event fyrer, hvordan får du den "forrige dotten" til å bli borte? Hva vil det si å "flytte" en dott?
  * Få en dott til å flytte seg med en viss hastighet i x-retningen og en annen hastighet i y-retningen. Hastighetene kan være tilfeldig valgt, men bør være innenfor et intervall der man kan se dotten fint når den flytter seg. Du må da gi dotten nye x- og y-koordinater hver gang et timer-interrupt fyrer. 
  * Lag nå mange slike dotter, som alle starter på samme sted, men flytter seg med en tilfeldig hastighet i hhv. x- og y-retningen. Hvordan ser dette fyrverkeriet ut? Hvorfor? 
  * Få en dott til å bevege seg i en gitt retning, der retning er definert ved en vinkel, i radianer. Radianer er vanligvis definert som et reelt tall mellom 0 og 2Pi, men det er enklere å bruke "Tau" som en konstant for 2Pi. Les mer om dette på [tauday.com](http://tauday.com/) og se gjerne videoen. For å finne de nye x- og y-koordinatene basert på vinkelen trenger du å gjøre en veldig enkel beregning som involverer sinus, cosiunus og hastigheten.
  * Du bør nå klare å lage effekten av en enkelt rakett. Eksperimenter med å gi dottene litt ulike farger. Forsøk å få til 
    * Helt rødt, grønt eller blått
    * Alle dotter har ulike, men kun "sterke farger"
    * Alle dotter har ulike farger, men "mest rødt", "mest lilla", "mest gult" etc.
  * Forsøk å få dottene til å få gradvis svakere farge, etter hvert som de beveger seg vekk fra utgangspunktet.
  * Generalisér løsningen. Hvordan får du nå mange raketter til å eksplodere?
  * Forsøk å designe et objektorientert fyrverkeri, med det du mener er et godt design. Når du får oblig2 vil du da være svært godt forberedt :-)

## Uke 10: Arv og polymorfi. 
Oppgaver og drill fra boken, kap. 14. Disse oppgavene bruker grafikkbiblioteket fra [fltk.org](http://www.fltk.org). Biblioteket fungerer for Mac, Windows og Linux, men må lastes ned fra hjemmesidene. For windows/visual studio står det en brukerveiledning i et eget appendix i boken (Appenix D s.1157), mens for Linux og Mac, må du bruke dokumentasjonen på hjemmesidene. Det er alltid litt knot å installere tredjeparts kode - og i seg selv er det en *svært nyttig* øvelse. 
Bruk av dette biblioteket vil også være nyttig for å ha noe å sammenlikne med når vi senere skal bruke Qt, som fungerer svært anderledes. 

## Uke 8-9: Arv, exceptions og operatoroverlasting
Du skal lage et lite system for å registrere brukere "på en nettbutikk". Du skal ikke lage noe web-grensesnitt, eller bruke nettverket, bare ta imot input fra brukeren via terminal. 

  1. **Arv, intro**: Systemet skal støtte to typer brukere; sluttkunder og leverandører. Du skal lage en klasse for hver, "consumer" og "supplier", som begge arver en mer generell klasse "user". Klassen `user` skal ha feltene `firstName`, `lastName`, `email`, `phone`, der alt utenom `phone` er obligatoriske felter. Klassen `consumer` skal ha feltene `org_no` som er et numerisk organisasjonsnummer og `discount`, som er en fast prosentsats, som i utgangspunktet settes til `5.0`. 
    * Lag klassene og opprett 2 ulike brukere av hver type
    * Overlaste strømoperatoren for alle klassene slik at du kan skrive dem ut direkte slik: `cout << user1 << endl`
    * Lag en vector for hver subklasse, og legg inn de to elementene. Lag en funksjon `userlist` som skriver ut alle.

  2. **Arv og exceptions**: Lag et registreringsbilde (bare en løke som venter på input fra `cin`) der man kan registrere seg. Dette skal ligge i en funksjon `user register()`, som returnerer en bruker, dersom registreringen var vellykket.
    * Det første systemet skal be om er om du vil opprette en `supplier` eller en `consumer`. Brukeren må da skrive inn dette som ren tekst. Dersom brukeren skriver noe annet skal det kastes en exception
    * Lag nå "form validation"; utvide systemet slik at det kastes egne exceptions for følgende: 
      * navn som inneholder noe annet en bokstaver, 
      * e-post som ikke inneholder minst en bokstav, fulgt av alfakrøll, fulgt av minst to bokstaver, så et punktum så minst to bokstaver
      * Organisasjonsnummer som ikke er numerisk (ta det imot som en string)
      * Telefonnummer som ikke er 8 siffer (ta det også imot som en string)
    * Lag en egen catch-clause for hver av disse
    * Dersom noe annet går galt, feks. at prosentsatsen er høyere enn 100, skal det kastes en stekepanne (en klasse fryingPan, med valgfritt innhold). Denne skal også fanges.
    * Til slutt, lag en generell catch-clause som fanger alle typer objekter.
    * Endre nå oppførsel i systemt slik at det *blir* opprettet en bruker, selv om telefonnummeret er feil, da bare uten telfonnummer. Dette gjøres når du fanger exception av typen som indikerer galt telefonnummer. For andre typer exceptions skal det bare skrives ut beskjed om at brukeren ikke ble opprettet.
    * Til sist i programmet skal listen av brukere skrives ut.


## Uke 6: Objektorientert programmering
   1. **Konstruktorer og initialisering:** 

      Lag en klasse, `computer` med medlemmene `float cpu_freq`, `float mem_size`, `float disk_size`, `string model`, `int usb_ports` og `char* manufacturer`, for hhv. Cpu-frekvens, minne- og diskstørrelse, midellnavn fra produsent (feks. `Latitude 2410` eller `MacBook Pro`) og produsent (Feks. `Dell`, `Samsung` etc.). 

      * Lag en `public` medlemsfunksjon `string to_string()`, som lager en string med sammendrag av samtlige medlemmer, egnet for utskrift. Uten å lage konstruktorer, instansier et par objekter av denne klassen i `main`, og skriv ut resultatet av `to_string()`. Har medlemmene blitt initialisert? Forsøk å instansiere utenfor main. Får du det til? Hva blir resultatet av `to_string()`?
      * Lag en konstruktor, som ikke tar noen argumenter. I konstruktorens kropp, bruk tilordning for å sette verdi til alle medlemmene (feks. `cpu_freq=2.4`). Kall `to_string()` hhv. *før* og *etter* tilordningene. Er det mulig å skrive ut innholdet før du satte verdier til dem? I så fall, hvorfor er det mulig og hva sier det om initalisering?
      * Instansier en `computer` med og uten konstruktorsyntaks i main (tomme parenteser når du oppretter variablen). Blir det noen forskjell på utskriften? Klarer du å gjenskape en situasjon der instansiering ser identisk ut som en funksjonssignatur? Dette heter [most vexing parse](http://en.wikipedia.org/wiki/Most_vexing_parse) og er et nyttig tilfelle å vite om, slik at du kan gjøre det riktig.
      * Bruk C++ sin spesielle initialiseringssyntaks for å initialisere alle medlemmene, men la tilordningene stå. Blir utskriften som forventet nå?
      * Ser du noen tilfeller der tilordning i konstruktorkroppen er *nødvendig* (det finnes noen)? Beskriv dem, og implementér den enkleste du kommer på (du kan gjerne legge til flere medlemmer om nødvendig).
      * Noen mengder inneholder seg selv. Hva hvis en `computer` kunne inneholde en `computer`? (Mange datamaskiner er virtuelle) Forsøk å få til å ha et computer-objekt som medlem. Pekere og referanser er lov:-)
      * Lag en ny klasse, `computer_manufacturer` og endre medlemmet `manufacturer` i `computer` til å være av denne typen. Lag en annen klasse, `country` og la begge klassene få en konstruktor, som skriver ut en beskjed om at den blir konstruert. 
      * Gi `computer_manufacturer` et medlem `country` og gi begge disse klassene ha et medlem `string name`, som skal bli initialisert av konstruktor, som tar en `string` som argument. Oppdater også `computer` med en konstruktor slik at man kan initialisere med et produsentobjekt. 
      * For alle tilfellene over, sjekk når disse konstruktorene blir kalt. Du må også legge til en `to_string()`-metode i de nye klassene, for å få til utskrift. 

   2. **Destructorer:**

      * Legg til destructorer i alle klassene over. Destructorene skal foreløpig bare skrive ut sitt eget navn. 
      * Instansier en `computer` "i dynamisk minne / free store", med `new`. Få konstruktorene til å kalles, ved å eksplisitt slette elementet.
      * Lag en funksjon `test_destructors` som oppretter en vector med ti ulike `computer`-objekter, og returnerer. Vectoren skal ligge på stack. Blir construcorene og destruktorene kalt? Hvorfor/hvorfor ikke?
      * La funksjonen `test_destructors` inneholde et array av pekere til ti ulike `computer-objekter`, som alle skal ligge i `free store`. Blir destructorene til disse kalt? Hva er forskjellen? Sjekk for minnelekkasjer med valgrind.
      * Lag enda et array, som over, men fyll i stedet inn faktiske `computer`-instanser. Blir destructore kalt nå? 
      * Endre vectoren og arrayet av pekere, slik at pekerne til computerobjekter (og objektene) blir laget før vectoren. Fyll deretter inn disse objektene i vectoren. Lag en setter-metode som lar deg endre ett av medlemmene, og endre noen av medlemmene i vector, og noen i arrayet. Er det de samme objektene? 
      * Gjør som over, men endre vectoren til å være en vector av pekere til computerobjekter. Er det nå de samme objektene? 

## Uke 5: Minne

  1. **Automatisk minne og stack**
     * Undersøk hvor mye plass din maskin setter av til stack.
        1. Se hvor "høyt" du kan gå, ved å lage en rekursiv funksjon `void stackmess(int i)` som kaller seg selv i ganger, før den returnerer. Funksjonen bør lagre en byte på stack før den kaller seg selv på nytt. Kall `stackmess` fra en for-løkke, der du øker "høyden" inkrementellt, og skriver ut høyden dersom det ble vellykket, frem til du får segfault.
        2. Se hvor stort array du kan allokere på stack.
        3. Sammenlikne høyden på rekursjonen, og størrelsen på arrayet. Forsøk å beskriv hva som er sammenhengen mellom disse tallene
    * Lag en funksjon `int* throw()`som skriver lagrer tallet 42 (meningen med livet) 1000 words (32/64 bit) opp i stacken. Returner en peker til dette tallet. Adressen til tallet, og tallet skal skrives ut når den returnerer.. 
    * Lag en ny funksjon, `int* fetch()` som reiser 1000 words oppover i stacken, leser av det den finner der, og skriver det ut, sammen med adressen. Får du `fetch` til å finne igjen tallet? Hvis ikke er det noen som har lurt på hvorfor, før deg. Les denne posten: [Why doesn't the C++ default destructor destroy my objects?](http://stackoverflow.com/questions/2403020/why-doesnt-the-c-default-destructor-destroy-my-objects). Hintet er at C++ garanterer at alle variable har en default "destructor" (vi kan lage egne for klasser), og at denne kalles når variablen går ut av skop. For en peker garanteres det dermed også at destructor kalles, men hva med det som pekes på? 
       * Du får naturligvis lov til å bruke pekere i både `throw` og `fetch`. Du kan også bruke litt farlig (gøy) pekeraritmetikk, når du legger tallet på stack, og når du henter det - det er ikke nødvendig at det ligger nøyaktig på "plass 1000"
    * Når du har fått til `throw` og `fetch`, kjør `stackmess` imellom, og se om du klarer å ødelegge for `catch`.

  2. **Statisk minne** 
     * Initialisér et array på 10 MB hhv. utenfor og innenfor main. Lag en løkke som sorterer innholdet i arrayet, med [std::sort](http://www.cplusplus.com/reference/algorithm/sort/). Ta tiden:  ser du noen forskjell i hastighet? Hvorfor?
     * Hvordan kunne du gått rem for å endre størrelsen på dette arrayet etter at programmet har startet? Hvis du har idéer til hvordan det kan gjøres, prøv!
     * Implementér nøyaktig det samme som over, men denne gangen med en vector. Får du noen forskjell i hastighet? 

  3. **Dynamisk minne (Heap/Free store)**
     * Gjenta eksperimentet fra oppgave 2, som tester hastigheten av sort. Denne gangen, forsøk å sortere et array som ligger allokert på "free store". OBS: Hele arrayet skal ligge på free store, og det er da nødvendig å bruke `new arr[n]`. Før du måler hastigheten, dealloker minnet med `delete arr`. Får du minnelekkasje? Mål deretter hastigheten og redegjør for sammenhengen med hastigheten i de to eksperimentene fra oppgave 2.
     * Lag en kontrollert minnelekkasje, der du forsøker å miste nøyaktig 10 000 bytes, fordelt på 2 500 allokeringer. Bruk valgrind til å verifisere lekkasjen.
     * Lag en heftig minnelekkasje! Dette må du gjøre på din egen maskin (hvis du tør). Forsøk å lage et program som spiser alt det minnet det kan få. Hvor mye får det før du ikke tør å la det kjøre lenger? Merker du noen effekt på systemet? **OBS:** dette må du **IKKE** gjøre på studssh - der er det mange som deler ressursene!
     * **Hvem har ansvar for deallokering?** Lag to funksjoner, `int* create_arr(n)` som oppretter et array av størrelse `n` på "free store" og returnerer en peker dit. Lag en ny funksjon, `void fill_random(int arrsize, int* n)` som fyller arrayet med tilfeldige tall. Lag en tredje funksjon `float average(int arrsize, int* n) som regner ut gjennomsnittet av innholdet i arrayet. Lag en fjerde funkson `float random_average(n)` som kun tar et tall n som input, og bruker de tre foregående funksjonene til å finne ut hva gjennomsnittsverdien av randomfunksjonen er, ved en git `n`. La nå main kjøre en løkke over økende `n` og skrive ut gjennomsnittene. Redegjør for hvor det er riktig å deallokere her. Finnes det alternativer? Er det andre måter å lage disse funksjonene der denne avgjørelsen blir enklere?

  4. **Structer**
     * Lag en kompositt type `struct student{...}`, med felter for navn, alder, studentnummer, evt. andre ting. Bruk passende datatyper. 
       * Verifisér at du klarer å opprette studenter og gi dem navn og alder, for så å skrive ut disse verdiene. 
       * Lag en funksjon `print_student(student s)` for å skrive ut innholdet av et studentobjekt på en pen måte.
       * Lag en ny struct, `struct student_container{...}` som inneholder et array av 100 studenter (ikke bruk pekere). Lag så en funksjon `student_container create_students(n)` som generer et student_container-objekt, fylt med tilfeldig genererte studenter. (Navnene kan du generere tilfeldig fra en liste av 10-20 for- og etternavn, de andre verdiene kan du også sette tilfeldig, eller bare i rekkefølge, for feks. studentnummer). Kjør funksjonen `create_students(n)` 1000 ganger og ta tiden. Hva skjer? 
       * Lag en ny funksjon, `student_container* create_students(n)`. Her skal hvert studentobjekt, og også selve containeren, ligge i "free store". Kjør funksjonen 1000 ganer og ta tiden på nytt. Noen forskjell? Har vi nå fått en bedre løsning? Forklar fordeler og ulemper. Sjekk implementasjonen i valgrind el. for å finne, og fikse eventuelle lekkasjer.
       * Lag en ny funksjon i to versjoner, `void sort_students(student_container)` og `void sort_students(&student_container). Tilbake i løkken som kjører `student_container create_students(n)`, sortér også studentobjektene etter alder, 

*Flere oppgaver:* Oppgavene i kap.27 - disse gir deg kjennskap til mange problemstillinger rundt C-strenger.

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

