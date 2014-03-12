### Installering av g++ og FLTK for Linux

På Ubuntu kan man bare:

```
  sudo apt-get install g++ build-essential cmake
  sudo apt-get install libfltk1.3-dev
```

### Installering av g++ og FLTK for Windows

Installer TDM-GCC, samt msys bash (for å få bash på windows)

```
  http://tdm-gcc.tdragon.net/download
  http://sourceforge.net/projects/mingwbuilds/files/external-binary-packages/
```


Et veldig bra GUI for git på Windows er "Github for Windows":

```
  http://windows.github.com/
```

For å installere fltk, følg instruksjonene her:

```
  http://www.fltk.org/doc-1.3/intro.html
```

Følg instruksjonene som om du var i Linux: ./configure, make, make install

#### Du trenger disse filene for å gjøre FLTK oppgavene:

```
  http://www.stroustrup.com/Programming/Graphics/
```

En kompilerbar versjon av det som er ovenfor med en del fixes:

```
  http://fbcraft.fwsnet.net/fyrverkeri.tar.gz
```

Først gå inn i stroustrup mappen og kompiler via 'make'. Bruk så 'make' i fyrverkeri mappen for å kompilere oppgaven. Det ligger et lite test skjelett i main.cpp som man kan bruke som utgangspunkt. Jeg brukte det for å verifisere at alt kompilerte. Ikke testet på windows.

Du trenger GCC 4.8.x for å kunne bruke -Og i gcc commandline. Hvis du ikke har det, bare fjern parametret fra makefile.
