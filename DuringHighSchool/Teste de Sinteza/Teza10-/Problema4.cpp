//Scrieti un program care citeste un numar natural n ( 1<n<16 ) si scrie pe prima
//linie a fisierului "sir.out" un sir ce contine numerele intre 1 si 2^n, sir 
//creat astfel:
//  -se porneste cu sirul initial format din 1 si 2;
//  -exact la mijlocul acestuia se insereaza secventa formata de 3 si 4
//   obtinandu-se sirul 1 3 4 2;
//  -exact la mijlocul sirului asfel format se insereaza secventa formata de
//   numerele 5, 6, 7 si 8 obtinandu-se sirul 1 3 5 6 7 8 4 2 etc;
//In general: la mijlocul sirului format de primele 2^i numere naturale se 
//insereaza secventa ordonata formata din urmatoarele 2^i numere naturale.

#include <iostream.h>
#include <fstream.h>
#include <conio.h>

typedef struct element {
  long nr;
  element * urm;
};
fstream g ( "sir.out", ios::out );
element *prima, *med, *p, *q;
int i, n;

element * adauga ( element * q, long v ) {
  element *p;
  p=new element;
  p->nr=v;
  if ( !prima ) prima=p;
  else q->urm=p;
  return p;
}

int main ( ) {
  long crt=1, maxim=1;
  cout<<"n= ";	cin>>n;
  for ( i=1; i<=n; i++, maxim*=2, p->urm=q, p=med, q=med->urm )
  for ( ; crt<=maxim*2; crt+=2, med==med==0?prima:med->urm ) {
    p=adauga ( p, crt );
    p=adauga ( p, crt+1 );
  }
  for ( p=prima, i=1; i<=maxim/2; i++, p=p->urm ) g<<p->nr<<"  ";
  g.close ( );
  getch ( );
  return 0;
}
       
