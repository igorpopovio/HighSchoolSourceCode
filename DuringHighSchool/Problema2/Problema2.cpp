//Problema2
//------------------------------------------------------------------------------
//Un grup format din n copii, numerotati de la 1 la n joaca urmatorul joc:
//-se aseaza in cerc, in ordinea 1, 2, ... , n, dupa copilul n urmand copilul 1;
//-copilul 1 alege un numar k si incepand cu el copiii numara de la 1 la k;
//-copilul care a rostit numarul k este eliminat din joc, iar numaratoarea se
//  reia de la copilul care urmeaza celui eliminat.
//Simulati acest joc utilizand o lista simplu inlantuita circulara. Numerele
//naturale nenule n si k se vor citi de la tastatura. Pe ecran se va afisa
//ordinea in care sunt eliminati copiii din joc.
//
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>

struct nod {
  int copil;
  nod *adr;
};

void creare ( nod *& prim, nod *& ultim, unsigned & n ) {
  nod *p,*q;
  p=new nod;
  p->copil=1;
  prim=p;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
  	q->copil=i;
  	p->adr=q;   q->adr=prim;   ultim=p=q;
 	}
 	cout<<endl;
}

void stergere ( nod *& prim, nod *& ultim, nod *& k, unsigned & n ) {
  nod *p,*q;
  p=prim;
  if ( k->copil==prim->copil ) {
  	prim=prim->adr;  delete p;    ultim->adr=prim;
 	}
 	else if ( k->copil==ultim->copil ) {
    for ( int i=1; i<( n-1 ); i++ )  p=p->adr;
    delete ultim;   ultim=p;    ultim->adr=prim;
  }
  else {
    while ( k->copil!=p->copil ) { q=p;  p=p->adr; }
    q->adr=p->adr;  delete p;
  }
  cout<<endl; n--;
}

void numaratoare ( nod *& prim, nod *& ultim, unsigned & n ) {
  nod *p,*q;
  int k;
  while ( n>0 ) {
    cout<<"k= ";  cin>>k;
    p=prim;
    for ( int i=1; i < k; i++ )  p=p->adr;
    q=p;  p=p->adr;
    cout<<"copilul "<<q->copil<<" este scos din joc"<<endl;
    stergere ( prim, ultim, q, n );
  }
  cout<<"Nu a mai ramas nici un copil in joc!!!";
}

int main ( ) {
  nod *prim,*ultim;
  unsigned n;
  cout<<"creez o lista circulara simplu inlantuita cu n copii;"<<endl; 
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  numaratoare ( prim, ultim, n );
  getch ( );
  return 0;
}
