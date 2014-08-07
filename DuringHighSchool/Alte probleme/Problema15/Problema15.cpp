//Sa se foloseasca conceptul de stiva alocata dinamic pentru a face conversia unui nr.
//din baza 10 in baza <=16.


#include <conio.h>
#include <iostream.h>


struct nod {
  char info;
  nod * adr;
};

char rest [ 16 ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
										 'A', 'B', 'C', 'D', 'E', 'F' };	

int push ( nod *& v, char & x ) {
  nod *c;
  if ( !v ) {
  	v=new nod;
    if ( !c ) return 0;
    v->info=x;
  	v->adr=NULL;
 	}
 	else {
 		c=new nod;
    if ( !c ) return 0;
    c->info=x;
 		c->adr=v;   v=c;
  }
  return 1;
}

int pop ( nod *& v, char & x ) {
	nod *c;
	if ( !v )  return 0;
  else {
  	c=v;  x=c->info;
  	v=v->adr; delete c;
 	}
 	return 1;
}

int main ( ) {
  nod * varf=NULL;
  unsigned n, r, q;
  char c;
  cout<<"n= ";	cin>>n;
  cout<<"Baza ( 1 <= q <= 16 in care doriti sa convertiti nr )= ";	cin>>q;
  if ( q==0 || q>16 ) return 1;
  while ( n ) {
    r=n%q;
    n/=q;
    push ( varf, rest[r] );
  }
  while ( pop ( varf, c ) ) cout<<c;
  getch ( );
  return 0;
}    
  
