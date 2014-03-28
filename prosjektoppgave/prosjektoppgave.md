Prosjektoppgave C++, vår 2014
===================================

##Oppgavebeskrivelse:

*Lag et fungerende og brukbart C++ program som du liker tanken på å vise frem.*

##Praktisk

- link til nytt, privat Github-repo med **utkast til prosjektbeskrivelse** i, må legges i ditt eksisterende github-repo  **innen fredag 06.april kl.23:59.** *(senere innlevering spiser av tiden deres)*. Repoet skal kun være delt med meg (alfred-bratterud) og prosjektdeltakerne. Linken skal ligge i en fil `link_prosjektoppgave.txt`. Her skal det kun være én link, ingen ting annet (da kan vi automatisere)

- Prosjektbeskrivelsen skal ligge i filen `prosjektbeskrivelse.md` i det *nye repoet*. I beskrivelsen må dere ha med: 
    1. Beskrivelse av hovedfunksjonaliteten  		       
    2. Tydelige designmål (Hva er fokus - skal det være utvidbart? Skalerbart? Effektivt? Bruke lite minne? Integrerbart? Modulært?)
    2. Avgrensing og mål: Noen minimumsmål (hva *må* med for at dere skal føle dere har "klart det") og noen hårete mål (noe dere ønsker å få til, men som dere venter med til dere har kontroll på minimumsmålene.

- Prosjektbeskrivelsen må godkjennes av meg - gjøres på github.

- Mangler du idéer? Sjekk [ideer.md](ideer.md).

- **Innleveringsfrist (hard):  04.mai 2014 kl.23:59**, da klones alle repoer.

- Som alltid: koden skal ikke deles med noen utenfor gruppen. All publisering og distribusjon av kode blir behandlet som bidrag til juks.

- Dere skal **presentere prosjektet deres** for meg, etter fristen. Dette blir helt uformelt, og dere skal ikke ha noen powerpoint, bare vise det dere har laget. Så snakker vi litt om koden og utviklingsprosessen og takker for i år.



###Generelle krav: 

  * 1 - 3 deltakere pr. gruppe. 

  * Med flere enn 1 deltaker vil hver deltaker kunne *vurderes etter sin commit-logg* på github - altså må dere dele opp i klare ansvarsområder - lag gjerne noen deler selvstendig, andre sammen.

  * Terminalbasert (Linux/Studssh), eller GUI - men da kun via [Qt](http://qt-project.org), [FLTK](http://fltk.org) eller [ncurses](http://www.gnu.org/software/ncurses/). Sistnevnte er et Ascii-basert grafikkbibliotek for å lage old-school grafikk i terminal. Fremdeles veldig nyttig, feks. for bios-menyer etc., men først og fremst gøy og nostalgisk.

  * Koden skal minst kjøre i linux, men bør være portabel mellom mac, windows og linux (med mindre unntak gis)

  * Koden skal bygges med "make" (evt. kjøres via Qt) og dokumentasjonen må tydelig angi alle avhengigheter (biblioteker, filer etc. som må finnes og hvor)

###Vurderingskriterier:
  1. **Helhetsinntrykk av sluttproduktet**: God kode virker! Det er svært vanskelig å gi poeng for avanserte teknikker og godt design hvis ingen ting virker. Et hjelpemiddel her kan være å lage egne test-programmer, som tester hver klasse/modul for seg; da kan man få poeng for det som virker i testprogrammene, selv om helheten sliter litt. Men; det er bedre å lage noe enkelt som virker, enn noe avansert som ikke virker. Har man ikke noe som kjører skikkelig vil man ikke få god karakter.

  2. **Kodekvalitet**.  God og riktig utnyttelse av C++, også med vekt på tydelighet og lesbarhet. Flere abstraksjoner (funksjoner, klasser etc.) gir ofte mulighet for kortere, mer intuitivt lesbar kode. Eksempel på leselig kode;
  ```c++ 
	if(queue->free_slots() > 0)
           queue->insert(request);
  ```
  Her kunne vi godt hatt koden til "queue->insert" inline (direkte under if-testen), og if-testen kunne vært et grisete logisk uttrykk. Men, det er mye mer leselig å bruke en klasse for køen, med en medlemsfunksjon "queue->insert" og å ha en variabel medlemsfunksjon "free_slots". Enda bedre; la `queue->insert` kaste en exception hvis det ikke er mer plass; da kan du bare si `queue->insert(request)` så lenge du passer på at `queue_full_exception` (el.) håndteres enten her, eller på relevant sted lenger ned i call-stacken. Poenget er at det å lese kode skal være som å lese en historie, ikke som å dekode en matematisk formel.

  3. **Programdesign**. Hensiktsmessig bruk av objektorientering, flyt, algoritmer, skalerbarhet, effektivitet etc., avhengig av prosjektets helhet og designmål. God bruk av **Patterns/Idiomer** og **Gjenbrukbar kode** gir plusspoeng.

  4. **Robusthet**. Fornuftig feilhåndtering og ressurshåndtering. Det forventes at normale use-case kan gjennomføres uten kjøretidsfeil. Noen mindre bugs er å forvente, men bør være dokumentert. Tenk på dette som en *alfa release*.

  5. **Dokumentajson**.  Det følger med et gjennomarbeidet dokument med hensiksmessig bruk av diagrammer (minst ett, som viser det helhetlige designet) og tekst, *som gjør prosjektet lett å sette seg inn i*. Koden skal også kommentert godt, dvs. alle deler som ikke er trivielle. Det er ingen spesielle krav til bruk av diagramtyper som UML el., men det er ikke *så* mange måter å tegne klassehierarkier på. Se gjerne på fireworks-diagrammet fra oblig 2 som eksempel.

  6. **Organisering**. Prosjektet er strutkturert ryddig i filer og mapper, som har konsekvente, tydelige navnestandarder. Koden er enkel å finne frem i, installere, og kjøre, på alle støttede platformer. Koden bør kunne kompileres i biter (evt. med delte biblioteker hvis hensiktsmessig), slik at den enkelt kan patches.

  7. **Bonus**. Evt. pluss for Kreativitet eller wow-faktor. Ikke et krav for å få A, men det kan hjelpe.

####Koeffisienter:
Kriteriene over vil bli bli sett i forhold til følgende to faktorer:

- Skop / Omfang
- Vanskelighetsgrad

