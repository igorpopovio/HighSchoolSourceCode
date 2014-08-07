//Problema3
//------------------------------------------------------------------------------
//Scrieti o functie care sa primeasca ca parametru adresa unui nod dintr-o lista
//dublu inlantuita si care sa returneze valoarea 1 daca lista are proprietatea
//palindromica si 0 in caz contrar. Spunem ca lista are proprietatea palindromica
//daca parcurgand lista de la inceput catre sfarsit obtinem aceeasi secventa de
//informatii ca la parcurgerea listei de la sfarsit catre inceput.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int & n ) {
  nod *p,*q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL; prim=ultim=p;

  for ( int i=2 ; i <= n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }

ultim=p;
cout<<endl;
}

int palindrom ( nod * prim, nod * ultim, int n ) {
  int g=1;    nod * p=prim, * q=ultim;
  for ( int i=0 ; i < (int) n/2 ; i++ ) {
    if ( p->info != q->info ) g=0;
    p=p->dr;  q=q->st;
  }
return g;
}



void main ( ) {
  int n;
  nod *prim, *ultim;
  cout<<"creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;
  creare ( prim, ultim, n );
  if ( palindrom ( prim, ultim, n ) ) cout<<"lista are proprietatea palindromica;"<<endl;
    else cout<<"lista nu are proprietatea palindromica;"<<endl;

  getch();
}
