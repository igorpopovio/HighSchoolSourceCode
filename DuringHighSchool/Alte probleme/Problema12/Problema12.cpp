//Sa se separe elementele dintr-o lista circulara simplu inlantuita cu informatii
//de tip intreg in doua liste astfel:
//  - elementele ce memoreaza nr. pare in prima lista;
//  - elementele ce memoreaza nr. impare in a doua lista;

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod *adr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod *p,*q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  prim=p;
  for ( int i=2; i<=n; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->adr=q;   q->adr=prim;   ultim=p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p;
  cout<<"p->info= "<<prim->info<<"  ";  p=prim->adr;
  while ( p!=prim ) {
    cout<<"p->info= "<<p->info<<"  ";  p=p->adr;
  }
  cout<<endl<<endl;
}

void separa ( nod *& prim, nod *& prim1, nod *& prim2 ) {
  nod *p,*q,*r,*s,*t;    
  p=prim;
  do {
    if ( p->info%2==0 ) {
      if ( prim1==NULL ) {
        q=new nod;
        q->info=p->info;
        q->adr=prim1;
        prim1=q;
      }
      else {
        r=new nod;
        r->info=p->info;
        r->adr=prim1;
        q->adr=r;
        q=r;
      }
    }
    else {
      if ( prim2==NULL ) {
        s=new nod;
        s->info=p->info;
        s->adr=prim2;
        prim2=s;
      }
      else {
        t=new nod;
        t->info=p->info;
        t->adr=prim2;
        s->adr=t;
        s=t;
      }
    } 
    p=p->adr;
  } while ( p!=prim );
}

int main ( ) {
  nod * prim=NULL, * ultim=NULL;
  nod * prim1=NULL, * ultim1=NULL;
  nod * prim2=NULL, * ultim2=NULL;
  int n;
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  separa ( prim, prim1, prim2 );
  cout<<"Nr. pare: "<<endl;
  listare ( prim1 );
  cout<<"Nr. impare: "<<endl;
  listare ( prim2 );
  getch ( );
  return 0;
}  
           

