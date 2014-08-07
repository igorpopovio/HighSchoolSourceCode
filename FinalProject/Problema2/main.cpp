#include "ListaCDI.h"
#include <iostream>

using namespace std;

int main ( ) {
  ListaCDI lista ( 100000 );
  char adrFisier[30];
  cout<<"Introduceti fisierul de intrare: ";
  cin>>adrFisier;
  lista.readFile ( adrFisier );
  lista.listareStDr ( );
  cin.get ( );
  cin.get ( );
  return 0;
}
