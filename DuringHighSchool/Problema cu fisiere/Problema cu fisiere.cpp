//Problema cu fisiere
//------------------------------------------------------------------------------
//Se da un fisier text avnd pe cateva linii memorate numare naturale. Scrieti un
//program care sa afiseze minimul de pe fiecare linie.
//
//------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main ( ) {
  fstream fin ( "numere.in", ios::in );
  char sir[100], * aux;
  unsigned nr, minim, i;
  fin.getline ( sir, 100 );
  i=1;	//linia curenta din fisier
  do {
    minim=64000;
    aux=strtok ( sir, " \n" );
    do {
    	nr=atol ( aux );
    	if ( nr<minim ) minim=nr;
    	aux=strtok ( NULL, " \n" );
    } while ( aux!=NULL );
    cout<<"minimul de pe linia "<<i++<<" este: "<<minim<<endl;
  } while ( fin.getline ( sir, 100 ) );
  fin.close ( );
  getch ( );
  return 0;
}   	
