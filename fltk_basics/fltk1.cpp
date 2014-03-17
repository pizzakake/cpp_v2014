#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

//Funksjoner for tegning
#include <FL/fl_draw.H>

class dotbox : public Fl_Box {
public:
  using Fl_Box::Fl_Box; //Arve konstruktører fra base (C++11)
  
  void draw() override{ //Override draw fra box ('override' er C++11)   

    //Tegnefunksjonene forutsetter #include <FL/fl_draw.H> og at man er inni en Widget
    fl_color(FL_RED); //Sette penselfarge
    fl_pie(160,80,30,30,0,360); //Tegne
    fl_color(FL_GREEN); //...gjenta
    fl_pie(170,90,40,40,0,360);
    fl_color(FL_BLUE);
    fl_pie(180,100,30,30,0,360);
  }
};

int main(int argc, char** argv){
  //Opprett et vindu
  Fl_Window *window=new Fl_Window(340,180, "Dots!");
  //Opprette en instans av dotbox
  dotbox *box=new dotbox(0,0,340,180);

  //Sperr vinduet for å ta inn flere widgets
  window->end();

  //Vis vinduet
  window->show();
  
  //Start FLTK's event-loop (kjør appen)
  return Fl::run();

}
