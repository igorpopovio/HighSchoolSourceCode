//Problema21 
//------------------------------------------------------------------------------
//Fiind date 2 liste simplu inlantuite cu informatii de tip intreg, sa se scrie
//functii care sa faca urmatoarele operatii: reuniunea, intersectia, diferenta
//si diferenta simetrica.
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

struct nod {
	unsigned info;
	nod *adr;
};

void creare ( nod *& prim, unsigned & n ) {
	nod *p,*q;
	p=new nod;
	cout<<"p->info= ";  cin>>p->info;
	p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
		q=new nod;
		cout<<"p->info= ";  cin>>q->info;
		p->adr=q;   q->adr=NULL;   p=q;
	}
	cout<<endl<<endl;
}

void listare ( nod * prim ) {
	nod *p;
	p=prim;
	cout<<"{ ";
	while ( p ) { cout<<p->info<<"; ";  p=p->adr;}
	cout<<" }";
	cout<<endl<<endl;
}

nod * concatenare ( nod * prim1, nod * prim2 ) {
	nod *r,*p,*q,*prim3;
	p=prim1->adr;
	prim3=new nod;
	prim3->info=prim1->info;    r=prim3;
	while ( p ) {
		q=new nod;
		q->info=p->info;
		r->adr=q;   r=r->adr;   p=p->adr;
	}
	p=prim2;
	while ( p ) {
		q=new nod;
		q->info=p->info;
		r->adr=q;   r=r->adr;   p=p->adr;
	}
	r->adr=NULL;
	return prim3;
}

void copie ( nod * prim, unsigned tablou[] ) {
  nod *p;
  int i=0;
  p=prim;
  while ( p ) {
    tablou[i++]=p->info;
    p=p->adr;
  }
} 

void actualizeaza ( nod *& prim, unsigned tablou[], unsigned & n ) {  
  nod *p,*q;
  p=new nod;
  p->info=tablou[0];	prim=p;
  for ( int i=1; i<n; i++ ) {
    q=new nod;
    q->info=tablou[i];
    p->adr=q;	p=q;
  }
  p->adr=NULL;  
}

nod * reuniune ( nod * prim1, nod * prim2, unsigned n1, unsigned n2 ) {
  unsigned a[50],b[50],i,j,g,k=0;
  nod *prim3;
  prim3=concatenare ( prim1, prim2 );
  copie ( prim3, a );
  for ( i=0; i<( n1+n2 ); i++ ) {
    g=1;
    for ( j=0; j<k; j++ )
    if ( a[i]==b[j] ) g=0;
    if ( g==1 ) b[k++]=a[i];
  }
  actualizeaza ( prim3, b, k );
  return prim3;
}

nod * intersectie ( nod * prim1, nod * prim2, unsigned n1, unsigned n2 ) {
  unsigned a[50],b[50],c[50],i,j,k=0;
  nod *prim3;
  copie ( prim1, a );
  copie ( prim2, b );
  for ( i=0; i<n1; i++ ) {
    for ( j=0; j<n2; j++ )
    if ( a[i]==b[j] ) c[k++]=a[i];
  }
  actualizeaza ( prim3, c, k );
  return prim3;
}

nod * diferenta ( nod * prim1, nod * prim2, unsigned n1,
								 unsigned n2, unsigned & n ) {
  unsigned a[50],b[50],c[50],i,j,k=0,g;
  nod *prim3;
  copie ( prim1, a );
  copie ( prim2, b );
  for ( i=0; i<n1; i++ ) {
    g=1;
    for ( j=0; j<n2; j++ )
    if ( a[i]==b[j] ) g=0;
    if ( g==1 ) c[k++]=a[i];
  }
  actualizeaza ( prim3, c, k );		n=k;
  return prim3;
}

int main ( ) {
  nod *prim1,*prim2,*prim3,*prim4,*prim5;
  unsigned n1,n2,n3,n4,n;
  cout<<"n1= ";	cin>>n1;
  creare ( prim1, n1 );
  cout<<"n2= ";	cin>>n2;
  creare ( prim2, n2 );
  cout<<"A= ";	listare ( prim1 );
  cout<<"B= ";	listare ( prim2 );
  prim3=reuniune ( prim1, prim2, n1, n2 );
  cout<<"A reunit cu B= ";  listare ( prim3 );
  prim3=intersectie ( prim1, prim2, n1, n2 );
  cout<<"A intersectat cu B= ";  listare ( prim3 );
  prim3=diferenta ( prim1, prim2, n1, n2, n );
  cout<<"A - B= ";  listare ( prim3 );
  prim3=diferenta ( prim2, prim1, n2, n1, n );
  cout<<"B - A= ";  listare ( prim3 );
  prim3=diferenta ( prim1, prim2, n1, n2, n3 );
  prim4=diferenta ( prim2, prim1, n2, n1, n4 );
  prim5=reuniune ( prim3, prim4, n3, n4 );
  cout<<"(A - B) reunit cu (B - A)= ";  listare ( prim5 );
  getch ( );
  return 0;
}      
  
