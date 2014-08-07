//Se citeste un sir de cuvinte terminat cu cuvantul format numai din caracterul
//* si se cere sa se afiseze aceste cuvinte in ordine inversa celei de la citire.
//Se va utiliza pentru memorarea cuvintelor o structura dinamica de date.

#include <iostream.h>
#include <string.h>
#include <conio.h>

struct element {
  char cuvant[20];
  element * urm;
};

element * p, * vf;
char cuv[20];

int main ( ) {
  //introducerea elementelor in stiva
  vf=NULL;
  cout<<"cuvantul: ";		cin>>cuv;
  while ( strcmp ( cuv, "*" )!=0 ) {
    p=new element;
    strcpy ( p->cuvant, cuv );
    p->urm=vf;
    vf=p;
    cout<<"cuvantul: ";	cin>>cuv;
  }
  
  //parcurgerea elementelor din stiva
  if ( !vf ) cout<<"primul cuvant citit a fost *";
  else {
  	cout<<"cuvintele in ordine inversa: ";
   	p=vf;
    do {
    	cout<<p->cuvant<<" ";
     	p=p->urm;
    } while ( p );
    cout<<'\n';
  }
  getch ( );
  return 0;
}      
