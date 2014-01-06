Oppgaver, C++ 2014
===========================

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

