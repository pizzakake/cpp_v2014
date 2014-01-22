#include <iostream>

using namespace std;


int main(){ 

  //Create an unsigned int, on stack
  unsigned int i=0; 
  i--; //Decrement. But, since unsigned ints does not support negative numbers, we get the biggest possible int.
  //Create a double, and decrement it, just to see the difference
  double d=0; d--;
  
  //Create a pointer to an unsigned (int*), and set it to the address of i (&i)
  unsigned int* iptr=&i;
  
  //'Dereference' iptr (that is, 'talk about what iptr points to') and set the value to 10
  *iptr=10;
  
  //Create a void-pointer - that is a pointer which points to an objet of undefined size
  //...This means that we can't write to it or read from it, since we don't know the size
  //It also means that we have to explicitly cast whatever we want to assign to it
  //Here, we assign it .. an int! It's a 4-bit number, which will now be interpreted as an address
  void* vptr=(void*)i;
  
  //Create a char, and initialize (Look in the ascii table to see which character)
  char c=64;
  
  //Create a lon
  long l=0;

  //Print out the variables, and their sizes (in bytes)
  cout << "i: " << i << " size: " << sizeof(i) << endl;
  cout << "d: " << d << " size: " << sizeof(d) << endl;
  cout << "c: " << c << " size: " << sizeof(c) << endl;
  cout << "l: " << l << " size: " << sizeof(l) << endl;
  
  //This just prints out the "value" of the pointer - which is the address it contains
  cout << "iptr: " << iptr << " size: " << sizeof(iptr) << endl;
  
  //Here we want to read (dereference) whatever the void-pointer points to.
  //...But void* is of "unspecified size" so we have to cast it to a type with size information
  //We cast it to an int-pointer (int*), and then we dereference, that is, we try to get an int out of whatever the void-pointer points to. Or; we want to get the four bytes, starting at addr 'vptr'. Then we print.
  //Is it allowed to read from this place in memory? Print out the address itself (vptr) to see which one it is.
  cout << "vptr: " << *((int*)vptr) << " size: " << sizeof(vptr) << endl;
  
  
  
  
}

