//Problema1
//------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>

using namespace std;

struct nod {
	int info;
	nod *adr;
};

void creare ( nod *& prim, nod *& ultim, unsigned & n ) {
	nod *p, *q;
  p=new nod;
  p->info=1;
  prim=p;	
  for ( int i=2; i<=n; i++ ) {
  q=new nod;
  q->info=i;
  p->adr=q;   q->adr=prim;   ultim=p=q;
  }
}
int main ( ) {
  unsigned a[50][50],i,j,k,n;
  nod *prim, *ultim, *p;
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  for ( i=0; i<n; i++ ) {
    p=prim;
    while ( p->info!=( i+1 ) ) p=p->adr;
    for ( j=0; j<n; j++ ) { a[i][j]=p->info;	p=p->adr; }
  }
  for ( i=0; i<n; i++ ) 
  for ( j=0; j<n; j++ ) {
    if ( j%n==0 ) cout<<endl;
    cout<<a[i][j]<<" ";
  }
  getch ( );
  return 0;
}    
