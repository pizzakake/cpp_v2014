#Idéer til prosjektoppgaver. 

##Et spill, en animasjonsfilm eller en simulering

### Spill
PacMan? Tetris? Snake? Mario-klone? Rogue-like? Rollespill? Sjakk? Poker? AngryBirds? Asteroids? Ja det kan du!

  * Med A.I.? 
  * Multiplayer over nett?
  * Automatisk generering av brett/labyrinter etc.?
  * Dialogbasert?

**Utfordring:** Bruk fysikkmotoren [Bullet](http://bulletphysics.org/) til å lage 2D-fysikk på grafikkelementene.

### Animasjonsfilm
Hvis du heller vil lage en animasjonsfilm kan du godt det og. Da kan du bruke mange av de samme elementene som i et spill, men ha mindre fokus på interaksjon med bruker og mer fokus på det som skjer på skjermen.

### Simulering
Da jeg tok første javakurs på blindern fikk vi utdelt et program med et enkelt GUI bestående av masse små ruter, som kunne være enten blå, røde eller grønne. Vi skulle lage logikken og simulere populasjoner av "Foxes and Rabbits". De røde rutene var "Foxes", de blå var "Rabbits". Når en blå rute var i nærheten av en rød, ville det være sjanse for at reven spiste kaninen. Når ruter av samme farge var i nærheten av hverandre var det sjanse for at de ville fomere seg. Revene måtte spise kaniner for å overleve, og kaninene måtte muligens også ha mat (husker ikke). Man startet simuleringen med et visst antall av hver, og målet var å finne ut hva som skulle til for å få en stabil populasjon; den ville variere mye, men med riktige parametre ville det aldri bli tomt for rever og kaniner. Så ble sykdom introdusert; en syk rev ble grønn, og en grønn rev kunne smitte en annen. Med sykdom var det mye vanskeligere å få stabile populasjoner. Andre faktorer kan være årstid, alder etc.

Dette er morsomt, men også en teknikk som brukes i virkeligheten for å simulere populasjonsvekst, økonomier etc. Se eksempel på en [matematisk modell av rever og kaniner her](http://www.illustrativemathematics.org/illustrations/817); en simulering kan være en fin måte å enten oppdage slike modeller på, eller å verifisere dem "eksperimentellt". For eksempel kan du "på baksiden" av et GUI skrive ut antall av hver populasjon, "dag for dag" og så kan dette plottes for å se om det stemmer med en matematisk modell.

### FLTK-grafikk
Dere kjenner FLTK - det er enkelt å komme i gang med og standard-compliant. FLTK har også støtte for [keyboard- og mus- events](http://www.fltk.org/doc-1.1/events.html), så du kan styre grafikk med piltaster, bruke drag'n drop etc.

### Qt-grafikk
Qt er det mest fullverdige (portable) GUI-rammeverket vi har for C++. Qt har alt fra webkit-browser objekter, 2D- og 3D-grafikk med OpenGL, vektorgrafikk, event-lyttere for mus/tastatur etc., asynkron kjøring i paralell eller "concurrent" you name it. Litt mer å sette seg inn i, og litt "alt eller ingenting", siden alle Qt-klasser nesten bare har Qt-medlemmer, men godt dokumentert. 
     

### ncurses-grafikk
Hvis du ønsker mer erfaring med ren, klassisk C og liker terminalbasert grafikk vil ncurses være riktig for deg. Her kan du lage vinduer med knapper, skygger, farger og rammer, men alt er basert på ascii.

## Musikk
  * **En enkel synthesizer** - ta lyd gjennom ulike filtre (frekvensendringer, fouriertransformasjoner etc.). La det være et GUI der det er mulig å koble ulike filte sammen for å få ulike lydeffekter.
  * **Beatbox:** Lage beats med samples? Jeg har sett veldig enkle lydprogrammer, der man har flere "lag" av lyder, som bare spilles av med ulike intervaller, og det hele kjører i loop.


##Anti-Cheat
*Et program som analyserer et antall c++-programmer, og avgjør hvor mye de likner på hverandre.*

Det å avgjøre om to programmer er "like" er et matematisk dypt problem. Men finnes det noen forholdsvis enkle algoritmer man kan bruke for å avgjøre om ett program er en modifisert kopi av et annet?
Programmet vil gi en score til hvert av programmene i et utvalg, som sier hvor mye det likner på de andre programmene.
Programmet bør ikke la seg lure av at funksjoner, variabler og klasser har endret navn, skiftet rekkefølge etc., og kommentarer bør ignoreres helt.
Programmet kan løses med eller uten GUI, men en form for grafisk representasjon av resultatene, som feks. stolpediagrammer, er en fordel.
Programmet bør ha et design som gjør det lett å utvide med støtte for flere språk, som php, java, python etc.

##Texas Holdem
*Pokerklient med AI-spillere*

Det mest spilte pokerspillet er Texas Holdem. Mitt siste år på bachelor lagde jeg en pokerklient, og to kunstige pokerspillere; en random-player, og en som spilte etter strategien "Kill Phil" (fra en bok). Man kunne sette sammen et bord med vilkårlige kombinasjoner av disse spillerne, og kjøre simuleringer, men også ha med menneskelige spillere som spilte via et GUI. Fokus i et slikt prosjekt må være et design som gjør det lett å skrive nye strategier, og evt. å gjøre det mulig å spille over nettverk.

##Minimal webserver - fra scratch
*En webserver med kun det nødvendigste av funksjonalitet kan bli veldig liten og rask*

En webserver med full støtte for hele HTTP-protokollen er et stort beist. Men en veldig stor del av innholdet på nett kunne helt fint blitt levert kun med støtte for GET. Browseren vil da sende en http-request (en tekst-streng) over port 80, der den spør om en fil, og alt webserveren trenger å gjøre er å finne fila, og sende innholdet over en port.

HTML- og CSS-filer kan sendes "As is" - de kan også inneholde javascript og dermed bli pene jquery-baserte sider.

Dynamisk innhold kan fint også lages - men da skal hver side genereres av et eget C++-program, som er kompilert separat, og dynamisk linket med webserveren (evt. lastet inn under kjøretid med runtime-linking). Dersom det feks. spørres om fila "mydomain.com/myDynamicContent1" skal det finnes en kompilert, og liket C++-klasse kalt "myDynamicContent1" (feks. en subklasse av "dynamicContent"), som har en metode som heter "string handle(request r)". Denne tar et request-objekt som argument - og returnerer en HTML-streng. I request-objektet vil typisk alle get-variable ligge, gjerne som en key-value struktur.

Designmål: Minimal, super-rask webserver, kun med støtte for de essensielle tingene.

*Tips:* Bruk netcat / nc i linux, for å lytte på en port direkte i terminal. Med kommandoen `nc -l 8080` (Eller `netcat -l 8080` på noen distroer) vil alle requests til port 8080 skrives ut til terminal. I en browser kan man da skrive `http://127.0.0.1:8080/myFile.cpp?var1=val1&var2=val2`. Da vil HTTP-requesten skrives ut i terminalen der netcat kjører, slik at man ser hva man må forvente i webserveren.

### Støtte for RESTFul API 
Ajax-applikasjoner bruker gjerne javascript til å hente innhold som JSON, fra en egen API. Den mest "riktige" måten å lage API på i HTTP, er RESTful, der man bruker HTTP-funksjonene `GET`, `POST`, `UPDATE`, `DELETE` til "det det høres ut som", og bruker `uri'er` til å aksessere data. For å kunne lage en RESTFul API må det da finnes en måte å mappe "filstier" til funksjoner på. Dette er en utrolig nyttig ting, som jeg ikke har sett for C++. [Les mer her.](http://en.wikipedia.org/wiki/Representational_state_transfer) og se eksempel fra node.js [her](http://coenraets.org/blog/2012/10/creating-a-rest-api-using-node-js-express-and-mongodb/)

##Minimal, portabel markdown-reader - med WYSIWIG. 
*Når man dobbeltklikker på en .md-fil bør den komme opp ferdig rendret, lynraskt, på samme måte som en PDF, men i et minimalt vindu uten dill. Hvis man "låser opp" dokumentet kan man redigere det direkte, i samme vindu, og lagre det tilbake som markdown*

Det finnes mange markdown-programmer tilgjengelig på nett, men flere av de jeg har sett tolker om markdown til HTML, og bruker så feks. webkit til å rendre dette. Det er en utrolig teit omvei! Med Qt kan man lage noe veldig lightweight som gir en pen rendering av markdown direkte i et vindu. Det finnes imidlertid mange open source markdown-readere, så man må da gjøre en tydelig egen vri på programmet.

- Mål: Svært lite og svært raskt
- Ingen omvei via HTML, men direkte fra MD til en pen visning i vindu
- Mulighet for redigering i og live-rendering *i samme vindu*. Man vil da ikke skrive markdown-syntaks i dette vinduet, men bruke hurtigtaster som ctrl-f for fet, ctrl-i for kursiv. Dette oppfører seg da som en vanglig tekst-editor, men det tolkes direkte om til markdown bak kulissene, slik at når man lagrer er det fremdeles bare et .md-dokument
- Støtte for bilder, linker etc. kan bygges inn i trinn - rekker man ikke alt er det helt OK, bare man da har en løsning det er lett å bygge videre på.


## Andre ting:
  * En kryssplatform native-app for android og iphone (Kun Qt som kan dette)
  * Kryptert dagbok
  * Et tegneprogram. Enkelt, med pikseltegning, eller mer avansert med vektorgrafikk (bezier-curves)
  * Har du flere idéer du ikke trenger selv? Send dem inn så hekter vi dem på så andre kan bruke dem.
