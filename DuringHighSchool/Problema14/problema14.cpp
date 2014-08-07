//Problema14
//------------------------------------------------------------------------------
//Creati o lista cu toate masinile dintr-un parc auto. Pentru fiecare masina, se
//cunoaste numarul de inmatriculare, marca si culoarea. Afisati:
//a) numarul de masini din fiecare marca existente in parc;
//b) culoarea care predomina in acest parc auto;
//Exemplu:
//pentru n=3
//datele de intrare: 1 q e, 2 w e, 3 q g
//Rezultatul va fi:
// Masini marca q: 2;
// Masini marca w: 1;
// Culoarea predominanta este e! (cu 2 aparitii);
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>
#include <string.h>

struct nod {
	char nr[10],marca[10],culoare[10];
	nod *adr;
};

struct masina {
  char marca[10],culoare[10];
  unsigned numar;
};  

void creare ( nod *& prim, unsigned & n ) {
	nod *p,*q;
	p=new nod;
	cout<<"p->nr. de inmatriculare= ";  cin>>p->nr;
	cout<<"p->marca= ";  cin>>p->marca;
	cout<<"p->culoare= ";  cin>>p->culoare;
	p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
		q=new nod;
		cout<<"p->nr. de inmatriculare= ";  cin>>q->nr;
		cout<<"p->marca= ";  cin>>q->marca;
		cout<<"p->culoare= ";  cin>>q->culoare;
		p->adr=q;   q->adr=NULL;   p=q;
	}
	cout<<endl;
}

void nr_marca ( nod * prim, unsigned n ) {
  nod *p;
  unsigned k=0,g;
  masina * parc;
  parc=new masina[n];
  p=prim;
  while ( p ) {
    g=1;
    for ( int i=0; i<k;	i++ ) {
      if ( !stricmp ( p->marca, parc[i].marca ) ) { parc[i].numar+=1;	g=0;}
    }
    if ( g ) { strcpy ( parc[k].marca, p->marca );	 parc[k++].numar=1; }
    p=p->adr;
  }
  for ( int i=0; i<k; i++ ) 
    cout<<"Masini marca "<<parc[i].marca<<": "<<parc[i].numar<<endl; 
  delete [] parc;
  cout<<endl<<endl;
}

void culoare ( nod * prim, unsigned n ) {
  nod *p;
  unsigned k=0,g;
  masina * parc,maxim;
  parc=new masina[n];
  p=prim;
  while ( p ) {
    g=1;
    for ( int i=0; i<k;	i++ ) {
      if ( !stricmp ( p->culoare, parc[i].culoare ) ) { parc[i].numar+=1;	g=0;}
    }
    if ( g ) { strcpy ( parc[k].culoare, p->culoare );	 parc[k++].numar=1; }
    p=p->adr;
  }
  maxim=parc[0];
  for ( int i=1; i<n; i++ )
  	if ( maxim.numar<parc[i].numar ) maxim=parc[i]; 
  cout<<"Culoarea predominanta este: "<<maxim.culoare<<"! ( cu "<<maxim.numar
  		<<" aparitii )";
  delete [] parc;
  cout<<endl<<endl;
}

int main ( ) {
  nod *prim;
  unsigned n;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  nr_marca ( prim, n ); 
  culoare ( prim, n ); 
  getch ( );
  return 0;
}      
     
