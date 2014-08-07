//Un elev are de realizat un program in care si-a definit tipurile necesare
//lucrului cu o lista dublu inlantuita astfel:
//typedef struct nod {
//  int info;
//  nod *prec, *urm;
//}nod;
//Pentru a introduce date in lista, el copiaza din caiet o procedura de creare
//a unei liste circulare simplu inlantuite ( folosind numai campul urm pentru
//a desemna adresa urmatorului element din lista, campul prec nefiind folosit )
//si i se pare mai simplu sa scrie o alta procedura care transforma lista circulara
//simpla in lista dublu inlantuita. Chiar daca nu sunteti de acord cu el trebuie 
//sa-l ajutati sa scrie procedura.
//Sa se scrie procedura care primeste ca parametru de intrare adresa p a unui
//element oarecare E din lista circulara, element ce va deveni capatul initial 
//al listei dublu inlantuite, lista care va fi formata din aceleasi elemente ca
//si lista circulara, in aceeasi ordine, la adresa de inceput a listei aflandu-se
//elementul E. Procedura va returna in variabila p adresa elementului E din lista
//dublu inlantuita construita.

#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;
typedef struct nod {
  int info;
  nod *prec, *urm;
};
nod *prima, *ultima;
int i;

void creare ( ) {
  nod *p, *q;
  int i,n;
  randomize ( );
  n=1+random ( 20 );
  prima=NULL;
  for ( i=1; i<=n; i++, p=q ) {
    q=new nod;
    q->info=random ( 1000 ) * ( 1-2*( random ( 2 )==0 ) );
    if ( !prima ) prima=q;
    else p->urm=q;
  }
  p->urm=prima; //realizarea legaturii circulare
}

void listare ( int sens ) {
  nod *p;
  if ( sens==1 ) p=prima;
  else p=ultima;
  if ( p )
  do {
    cout<<p->info<<" ";
    if ( sens==1 ) p=p->urm;
    else p=p->prec;
  } while ( p && ( p!=prima || sens==0 ) );
  cout<<endl;
}

void ldi ( nod * p ) {
  if ( p ) {
    p->prec=NULL;
    while ( p->urm!=prima ) {
      p->urm->prec=p;
      p=p->urm;
    }
    p->urm=NULL;
  }
  ultima=p; 
}

int main ( ) {
  creare ( );
  listare ( 1 );
  for ( i=1; i<=random ( 50 ); i++ ) prima=prima->urm;
  ldi ( prima );
  listare ( 1 ); listare ( 0 );
  getch ( );
  return 0;
}
               
