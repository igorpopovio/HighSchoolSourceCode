//Fiind data o lista circulara simplu inlantuita ce memoreaza un sir de cuvinte,
//se cere sa se afiseze toate cuvintele distincte.

#include <conio.h>
#include <iostream.h>

struct nod {
  char cuvant[20];
  nod *adr;
};

void creare ( nod *& prim, nod *& ultim, int & n ) {
  nod *p, *q;
  p=new nod;
  cout<<"p->cuvant= ";  cin>>p->cuvant;
  prim=p;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
 		cout<<"p->cuvant= ";  cin>>q->cuvant;
 		p->adr=q;   q->adr=prim;   ultim=p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p;
  cout<<"p->cuvant= "<<prim->cuvant<<"  ";  p=prim->adr;
  while ( p!=prim ){cout<<"p->cuvant= "<<p->cuvant<<"  ";  p=p->adr;}
  cout<<endl<<endl;
}

void cuv_distincte ( nod *& prim ) {
  nod *p, *q;
  p=prim->adr;
  while ( p!=prim ) {
    q=p->adr;
    while ( q!=prim ) {
      if ( !strcmp ( p->cuvant, q->cuvant ) ) break;
      q=q->adr;
    }
    if ( q==prim ) cout<<p->cuvant<<endl;
    p=p->adr;
  }
}

int main ( ) {
  nod * prim, * ultim;
  int n;
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  listare ( prim );
  cuv_distincte ( prim );
  getch ( );
  return 0;
}      
    
