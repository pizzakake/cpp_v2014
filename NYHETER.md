#NYHETER

**04.04.2014: Siste forelesning lagt ut:**
Da er siste forelesning gjennomført og lagt ut. Jeg har også lagt ut Qt-koden jeg viste i forelesningen, men jeg la til en progressbar som endrer seg med antall tegn du skriver inn i tekstboksen. Jeg lot denne abonnere på signalet fra MainWindow (gjorde koblingen med click'n drag), som fyrer av hver gang teksten endres, og sender med "character count". La også til en enkel if-test for å sjekke om det var for mange tegn i boksen; hvis det er det blir teksten rød. Se [mainwindow.cpp](./f11_qt/Qt_demo1/mainwindow.cpp) for detaljer. 

*Vi sees senest til presentasjon av prosjektene, men jeg vil uansett takke for et bra semester! Det har vært mange gode spørsmål og gode resultater så langt, og jeg gleder meg til å se prosjektene deres!*

**PS:** For å kjøre koden, last ned og installér Qt open source-versjon, fra [qt-project.org](http://www.qt-project.org). Når dette er installert kan du dobbeltklikke på `.pro`-filen (prosjektfila) fra Qt-prosjektet i mappen [f11_qt](./f11_qt). Deretter blir du spurt om å konfigurere prosjektet (dvs. koble opp mot kompilator) noe du bare kan si OK til. Deretter, "press play".


**28.03.2014: Grupper til prosjektoppgave**:
Prosjektoppgaven er nå lagt ut under [prosjektoppgave](./prosjektoppgave). Les oppgaven, dann grupper og opprett et nytt github-repository for prosjektet. Der skal dere legge ut et utkast til prosjektbeskrivelse innen neste søndag. Utkastet er ikke bindende, og det er ikke meningen at arbeidet skal starte før uken etter, men vi trenger tid til å gå igjennom forslagene for å kunne godkjenne dem, evt. komme med tilbakemeldinger, tips eller råd.

**PS:** Hvis du ikke har noen å være på gruppe med, men ikke ønsker å jobbe alene, send meg e-post! 

Ellers er dagens forelesningsnotater lagt ut, med informasjon om prøven, samt noen viktige patterns/idiomer. 

God helg!

**27.03.2014: Generell utsettelse på oblig 2**:
Det er såpass mange som har behov for utsettelse på oblig2 at jeg velger å gi en generell utsettelse til alle. Ny frist er *onsdag 02.04.2014 kl. 23:59*. Dette gjelder alle, men for dere som blir ferdige før fristen er det naturligvis bare å committe til github i morgen. Jeg har ingen egen eksamen førstkommende onsdag så jeg vil være tilstede på lab for å hjelpe de som trenger det med innspurten.

Lykke til!

**24.03.2014: FLTK, Makefile mm.**

**FLTK og Make:** Når man skal kompilere et program som bruker FLTK må kompilatoren vite hvor FLTK-bibliotekene ligger. Hvis du bruker den ferdige ubuntu-VM'en jeg har laget, og beskrevet [her](./ubuntu_faq.md) vil det være tilstrekkelig med ett linker-argument til g++ for å få til dette; hvordan det da gjøres ser du i Makefila som ligger i mappen [fltk_basics](./fltk_basics). 

Hvis du *ikke* bruker den VM'en jeg har laget, vil det variere hvor FLTK-bibliotekene ligger. FLTK har da laget et script, "fltk_config" beskrevet [her](http://www.fltk.org/doc-1.1/basics.html) som kan hjelpe deg å kompilere med riktig linking. Dette er imidlertid også litt å sette seg inn i. For å hjelpe dere har Alf laget en makefil som bruker "fltk_config", og delt den med dere. Den heter "Makefile" og ligger i mappen [oblig 2](./oblig2). Denne makefila kan dere bruke, eller evt. bare se på for å få hjelp til å lage en egen.

**Anbefalt fremgangsmåte for oblig2**
For de som fortsatt strever med å komme i gang med programmeringen av fyrverkeri, anbefaler jeg denne fremgangsmåten:
  
  1. Sjekk at du har installert FLTK riktig, vet å bygge og kjøre [fltk_basics](./fltk_basics)
  2. Lag fireworks.cpp, og: 
    * Opprett et FLTK-vindu
    * Opprett en FL_Box direkte etter vinduet. Hvis du sender med en tekststreng til boksens konstruktør, skal du se denne teksten på skjermen. 
    * Opprett et animation canvas i stedet for boksen. Animation-canvas tar en tekststreng som argument (const char* l), som skal sendes videre til konstruktøren til FL_Box, i konstruktøren. Denne teksten skal da vises på skjermen.
    * I animation-canvas' draw-funksjon, forsøk å tegne sirkler med `fl_pie`. Denne tegnefunksjonen vil bare fungere inni en FLTK-widget, men siden animation-canvas arver FL_Box vil det gå bra.
    * Når du har kommet så langt kan du flytte tegnefunksjonen inn i klassen `dot` og så opprette dotter direkte i animation-canvas'et, ved å lage animated-pekere til dem, og putte disse inn i vectoren `parts`. Animation-canvaset sin draw-funksjon skal nå i stedet for å tegne, bare inkrementere alle `parts` (dvs. dottene). Dottenes operator++ (som er prefiks-inkrementering) skal igjen kalle "draw" i dotten, som da skal resultere i at dotter blir tegnet.


**22.03.2014: Ekstra lab på mandag**

Vi setter opp en ekstra lab mandag 24.mars, kl. 12:30 - 16:00. Vi har bedt om å få det vanlige rommet (PH451) som er ledig da. Vi regner med det går i orden (i verste fall flytter vi til datatorget.). Jeg vil være til stede deler av tiden, Alf hele. Fokus vil være på FLTK og oblig2.

**19.03.2014: Lab i dag**

**Kontra:** Alf har blitt syk og kan ikke komme i dag. Selv har jeg hjemmeeksamen kl.12. Dere får hjelpe hverandre så godt dere kan, og bruke dokumentasjonen som er lagt ut. Jeg kan svare på spørsmål via e-post etter kl.12.

På lab i dag blir det jobbing med oblig2, ~~Alf vil være tilstede for å hjelpe dere~~. For de som enda ikke har gjort oppgavene om FLTK anbefales disse. Se også forrige nyhetspost for hjelp til oppsett av FLTK.

**OBS:** Minner om at oblig2 skal leveres i *samme repository* som oblig1. Du skal altså kun ha ett repository for kurset, og der skal det ligge en mappe for oblig1 og en for oblig2. Da slipper vi å levere inn to linker via fronter.

**17.03.2014: Hjelp til FLTK i ubuntu**

Jeg har nå lagt ut en del stoff om hvordan man bruker FLTK i ubuntu, under [ubuntu_faq.md](ubuntu_faq.md). I tillegg er det lagt ut en beskrivelse, trinn for trinn, av hvordan man lager en fungerende ubuntu-vm, med et lettkjørt desktopmiljø (lubuntu), hvordan man får inn alle kursets programmer *og fltk*. I tillegg har jeg lagt ut link til en ferdig slik VM, som kan lastes ned, for de som er lei av konfigurering. Det er også laget en mappe med et enkelt FLTK-prosjekt som bygger fint i denne VM'en. Prosjektet består bare av en fil og en Makefile, som når det er bygget åpner et vindu og tegner tre dotter. Du finner dette i mappen [fltk_basics](./fltk_basics). 

**OBS:** Alf har laget en egen guide for å legge inn bibliotekene fra læreboken ([fyrverkeri.md](fyrverkeri.md)). Disse er *ikke nødvendige for å løse obligen og skal bare brukes for å løse oppgavene i boken*. De kan også være nyttige for å løse oppgavene om fyrverkeri, men er ikke nødvendige der heller. 

Lykke til!

**14.03.2014: Oblig 2 ute!**

Oblig 2 er nå lagt ut, under [oblig2](./oblig2/oblig2.md). Mappen `oblig2` består av oppgavetekst, klassedokumentasjon (tekst og PDF-figur) og alle header-filene du skal implementere. Vi kommer til å legge ut mere materiale for å hjelpe dere i gang med det praktiske rundt FLTK. 

*Lykke til!*

**11.03.2014: Lab i morgen og oblig 2**

I følge semesterplanen kommer Oblig2 ut på fredag. Oppgaven vil være å lage fyrverkeri. Dere vil få utdelt header-filer til et lite klassehierarki, der dere skal lage implementasjonen. Fyrverkeriet dere skal ende opp med vil se ut ca. [sånn som dette](https://www.dropbox.com/s/shw2mqbf2qbjn03/fireworks1.mov). 
  * Oppgaven skal løses med grafikkbiblioteket FLTK. Lab'en i morgen vil derfor igjen handle om FLTK, og Alf vil være til stede og hjelpe dere (jeg har nok en deleksamen). Jeg legger ut noen oppgaver som går ut på at dere skal forsøke å lage fyrverkeri allerede nå. 
  * Til oblig2 vil dere måtte implementere løsningen dere får utdelt, men det vil være en stor fordel å ha prøvd litt på egenhånd først. 
  * I tillegg til implementasjonen vil dere bli bedt om å identifisere noen styrker og svakheter i designet (det er med vilje ikke perfekt) og foreslå alternativer på ulike punkter. Det vil da være nødvendig at dere har kontroll på arv, polymorfi og abstrakte klasser. Oppgavene fra boken som ble lagt ut forrige uke vil være nyttige her.

**PS:** Dere gikk glipp av en forelesning om templates på fredag. Dersom jeg ikke rekker å dekke dette på fredag vil bli gjort tilgjengelig senere, som videoforelesning; dere trenger ikke kunne dette for å løse oblig2.

Lykke til i morgen - vi sees på fredag!

**07.03.2014: Forelesning avlyst i dag**

Dagens forelesningen er dessverre avlyst pga. sykdom. 

**04.03.2014: Lab i morgen**

Det viser seg at det er del som må gjøre mer med oblig 1. I tillegg har jeg hjemmeeksamen til i morgen kl.12, så vi utsetter gjennomgang av oblig enda en uke. Da vil dere også ha mottatt kommentarer fra rettingen og ha fått utdelt Oblig 2. I morgen legger vi opp til at dere jobber med oppgaver i arv og polymorfi (lagt ut), som vil være svært viktig å ha kontroll på i oblig 2. Jeg kommer ikke til å være der, men Alf Walla kommer kl.08:30 og vil hjelpe dere. 

Oppgavene bruker et grafikkbibliotek som fungerer for de tre store platformene (Windows, Mac, Linux) og vil gi dere muligheten til å teste grafikkprogrammering i C++. Dette kan være et nyttig hjelpemiddel i programmeringen og jeg anbefaler på det sterkeste at dere dukker opp, gjør oppgaver og spør Alf straks dere står fast. 

PS: Fint om så mange som mulig tar med boken, slik at de som ikke har kan låne.

Lykke til - vi sees på fredag!

**21.02.2014: VIKTIG - Status Oblig 1**

Alle som har levert oblig 1 på godkjent måte skal nå ha fått en fil lastet opp til sitt github-repo. Filen heter `studnr_sxxxxxx` og inneholder bare en setning om at obligen er bekreftet mottatt. **Alle må nå:**
  * Sjekke at riktig studentnummer er skrevet inn. De er lagt inn atuomatisk, men basert på en manuell sjekk, på grunn av begrensninger i fronter. 
  * Dersom filen er kommet inn med riktig nummer, kan du slappe av og fortsette med oppgaver (dere gjør vel ikke annet?)
  * Dersom filen er kommet inn med *feil studentnummer* eller dersom du mener å ha levert obligen, men *ikke har fått noen fil*, [send meg e-post ASAP](mailto:alfred.bratterud@hioa.no)
  * Tilbakemeldinger på oblig1 kommer så snart de er klare, og vil bli pushet opp til ditt repo.
  
Vi sees på onsdag!

**16.02.2014**

**Undervisningsfri denne uken**. I henhold til [semesterplanen](http://www.hioa.no/Studier/TKD/Undervisnings-og-semesterplaner/Semesterplan-tekniske-studier-2013-2014) for dette semesteret er det undervisningsfri denne uken. Jeg anbefaler alle å jobbe med de oppgavene som er lagt ut, og de det er referert til fra boken. Flere oppgaver og kodeeksempler kommer, så følg med og hold C++ ved like. Vi sees onsdag 26.februar!

**12.02.2014**

**Kun lab i dag**. Jeg har blitt smittet av datteren min som var syk hele forrige uke, så jeg holder meg hjemme. Det blir derfor kun lab i dag. Stud. ass. kommer som normalt, og vil hjelpe dere. Dersom dere fremdeles har spørsmål etter lab'en, ta kontakt på e-post så skal jeg forsøke å hjelpe så godt jeg kan. Kodeeksempler fra fredagens forelesning blir lagt ut, og gjennomgått senere. 

Satser på at vi sees på fredag - Lykke til!

**03.02.2014**

  * Forelesningsnotater fra forelesning 3 og 4 er lagt ut, med kodeeksempler fra f.4.
  * Obligen er også ute - minner om at:
    * Obligen er **Individuell**
    * Obligen skal leveres via et privat github-repo som kun du og jeg (alfred-bratterud) har tilgang til.

**17.01.2014**

Forelesningsnotater fra i dag, og en hel del nye oppgaver er nå lagt ut. Jeg håper så mange som mulig kan løse en del av (eller alle) oppgavene til onsdag, slik at jeg da kan gå igjennom noen av dem!

**09.01.2014**

Minner om at det *ikke er forelesning i morgen*, fredag 10.01. Dette ble informert om i første forelesning mandag, og står i forelesningsnotatene (f1). Fra og med neste uke er det forelesning/lab, hver onsdag fra 08:30 - 12:15, og ordinær forelesning hver fredag, fra 08:30 - 10:15. Vi sees på onsdag - flere oppgaver kommer før det, i mellomtiden:

  * Registrer studentkonto på github ([https://github.com/edu](github.com/edu))
  * Post link til din github-bruker på fronter
  * Skriv roulette-programmet i et språk du kan godt
   	* Kult hvis du legger dette på github - dette kan du gjerne legge i et offentlig repository, slik at andre også kan se det, og sammenlikne. 
  * Deretter, forsøk å skrive et tilsvarende program i C++
  * Deretter, forsøk å skrive en rekordrask versjon i C++. Den som lager den raskeste løsningen får cred, men ikke fortvil hvis du synes dette er vanskelig - det er ikke forventet at dette skal være enkelt; tanken er bare at vi skal ha et konkret case å øve på:-)
       

**08.01.2014**

Jeg blir dessverre ca. 1t og 15 min. forsinket i dag, da jeg må levere i barnehagen. Jeg tar igjen dette ved å bli lenger. Planen for dagen er helt praktisk; å gjøre roulette-oppgaven på github, først i et språk man kjenner, deretter i C++. Bruk tiden frem til jeg kommer til å gjøre dette i et språk dere kan fra før! Evt. forsøk dere i C++; bruk gjerne cplusplus.com.


