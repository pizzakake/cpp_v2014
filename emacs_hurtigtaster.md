Emacs hurtigtaster
--------------------------------

###Tastenavn
  * C=Ctrl
  * M="Meta", vanligvis "Alt", noen steder "Esc"
  * RET="Enter"

C-x betyr da `Ctrl-x`, `C-x C-c` betyr `Ctrl-x Ctrl-c`. Man taster dette ved å holde ctrl inne, så trykke x, så c

###Basics
Save: 	  `C-x C-s`
Exit: 	  `C-x C-c`


###Minibuffer
"Minibuffer" er det lille tekstfeltet neders i emacs, der du "snakker med" ulike emacs-kommandoer. Her kan du feks. oppgi filnavn for lesing/skriving filer, og mer info til kommandoer som søk/erstatt etc. **OBS:** Når minibufferen er aktiv, vil den mase på deg om å få input. For å avbryte kommandoen i minibuffer, bruk `C-g`

###Klipp ut, lim inn, merk
  * For å "klippe ut" en hel linje: `C-k`. Linjen havner i en "kill ring (derav 'k')", dvs. at du kan gjøre dette flere ganger etter hverandre for å dytte flere linjer inn i ringen.
  * For å "lime inn" det som ligger i kill-ring: `C-y` ('y' for yank)
  * Merking av ord og linjer skjer ved å "sette et merke" med `C-space`, og så bruke piltastene. Når du har merket noe, vil "Kill" og "Yank", hhv. klippe ut, og limE inn det som var merket.
  * For å avslutte merking (unset mark), `C-space space`
  * For å "kopiere" noe merket, uten å klippe ut: `M-w`

###Navigering i et dokument
Emacs har linjenummerering på som standard. På statuslinjen nederst står det "Lx" der "x" er et nummer, som er linjenummeret du står på.	    

  * Hopp til slutten av en linje: `C-e`
  * Hopp til begynnelsen av en linje: `C-a`
  * Hopp ett ord frem, eller ett ord tilbake: `C-pil høyre` / `C-pil venstre`
  * Gå til et linjenummer: `M-x gg`. Du blir tatt til minibuffer og bedt om å oppgi et linjenummer. Du hopper da til det linjenummeret du tastet inn, når du trykker enter.

###Vinduer	
  * Dele "vinduet" du står i i to, vertikalt: `C-x 3`
  * Dele vinduet to, horisontalt: `C-x 2`
  * Nullstille, til kun ett vindu: `C-x 1`
  * Skifte til neste vindu: `C-x o` (Denne kommandoen kan du også bruke for å hoppe ut av "minibuffer")

###Filbehandling
  * Åpne en fil, mens du er inne i emacs: `C-x C-f`. Du blir tatt til minibuffer, og kan der oppgi sti/filnavn. Finnes ikke filen, blir den "opprettet" (dvs. det blir laget et tomt emacs-vindu for den, men selve filen blir først opprettet i filsystemet når du har skrevet inn noe, og lagrer med `C-x C-s`)
  * Skrive ut en "buffer" (dvs. et vindu med tekst i) til en (annen) fil: `C-x C-w`. Du blir tatt til minibuffer og bedt om å oppgi filnavn
  * Flere filer kan være åpne i emacs samtidig. For å skfite mellom åpne filer (buffere): `C-b`. Du kan da skrive navnet på bufferen (filnavenet), eller trygge `tab` for å få opp en buffer med liste over åpne buffere. I denne listen kan du bruke piltastene til å navigere deg frem til filen du ønsker. Når du trykker `RET` skifter du til bufferen kursoren står ved.

###Kompilere:    
  * M-x (Tar deg til "minibuffer")
  * skriv "compile", Enter	
  * Nå vil det i minibufferen stå forslag om kommando ("make -k"). Her kan du i prinsippet putte inn "g++ myprogram.cpp -o mypgorgram", men det er enklere å la den bruke make. Syntaksen er da "make mypgoram", som betyr nøyaktig det samme som "g++ myprogram.cpp -o myprogram"
  * Jeg har laget hurtigtast for dette, til "C-c RET". For å endre hurtigtaster, farger elle r aaaaalle mulige andre ting i emacs kan man skrive inn "elisp"-kommandoer i fila `.emacs`. Denne ligger ofte rett i hjemmeområdet `~`. Mer om dette feks. [her](http://www.gnu.org/software/emacs/manual/html_node/elisp/Key-Binding-Commands.html)


###Mer info:
Bruk google "Emacs key bindings", eller se feks. [her](http://wttools.sourceforge.net/emacs-stuff/emacs-keybindings.html)