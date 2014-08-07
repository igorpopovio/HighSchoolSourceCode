//Se considera declaratiile necesare definirii unei liste simplu inlantuite:
//typedef struct element {
//  int inf;
//  element * urm;
//}element;
//a) Scrieti un subprogram care creeaza o lista cu un anumit numar de elemente
//( precizat ca parametru ), valorile campului inf fiind generate aleator astfel
//incat orice doua elemente succesive ale listei sa se afle in ordine crescatoare;
//subprogramul va returna adresa primului element din lista;
//b) Scrieti un subprogram care interclaseaza doua liste ( considerate ordonate ),
//fiecare lista fiind data prin adresa primului sau element ( sau NULL daca lista
//respectiva este vida ); subprogramul va returna adresa primului element din
//lista rezultata in urma interclasarii.

#include <conio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct element {
  int inf;
  element * urm;
};

element *p, *q;

element * next ( int i, int prec ) {
  element * a;
  if ( i==0 ) return NULL;
  else {
    a=new element;
    a->inf=prec + random ( 20 );
    a->urm=next ( i-1, a->inf );
    return a;
  }
}

element * inter ( element * p, element * q ) {
  if ( !p ) return q;
  else if ( !q ) return p;
  else if ( p->inf<=q->inf ) {
    p->urm=inter ( p->urm, q );
    return p;
  }
  else {
    q->urm=inter ( p, q->urm );
    return q;
  }
}

void scrie ( element * p ) {
  while ( p ) { cout<<p->inf<<" ";	p=p->urm; }
  cout<<endl;
}

int main ( ) {
  randomize ( );
  p=next ( random ( 10 ), 0 );	scrie ( p );      
  q=next ( random ( 10 ), 0 );	scrie ( q );  
  p=inter ( p, q );
  scrie ( p );
  getch ( );
  return 0;
}          
