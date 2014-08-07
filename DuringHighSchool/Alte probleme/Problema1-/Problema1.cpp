//Sa se creeze o lista liniara simplu inlantuita care memoreaza elementele nenule
//dintr-o matrice impreuna cu linia si coloana pe care se afla acel element.
//Cerinte:
//  a) afisati elementele de pe diagonala principala;
//  b) sa se afiseze elementul maxim din lista;
//  c) sa se afiseze dvizorii tuturor elementelor din lista;

#include <iostream.h>

struct nod {
  int nr;
  int lin, col;
  nod * adr;
};

void divizor ( int numar ) {
  int k;
  cout<<1<<"  ";
  for ( k=2; k<=numar/2; k++ )
    if ( numar%k==0 ) cout<<k<<"  ";
  cout<<numar;
  cout<<endl;
}

void citire ( nod *& prim, int n, int m ) {
  nod *p, *q;
  p=new nod;  
  cout<<"Element= ";
  cin>>p->nr;
  cout<<"Linia= ";	cin>>p->lin;
  cout<<"Coloana= "; cin>>p->col;
  prim=p;
  for ( int i=0; i<n; i++ )
    for ( int j=0; j<m; j++ ) {
      cout<<"Element= ";
      q=new nod;
      cin>>q->nr;
      cout<<"Linia= ";	cin>>q->lin;
      cout<<"Coloana= "; cin>>q->col;
      p->adr=q;
      p=q;
    }
  p->adr=NULL;
}

nod maxim ( nod *& prim ) {
  nod maxim;
  maxim=*prim;
  nod *p;
  p=prim;
  while ( p ) 
    if ( maxim.nr<p->nr ) maxim=*p;
  return maxim;
}

int main ( ) {
  nod *prim=NULL;
  int n,m;
  cout<<"Nr. de linii  = ";	cin>>n;
  cout<<"Nr. de coloane= "; cin>>m;
  citire ( prim, n, m );
  nod max= maxim ( prim );
  cout<<"Maximul este: "<<max.nr<<" si se gaseste pe linia "<<max.lin<<" si "
        "coloana "<<max.col;
  cout<<"Divizorii elementelor din matrice:"<<endl;
  nod *p;
  p=prim;
  while ( p ) {
    cout<<"divizorii lui "<<p->nr<<" sunt:"<<endl;
    cout<<"   ";
    divizor ( p->nr );
  }
  cin.get ( );
  return 0; 
}   
                
