
Obligatorisk oppgave 2: Fyrverkeri
========================================

*Effektiv kode med C og C++ vår 2014*

**Innlevering:** 

  * En mappe kalt "oblig2" må ligge i samme github-repository som sist, innen **21.03.2014 kl.23:59**
  * Mappen kan være tom, men må legges ut 1 uke før den endelige fristen, for at jeg skal kunne sjekke at alle er med, og på github.
  * Det ferdige prosjektet må ligge i den samme mappen på github inen **28.03.2014 kl.23:59**

  * Det er tre oppgaver, der alle skal løses.

**Generelle retningslinjer:**

  * Det er lov å snakke med hverandre om løsningen, men det å dele kode med andre, på noen som helst måte, blir betraktet som juks. Det er du alene som skal skrive koden, og du skal kunne redegjøre for innholdet.
  * Spesielt er det viktig at ingen åpner sitt github-repository for noen andre enn meg (alfred-bratterud)
  * Manglende innlevering gjør at man mister muligheten til å få karakter i kurset, med mindre man har *fått innvilget utsettelse før fristen.* 
  * Man vil få tilbakemelding på det man har gjort, og kan da evt. få beskjed om ting som må endres, for at oppgaven skal bli godkjent. 
  * *Alle steg i koden som ikke er helt trivielle skal kommenteres*

## 1) Implementasjon av fyrverkeri

I mappen for oblig2 ligger det det et ferdig designet klassehierarki for et fyrverkeri, laget i et lite animasjonsrammeverk bygget på [fltk](http://www.fltk.org). Du skal nå lage implementasjonen til dette fyrverkeriet. Klassene er dokumentert i [klassedokumentasjonen her](./klassedokumentasjon.md). Du skal gjøre følgende:

  1. For alle .h-filene som trenger å implementeres (du må finne ut hvilke), må det lages en `.cpp`-fil med samme fornavn. I tillegg skal det være en fil `fireworks.cpp` som skal inneholde `main`. Denne fila skal kompileres til `fireworks` og bare opprette et vindu, gjerne i fullskjermmodus, og starte et fyrverkeri i vinduet.
  2. Du skal ikke forandre header-filene! De har svakheter, men du må jobbe med de som de er (svakhetene skal du skrive noe om i neste oppgave)
  3. Prosjektet skal kompileres med en make-fil som må lages, ved å skrive `make fireworks` eller også bare `make` (begge deler skal funke)
  4. Make-fila skal kompilere alle klasser hver for seg, som `.o`-filer og deretter kompilere `fireworks.cpp`, der `.o`-filene linkes inn med statisk eller dynamisk linking.
  5. Alle kompilerte filer skal bli borte når man skriver `make clean`. 
  6. Koden må fungere på ubuntu, og kompileres med siste versjon av `gcc`. 

Du kan skrive all den koden du mener du trenger, men forsøk å være konsis, uten at det er noe mål i seg selv å få det spesielt kort.

**Krav til fyrverkeriet:**

  1. Som et minimum, forsøk å få fyrverkeriet til å likne på [dette](https://www.dropbox.com/s/shw2mqbf2qbjn03/fireworks1.mov)
  2. Følg ellers retningslinjene i oppgavene om fyrverkeri fra forrige uke, mtp. farger og bevegelse i dottene. Spesielt, forsøk å få de ulike dottene til å ha litt ulik farge, men forsøk også å få hver rakett til å ha overvekt av en farge; noen litt røde, noen litt blå, noen litt grønne etc.
  3. Hvis du ønsker kan du variere og eksperimentere, og la fyrverkeriet bestå av feks. stjerner, i stedet for dotter, ha ytterligere effekter som at "dottene" roterer el., men det skal være "prinsipielt det samme" fyrverkeriet.

## 2) Kortsvarsspørsmål
Du skal svare på følgende spørsmål, i en fil `answers_to_questions.md`:

  1. En del av klassene inneholder en del `protected` datamedlemmer. Er dette lurt? Nevn noen fordeler og ulemper, og hvordan dette kunne vært gjort anderledes for å unngå ulempene.
  2. Anta at vi ønsket å implementere fyrverkeriet med et annet grafikkbibliotek, `fancyGraphics (FG)`. Hva kunne vært gjort anderledes i designet for at dette skulle kunne blitt gjort enklere?
  3. Basert på ditt forrige svar; hvis du skulle laget ett eller flere "namespaces" i dette prosjektet, hvilke skulle det vært? Hvilke filer skulle vært med i hvilket namespace og hvilke filer skulle hatt `using namespace ...` for de ulike (hvis flere) namespacene?
  4. Klassene `animated` og `animation_canvas` legger opp til polymorfi. Kunne `animation_canvas` vært implementert med templates i stedet? Hva ville vært fordeler og ulemper?
  5. Bortsett fra det du har diskutert, ser du andre svakheter i designet, eller andre ting du ville gjort anderledes?

## 3) Implementasjon av egen animasjon

I tillegg til fyrverkeriet skal du lage en egen animasjon, som bruker det samme animasjonsrammeverket, dvs. `class_animated` og `class_animation_canvas`. Du står fritt til hva du vil lage her, og det trenger ikke være spesielt fancy. Målet er å vise at du forstår hvordan man skriver og bruker *gjenbrukbar kode*. Det stilles følgende krav til animasjonen:

  1. Det skal ikke være et nytt fyrverkeri
  2. Det må være minst tre elementer som animeres
  3. Din animasjon skal kunne bygges med `make custom` og kjøres med `./custom`


#Lykke til!