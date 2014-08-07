//Problema20
//------------------------------------------------------------------------------
//Fiind data o lista simplu inlantuita cu informatii numere reale, sa se faca
//eliminarea elementelor negative. Sa se afiseze ambele liste (cea noua si cea
//veche).
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

struct nod {
	float info;
	nod *adr;
};

void creare ( nod *& prim, unsigned & n) {
	nod * p,* q;
 	p=new nod;
	cout<<"p->info= ";  cin>>p->info;
	p->adr=NULL; prim=p;
	for( int i=2; i<=n; i++ ) {
		q=new nod;
		cout<<"p->info= ";  cin>>q->info;
		p->adr=q;   q->adr=NULL;   p=q;
	}
}

void listare ( nod *& prim ) {
	nod * p;
  p=prim;
	while ( p ) { cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
	cout<<endl<<endl;
}

void elimina ( nod *& prim ) {
  nod *p,*q,*r;
  while ( prim->info<0 ) { r=prim;	prim=prim->adr;	delete r;}
  p=prim->adr;	q=prim;
  while ( q ) {
    while ( q->info<0 ) {
      r=q;
      p->adr=q->adr;
      delete r;
    }
    p=q;	q=q->adr;
  }
}

int main ( ) {
  nod *prim;
  unsigned n;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  listare ( prim );
  elimina ( prim );
  listare ( prim );
  getch ( );
  return 0;
}        
      
