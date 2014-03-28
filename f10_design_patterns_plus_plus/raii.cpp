/*
  Code adapted from Bjarne Stroustrup FAQ; 
  http://www.stroustrup.com/bs_faq2.html#finally  
  
  Demonstrates the RAII (Resource Acquizition Is Initialization) pattern/idiom.
  Here we use it to make a low-level file-handle exception-proof. We could just as well use it to protect 
  - a server socket (if you don't close it you - or any other process - can't reopen it)
  - memory allocated with new (if you don't delete you have a memory leak)
  - a mutex (if you don't release it you'll get a deadlock

  ...or any other resource that needs to be properly released after use.

  Comment/Uncomment the classical vs. the RAII solution, in "dataFromFile" to see the effect.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

//Our RAII-class
class specialFile{
  FILE* p; //A C file pointer
public:
  //Acquire file (the resource) by instantiating (initializing) this class
  specialFile(const char* file, const char* access){
    p=fopen(file,access);
    if(p==0)
      throw runtime_error("File not found");
  }

  //We know that destructors are called when leaving scope!
  //So we can release the resource, simply by going out of scope.
  //...even if it happens by an exception
  ~specialFile(){     
    fclose(p);
  }
  //Overload *-operator to get easy access to the pointer
  FILE* operator*(){return p;}
};

//Do some low-level file access; read only certain bytes into buf.
void dataFromFile(char* buf,int size){
  /* 
     Classical solution (Comment/uncomment the following line) 
  */
  FILE* f=fopen("raii.cpp","r");  //try this solution first
  /* ~Classical solution */
  
  /* 
     RAII-solution (Comment/Uncomment the two following lines) 
  */
  //specialFile safe("raii.cpp","r"); //The RAII solution
  //FILE* f=*safe;        //Belongs to the RAII-solution; just here to make the remaining lines work for both cases.
  /* ~RAII-solution */
  
  fseek(f,23,SEEK_SET);
  fread(buf,size,1,f);
  throw runtime_error("forgot my keys!");
  //Ops! We'll never get here!
  fclose(f);
}
  
  
int main(){
  //Set up a buffer
  const int bufsize=18;
  char buffer[bufsize+1]={0};
  
  try{
    //Fill it with certain bytes from a file
    dataFromFile(buffer,bufsize);
  }catch(runtime_error e){
    //Pretend this error was not so serious...
    cout << "Tiny glitch: " << e.what() << endl;
  }

  //...So we continue running
  cout << "Nevermind, we got the contents. Enter a nice word to see it:" << endl;
  
  string input;
  while(cin>>input){
    cout << input << " " << buffer << endl;
    cout << "Now check if the file is open! (Ask your OS)" << endl;
    //Use your operating system to find out if the file is still open. 
    //On Linux / mac, use the command "lsof -f PID" where PID is the process ID. 
    //...Get the PID by calling "ps aux | grep raii" when the raii process is running.
    //On mac, you can also select the process in "activity monitor" and press "inspect". Will show a tab of open files.
    //On windows; I don't know, but there is a tool here : http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx
  }

}

