# Virtuelle maskiner med ubuntu
Det er veldig fint å jobbe på en egen virtuell maskin i faget. Vi anbefaler da siste versjon av ubuntu (ikke 12.04 LTS). Du kan bruke en hvilken som helst løsning for å kjøre virtuelle maskiner; jeg bruker [virtualbox](https://www.virtualbox.org/). I virtualbox kan du installere ubuntu ved å laste ned iso-imaget fra ubuntu.com, klikke "new" i virtualbox,  og følge installasjonsveiledningen. 

## Installasjon av programmer i ubuntu
Alle programmer i ubuntu kan installeres fra kommandolinje. I faget trenger vi disse:

  * `$ sudo apt-get install valgrind`
  * `$ sudo apt-get install emacs`
  * `$ sudo apt-get install g++`

## Tilgang til lokal VM via SSH
Det fungerer fint å jobbe på en virtuell maskin direkte fra virtual-box, men det har noen ulemper, bla. at mus og tastatur "fanges" og at man ikke kan kopiere og lime inn mellom VM og lokal PC. Det kan derfor være nyttig å jobbe på VM'en via SSH. Dette er kanskje mest aktuelt fra mac, som har et innebygget shell (har man allerede linux trenger man vel ikke en VM), men det vil også fungere med windows, via putty. For å jobbe slik må man legge til et ekstra nettverkskort i VM'en, under *Settings->Network->Adapter2*. 

  * Huk av "Enable Network Adapter"
  * Velg *Attached to: Host-only Adapter*
  * Velg *Name: vboxnet1* eller et annet lokalt, virtuellt nettverk.

Når man vel har gjort dette må man konfigurere sin ubuntu-vm til å hente en IP-adresse på sitt nye nettverkskort. Dette kan man gjøre med `$ dhclient eth1`. Dette vil da bare gjelde til neste gang man starter PC'en; for å få dette til å bli en permanent innstilling må man endre nettverksinnstillingene. 

**OBS:** *Dersom du vet at du ønsker å jobbe på denne måten kan det være en fordel å gi VM'en to nettverkskort i det man oppretter VM'en - da vil ubuntu-installasjonen kunne sette opp dette for deg.*

## Lubuntu - en lettere desktop-løsning
Standard ubuntu med GUI har et fancy grensesnitt som krever mye av maskinen. Det kan derfor være tungt å kjøre denne virtuellt. Heldigvis finnes det mange lettvektsalternativer; feks. [lubuntu](http://www.lubuntu.net) som er en offiselt støttet lettvekter. Du får et fullverdig desktop-miljø, bare mindre fancy. 


## Oppsett av FLTK i Ubuntu

I ubuntu kan fltk installeres som pakke, slik:
> `$ sudo apt-get install fltk1.3` 

Når dette er installert vil `#include <FL/...>` fungere, men du må fremdeles gi beskjed til linkeren om hvor den finner bibliotekene. Det er nå laget en mappe `fltk_basics` som har en makefile, der du ser hvordan dette gjøres. Kort fortalt trenger du å sende med `-L/usr/local/lib -lfltk` der `-L` betyr at man skal linke dynamisk, `/usr/local/lib` er stdet der man finner biblioteket, og `-lfltk` at man skal se etter biblioteket `libfltk`.


## Lei av konfigurering? Last ned en ferdig kurs-VM.
Selv om vi synes det er viktig at dere får erfaring med installasjon og konfigurasjon av kurset, vil vi ikke at dere skal bruke all tiden på dette. Dersom du er lei og bare vil komme i gang har vi nå laget en ferdig VirtualBox-VM, med alt du trenger installert. 

Hvis du vil bruke denne, gjør slik:

  1. [Last ned den ferdige virtual-boks-VM'en her](https://www.dropbox.com/s/innnzqier054sue/ubuntu_cpp2014.ova) (Den skal være ferdig lastet opp ca. kl.22:15, mandag 17.03)
  2. Installer virtualbox, hvis du ikke har gjort det allerede
  3. I VirtualBox, velg *File->Import Appliance*. Du vil nå få opp en VM som heter "ubuntu_cpp2014", som kan startes ved å dobbeltklikke på den. 


### Hva vi har gjort, trinn for trinn (i tilfelle du vil lage den selv):

  1. Lastet ned siste versjon av lubuntu, [herfra](https://help.ubuntu.com/community/Lubuntu/GetLubuntu). Vi valgte *PC 64bit standard image disk*.
  2. Opprettet en ny VM i VirtualBox, ved å trykke "New" og så gi den *helt standard instillinger*. 
    * Brukernavn: *student*
    * Passord: *hioa*
  3. Logget inn i VM'en, åpnet en terminal, og oppdatert pakkesystemet:
    * `$ sudo apt-get update`
  4. Installert programvare slik:
    * `$ sudo apt-get install g++ valgrind emacs git make`
  5. Installert *fltk* slik (kunne vært gjort sammen med øvrig programvare)::
    * `$ sudo apt-get install fltk1.3` 
  6. Klonet kursets github-repo, slik:
    * `git clone https://github.com/hioa-cs/cpp_v2014.git`
  7. Gå inn i kurs-repo'et, og mappen "fltk_basics". Skriv `$ make` og så `$ ./fltk1`. Du skal da få opp et lite vindu med tre dotter i.

    