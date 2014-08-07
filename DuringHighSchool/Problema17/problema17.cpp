//Problema17
//------------------------------------------------------------------------------
//Sa se separe o lista dublu inlantuita cu informatii de tip intreg in doua liste
//dublu inlantuite cu informatii pozitive si negative.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>

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

void separa ( nod *& prim, nod *& pozitiv, nod *& negativ ) {
  nod * p, * r, * s, * w, * v;
  p=prim;
  while ( p ) {
    if ( p->info>0 ) {
      if ( pozitiv == NULL ) { r=new nod;    r->info=p->info;  r->st=r->dr=NULL;    pozitiv=r;
      }
        else   { s=new nod;    s->info=p->info;  s->dr=NULL;  s->st=r;  r->dr=s;   r=s;
        }
      }
        else { if ( negativ == NULL ) { w=new nod;    w->info=p->info;  w->st=w->dr=NULL;    negativ=w;
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
  nod * prim, * ultim, * pozitiv=NULL, * negativ=NULL;
  nod * p, * q;
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, ultim, n );
  separa ( prim, pozitiv, negativ );
  cout<<"2. afisez lista de la stanga la dreapta cu nr pozitive;"<<endl;
  list_st_dr ( pozitiv );
  cout<<"3. afisez lista de la stanga la dreapta cu nr negative;"<<endl;
  list_st_dr ( negativ );
  getch();
  return 0;
}
