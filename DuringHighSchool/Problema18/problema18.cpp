//Problema18
//------------------------------------------------------------------------------
//Fiind date elementele reale ale unei liste simplu inlantuite in ordine crescatoare
//sa se faca o functie de insertie a unui element astfel incat lista sa ramana
//ordonata.
//
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;


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

void listare ( nod * prim ) {
	nod * p;
  p=prim;
	while ( p ) { cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
	cout<<endl<<endl;
}

void adaugare ( nod *& prim, float & numar ) {
  nod *p,*q,*r;
  p=prim;
  r=new nod;	r->info=numar;  r->adr = NULL;
  if ( p->info>numar ) {
    r->adr=prim;	prim=r;
  }
  else {
    while ( p->info<numar && p!=NULL ) { q=p; p=p->adr;}
    if ( !p ) {r->adr=p;		q->adr=r;}
    else q->adr = r;
  }  
}

int main ( ) {
  unsigned n;
  float numar;
  nod *prim;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  listare ( prim );
  cout<<"numar= ";	cin>>numar;
  adaugare ( prim, numar );
  listare ( prim );
  system ( "PAUSE" );
  return 0;
}
