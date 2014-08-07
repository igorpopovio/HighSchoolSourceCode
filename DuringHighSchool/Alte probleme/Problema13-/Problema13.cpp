//Fiind date doua liste ordonate crescator, scrieti un subprogram care interclaseaza
//cele doua liste.

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod *adr;
};


void creare ( nod *& prim, int n ) {
  nod * p, *q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->adr=NULL; prim=p;
  for ( int i=2; i<=n; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->adr=q;   q->adr=NULL;   p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p=prim;
  while ( p ) {
    cout<<"p->info= "<<p->info<<"  ";  p=p->adr;
  }
  cout<<endl<<endl;
}

void interclasare ( nod *& prim, nod *& prim1, nod *& prim2 ) {
  nod *p, *q, *r, *s;
  p=prim1;
  q=prim2;
  while ( p && q ) {
    if ( p->info>q->info ) {
      if ( prim==NULL ) {
        r=new nod;
        r->info=q->info;
        r->adr=NULL;
        prim=r;
      }
      else {
        s=new nod;
        s->info=q->info;
        s->adr=NULL;
        r->adr=s;
        r=s;
      }
    }
    else {
      if ( prim==NULL ) {
        r=new nod;
        r->info=p->info;
        r->adr=NULL;
        prim=r;
      }
      else {
        s=new nod;
        s->info=p->info;
        s->adr=NULL;
        r->adr=s;
        r=s;
      }
    }
    p=p->adr;
    q=q->adr;
  }
  while ( p ) {
    s=new nod;
    s->info=p->info;
    s->adr=NULL;
    r->adr=s;
    r=s;
  }
  while ( q ) {
    s=new nod;
    s->info=q->info;
    s->adr=NULL;
    r->adr=s;
    r=s;
  }
}

int main ( ) {
  nod * prim=NULL, * prim1=NULL, * prim2=NULL;
  int n,m;
  cout<<"Introduceti 2 liste in ordine crescatoare: "<<endl;
  cout<<"n= ";	cin>>n;
  creare ( prim1, n );
  cout<<endl;     
  cout<<"m= ";	cin>>m;
  creare ( prim2, m );
  interclasare ( prim, prim1, prim2 );
  cout<<endl;
  listare ( prim );
  getch ( );
  return 0;
}
            
