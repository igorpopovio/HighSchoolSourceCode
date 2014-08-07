//Problema5
//------------------------------------------------------------------------------
//Scrieti un subprogram care insereaza intre oricare doua elmente ale unei liste
//dublu inlantuite media lor aritmetica.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>

struct nod {
  float info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL;   prim=ultim=p;

  for ( int i=2; i <=n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }

  ultim=p;
  cout<<endl;
}

void adaugare ( nod *& nod1, nod *& nod2, int & n ) {
  nod * p=new nod;
  p->info= ( nod1->info + nod2->info )/2;
  p->dr=nod2;   p->st=nod1;
  nod1->dr=p;          nod2->st=p;      n++;
}

void list_st_dr ( nod *& prim ) {
  nod * p;
  p=prim;
  while ( p ) {
    cout<<p->info<<endl;
    p=p->dr;
  }
}

void main ( ) {
  int n;
  nod * prim, * ultim;
  nod * p, * q;
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, ultim, n );
  p=prim;    q=prim->dr;
  while ( q ) {
    adaugare ( p, q, n );
    p=q;    q=q->dr;
  }
  cout<<"2. afisez lista de la stanga la dreapta;"<<endl;
  list_st_dr ( prim );
  getch();
}