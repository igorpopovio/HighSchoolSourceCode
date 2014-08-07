//Dandu-se maxim un milion de numere intregi, intre care destul de multe se repeta, 
//sa se gaseasca un procedeu eficient de determinare a numarului care se repeta 
//cel mai des. Citirea datelor se face incepand cu un numar n care reprezinta
//numarul de valori de prelucrat ( maximum un milion ) si este urmata de numerele
//respective. Eficienta procedeului consta in utilizarea unei singure treceri
//prin numere, dupa ce acestea au fost citite toate, pentru a se determina acel
//numar care se repeta de cele mai multe ori.

#include <conio.h>
#include <iostream.h>

typedef struct arb {
  int n;
  long rep;
  arb * s, * d;
}*nod;
long m, maxim, nr;
int x;

void crarb ( nod & r, int m ) {
  if ( r==NULL ) {
    r=new arb;
    r->n=m;
    r->rep=1;
    r->s=NULL;
    r->d=NULL;
  }
  else if ( r->n!=m )
  			 if ( r->n>m ) crarb ( r->s, m );
         else crarb ( r->d, m );
       else r->rep++;
}

void drs ( nod r ) {
  if ( r ) {
    drs ( r->d );
    if ( maxim<r->rep ) {
      x=r->n;
      maxim=r->rep;
    }
    drs ( r->s );
  }
}

int main ( ) {
  int a, nr;
  nod r;
  cout<<"Dati numarul de valori, maximum un milion ";
  cin>>m;
  nr=1;
  maxim=0;
  r=NULL;
  cout<<"Dati valori pentru arbore "<<endl;
  while ( nr<=m ) {
    cin>>a;
    nr++;
    crarb ( r, a );
  }
  drs ( r );
  cout<<"Numarul care se repeta de cele mai multe ori: ";
  cout<<x<<" ( de "<<maxim<<" ori! )"<<endl;
  getch ( );
  return 0;
}
                
