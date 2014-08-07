//Sa se genereze o lista ce contine numele unor persoane astfel incat sa fie ordonata.

#include <conio.h>
#include <string.h>
#include <iostream.h>

struct nod {
  char nume[30];
	nod *adr;
};

void creare ( nod *& prim, int n ) {
  nod * p, * q;
	p=new nod;
	cout<<"p->nume= ";  cin>>p->nume;
	p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
	  q=new nod;
		cout<<"p->nume= ";  cin>>q->nume;
		while ( p && ( strcmp ( p->nume, q->nume ) < 0 ) ) 
		  p=p->adr;
    if ( p==prim ) {
	    q->adr=p;
	    prim=q;
		}
		else {
	  	q->adr=p->adr;
	  	p->adr=q;
		}
		p=prim;
	}
	cout<<endl;
}

void listare ( nod *& prim ) {
  nod * p=prim;
  while ( p ) {
		cout<<"p->nume= "<<p->nume<<endl;  p=p->adr;}
cout<<endl<<endl;
}

int main ( ) {
  nod * prim=NULL;
  int n;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  listare ( prim );
  getch ( );
  return 0;
}
