//Problema22
//------------------------------------------------------------------------------
//Se da o lista liniara simplu inlantuita avnd ca informatii numere naturale.
//Sa se ordoneze informatiile crescator, prin actualizarea legaturilor listei.
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

struct nod {
	unsigned info;
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

void copie ( nod * prim, unsigned tablou[], unsigned & n ) {
  nod *p;
  int i=0;
  p=prim;
  while ( p ) {
    tablou[i++]=p->info;
    p=p->adr;
  }
} 

void bubblesort ( unsigned tablou[], unsigned & n ) {
  int g=1,i;
  unsigned aux;
  while ( g ) {
    g=0;
    for ( i=0; i<(n-1); i++ )
    if ( tablou[i]>tablou[i+1] ) {
      aux=tablou[i];
      tablou[i]=tablou[i+1];
      tablou[i+1]=aux;
      g=1;
    }
  }
}

void actualizeaza ( nod *& prim, unsigned tablou[], unsigned & n ) {
  copie ( prim, tablou, n );
  bubblesort ( tablou, n );
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

int main ( ) {
  nod *prim;
  unsigned tablou[50];
  unsigned n;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  listare ( prim );
  actualizeaza ( prim, tablou, n );
  listare ( prim );
  getch ( );
  return 0;
}              
  
