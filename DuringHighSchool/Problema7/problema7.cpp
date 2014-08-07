//Problema7
//------------------------------------------------------------------------------
//Fiind data o lista dubla sa se separe in doua liste elementele prime si
//neprime.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream>
using namespace std;

struct nod {
  int info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL;   prim=ultim=p;
  for ( int i=2; i<=n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }
  ultim=p;
  cout<<endl;
}

int este_prim ( int & a ) {
  for ( int i=2; i < ( a/2 +1 ); i++ )
    if ( a % i == 0 ) return 0; 	
  return 1;
}

void separa ( nod *& prim, nod *& prime, nod *& neprime ) {
  nod * p, * r, * s, * w, * v;
  p=prim;
  while ( p ) {
    if ( este_prim ( p->info ) ) {
      if ( prime == NULL ) { r=new nod;    r->info=p->info;  r->st=r->dr=NULL;    prime=r;
      }
        else   { s=new nod;    s->info=p->info;  s->dr=NULL;  s->st=r;  r->dr=s;   r=s;
        }
      }
        else { if ( neprime == NULL ) { w=new nod;    w->info=p->info;  w->st=w->dr=NULL;    neprime=w;
               }
               else   {v=new nod;    v->info=p->info;  v->dr=NULL;  v->st=w;   w->dr=v;   w=v;
               }
    }

  p=p->dr;
  }
}

void list_st_dr ( nod *& prim ) {
  nod * p;
  p=prim;
  while ( p ) {
    cout<<p->info<<"  ";
    p=p->dr;
  }
  cout<<endl<<endl;
}

int main ( ) {
  int n;
  nod * prim, * ultim, * prime=NULL, * neprime=NULL;
  nod * p, * q;
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, ultim, n );
  separa ( prim, prime, neprime );
  cout<<"2. afisez lista de la stanga la dreapta cu nr prime;"<<endl;
  list_st_dr ( prime );
  cout<<"3. afisez lista de la stanga la dreapta cu nr neprime;"<<endl;
  list_st_dr ( neprime );
  getch();
  return 0;
}
