//O lista simplu inlantuita nevida contine in campurile info din fiecare nod 
//valorile unor contracte succesive ale unei firme. Firma are dreptul sa revoce
//oricare din contracte, mai putin ultimul ( cel mai recent ).
//Sa se scrie o procedura care sa primeasca un pointer p spre un element al
//listei ( oricare ar fi acesta, exceptand ultimul nod ). Procedura trebue sa 
//aiba ca efect disparitia din lista a nodului indicat de pointerul p, fara sa
//se altereze structura de lista. Daca p indica ultimul nod, se va da doar un 
//mesaj de eroare.
//Atentie: se presupune ca lista a fost creata in programul principal, inaintea
//apelului procedurii de stergere, iar procedura nu are acces la adresa primului
//element din lista.
//Se cer: declaratiile din programul principal, procedura de stergere si 
//instructiunea din programul princpal care apeleaza procedura de stergere.
//Exemplu: lista initiala este 100, 300, 500, 400, 200. Daca pointerul indica
//nodul al doilea, dupa executia procedurii, lista contine: 100, 500, 400, 200.

#include <iostream.h>
#include <conio.h>

struct pnod {
  int info;
  pnod * urm;
};

void listare ( pnod * v ) {
  pnod * c=v;
  while ( c ) {
    cout<<c->info<<' ';
    c=c->urm;
  }
  cout<<endl;
}

void creare ( pnod *& v ) {
  int nr;
  pnod * c1, * c2;
  cout<<"Dati numarul ";	cin>>nr;
  while ( nr>=0 ) {
    if ( !v ) {
      v=new pnod;  v->info=nr;
      v->urm=NULL;  c1=v;
    }
    else {
      c2=new pnod;	c2->info=nr;
      c2->urm=NULL;	c1->urm=c2;
      c1=c2;
    }
    cout<<"Dati numarul ";	cin>>nr;
  }
}

void sterg ( pnod * x ) {
  pnod * q;
  if ( !x->urm ) cout<<" este ultimul!"<<endl;
  else {
    q=x->urm;
    x->info=x->urm->info;
    x->urm=x->urm->urm;
    delete q;
  }
}

int main ( ) {
  pnod * v=NULL, * m;
  int k;
  creare ( v );
  listare ( v ); 
  cout<<"nr. nodului care trebuie sters ";	cin>>k;
  m=v;
  for ( int i=1; i<k; i++ ) m=m->urm;
  sterg ( m );
  listare ( v );
  getch ( );
  return 0;
}
                    
