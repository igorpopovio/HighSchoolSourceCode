//Fiind data o lista circulara simplu inlantuita, se cere sa se elimine zerourile
//din lista.

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod *adr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod *p, *q;
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
	while ( p!=prim ){ cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
	cout<<endl<<endl;
}

void elimina ( nod *& prim, nod *& ultim, int & n ) {
  nod *p, *q, *r;
  
  while ( prim->info==0 ) {
    r=prim;
    prim=prim->adr;
    ultim->adr=prim;
    delete r;
  }
  q=prim;
  p=prim->adr;  
  while ( p!=prim ) {
    if ( p->info==0 ) {
      q->adr=p->adr;
      r=p;
      p=p->adr;
      delete r;
      n--;
    }
    else {
      q=p;
      p=p->adr;
    }
    if ( q->adr==prim ) ultim=q;      
  }
}

int main ( ) {
  int n;
  nod * prim, * ultim;
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  elimina ( prim, ultim, n );
  listare ( prim );
  getch ( );
  return 0;
}          
      

