//Problema4
//------------------------------------------------------------------------------
//Scrieti o functie care sa parcurga o lista simplu inlantuita a carei adresa de
//la inceput este specificata ca parametru si care sa returneze numarul de perechi
//de noduri consecutive din lista care contin in partea de informatie valori intregi
//de semne contrare.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod * adr;
};


void creare ( nod *& prim, int n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->adr=NULL; prim=p;

  for ( int i=2 ; i <= n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->adr=q;   q->adr=NULL;   p=q;
  }

  cout<<endl;
}

int numara ( nod * prim ) {
  int k=0;
  nod * p, * q;
  p=prim;
  q=prim->adr;
  while ( q ) {
    if ( p->info == ( 0 - q->info ) ) k++;
    p=p->adr;
    q=q->adr;
  }
return k;
}


void main ( ) {
  int n;
  nod * prim;
  cout<<"creez o lista liniara simplu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, n );
  cout<<"lista contine "<<numara ( prim )<<" perechi de noduri consecutive ce au"<<endl
      <<"partea de informatie formata din numere intregi de semne contrare;"<<endl;

  getch();
}