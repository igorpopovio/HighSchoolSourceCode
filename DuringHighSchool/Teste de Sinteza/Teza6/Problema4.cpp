//Beneficiile filialelor unei firme sunt depuse in campurile info ale unei liste
//simplu inlantuite L1. Se doreste sa selectam intr-o alta lista simplu inlantuita
//L2 bebeficiile din L1 ce depasesc o valoare x ce se citeste de la tastatura.
//Se cere sa se scrie o procedura, prin care sa se realizeze lista L2 care sa
//contina in campurile sale info valorile ce depasesc valoarea x luate din 
//campurile info ale listei L1.
//Numarul natural x se citeste in programul principal.
//Procedurii i se transmit: un pointer p1 la inceputul listei L1 si numarul 
//natural x. Procedura va intoarce un pointer p2 la primul nod al listei L2.
//Daca lista L2 este vida, pointerul p2 va contine constanta NULL.

#include <conio.h>
#include <iostream.h>

struct pnod {
  int info;
  pnod * urm;
};
int x;

void listare ( pnod * v ) {
  pnod * c=v;
  while ( c ) {
    cout<<c->info<<" ";
    c=c->urm;
  }
  cout<<endl;
}

void creare ( pnod *& v ) {
  int nr;
  pnod *c1, *c2;
  //pana la citirea unei valori negative
  cout<<"dati numarul: ";		cin>>nr;
  while ( nr>=0 ) {
    if ( !v ) {
      v=new pnod;
      v->info=nr;
      v->urm=NULL;
      c1=v;
    }
    else {
      c2=new pnod;
      c2->info=nr;
      c2->urm=NULL;
      c1->urm=c2;
      c1=c2;
    }
    cout<<"dati numarul: ";	cin>>nr;
  }
}

void proc ( pnod * p1, pnod *& p2 ) {
  pnod * c1, *c2;
  p2=NULL;
  while ( p1 ) {
    if ( p1->info>x )
    if ( !p2 ) {
      p2=new pnod;
      p2->info=p1->info;
      p2->urm=NULL;
      c1=p2;
    }
    else {
      c2=new pnod;
      c2->info=p1->info;
      c2->urm=NULL;
      c1->urm=c2;
      c1=c2;
    }
    p1=p1->urm;
  }
}

int main ( ) {
  pnod * v=NULL, * v1=NULL;
  creare ( v );
  listare ( v );
  cout<<"valoarea x= ";	cin>>x;
  proc ( v, v1 );
  listare ( v1 );
  getch ( );
  return 0;
}
    
                 
