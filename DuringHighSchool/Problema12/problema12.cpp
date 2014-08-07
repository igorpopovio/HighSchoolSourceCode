//Problema12
//------------------------------------------------------------------------------
//O lista contine coordonatele a n puncte in plan. Sa se determine tripletele de
//puncte consecutive din lista care sunt coliniare si sa se afiseze.
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

struct nod {
	float x,y;
	nod *adr;
};

void creare ( nod *& prim, unsigned & n ) {
  nod *p,*q;
  p=new nod;
  if ( n>=3 ) {
  	cout<<"p->x= ";  cin>>p->x;
  	cout<<"p->y= ";  cin>>p->y;
  	p->adr=NULL; prim=p;
  	for ( int i=2; i<=n; i++ ) {
  		q=new nod;
  		cout<<"p->x= ";  cin>>q->x;
  		cout<<"p->y= ";  cin>>q->y;
  		p->adr=q;   q->adr=NULL;   p=q;
  		}
  		cout<<endl;
  }
  else cout<<"Introduceti cel putin coordonatele a 3 puncte!";		
}

void coliniar ( nod * prim ) {
  nod *p,*q,*r;
  r=prim->adr->adr;
  q=prim->adr;
  p=prim;
  cout<<"Tripletele de puncte consecutive din lista ce sunt coliniare: "<<endl;
  while ( r ) {
    if ( ( q->x - p->x ) * ( r->y - p->y ) ==
 			   ( r->x - p->x ) * ( q->y - p->y ) ) {
	    cout<<"{ "<<p->x<<" ; "<<p->y<<" } ";
	    cout<<"{ "<<q->x<<" ; "<<q->y<<" } ";
	    cout<<"{ "<<r->x<<" ; "<<r->y<<" } ";
	    cout<<endl<<endl;
	  }
 		p=q;
   	q=r;
    r=r->adr;
  }
} 

int main ( ) {
  nod *prim;
  unsigned n;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  coliniar ( prim );
  getch ( );
  return 0;
}         

