//Problema9
//------------------------------------------------------------------------------

#include <iostream.h>
#include <string.h>
#include <conio.h>

struct nod_pr {
	char numeProprietar[10],nrInmatriculare[10];
	unsigned an;
	nod_pr *adr;
};

struct nod {
  char marca[10];
  nod_pr *prim;
  nod *adr;
};  

void creare_pr ( nod_pr *& prim, unsigned & n ) {
	nod_pr *p,*q;
	p=new nod_pr;
	cout<<"p->numeProprietar= ";  cin>>p->numeProprietar;
	cout<<"p->an= ";  cin>>p->an;
	cout<<"p->nrInmatriculare= ";  cin>>p->nrInmatriculare;
	p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
		q=new nod_pr;
		cout<<"p->numeProprietar= ";  cin>>p->numeProprietar;
		cout<<"p->an= ";  cin>>p->an;
		cout<<"p->nrInmatriculare= ";  cin>>p->nrInmatriculare;
		p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void creare ( nod *& prim, unsigned & n ) {
	nod *p,*q;
	unsigned k;
	p=new nod;
	cout<<"p->marca= ";  cin>>p->marca;
	cout<<"Nr. de proprietari= ";	cin>>k;
	creare_pr ( p->prim, k );
	p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
		q=new nod;
		cout<<"p->marca= ";  cin>>q->marca;
		cout<<"Nr. de proprietari= ";	cin>>k;
		creare_pr ( q->prim, k );
		p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void suprima ( nod *& prim, unsigned an ) {
  nod *p,*q;
  nod_pr *r,*s,*z;
  p=prim;
  while ( p ) {
    r=p->prim->adr;		s=p->prim;
    while ( r ) {
      if ( r->an<an ) {
        z=r;
        s->adr=r->adr;
        delete z;
      }
      s=r;
      r=r->adr;
    }
    p=p->adr;
  }
}

void listare ( nod * prim ) {
  nod *p;
  nod_pr *q;
  p=prim;
  while ( p ) {
    cout<<"marca: "<<p->marca<<endl;
    q=p->prim;
    while ( q ) {
      cout<<"     numeProprietar: "<<q->numeProprietar<<endl; 
      cout<<"     an: "<<q->an<<endl;
      cout<<"     nrInmatriculare: "<<q->nrInmatriculare<<endl;
      q=q->adr;
    }
    p=p->adr;
  }
  cout<<endl<<endl;
}            
int main ( ) {
  nod *prim;
  unsigned an;
  unsigned n;
  cout<<"Nr. de noduri= ";	cin>>n;
  creare ( prim, n );
  cout<<"Introduceti anul de inmatriculare: ";	cin>>an;
  suprima ( prim, an );
  listare ( prim );
  getch ( );
  return 0;
}  
        


