//Pe o tija verticala sunt n bile colorate cu cel mult k culori, fiecare bila avand
//o eticheta cu un numar de la 1 la n. Sa se mute bilele pe alte k tije, pe fiecare
//punandu-se numai bile de aceeasi culoare. Fiecare tija are un capat liber pe unde
//se introduc/extrag bilele, celalalt capat fiind sudat de suportul tijei.
//Sa se afiseze bilele de pe fiecare din cele k tije.

#include <conio.h>
#include <iostream.h>

struct nod {
	int nr;
	int culoare; 
	nod * adr;
};

nod * tija[20];

//Subprogramele pentru stiva----------------------------------------------------
void push ( nod *& v, nod *& p ) {
	nod *c;
	if ( !v ) {
		v=new nod;  
  	v->nr=p->nr;
  	v->culoare=p->culoare;
  	v->adr=NULL;
	}
	else {
		c=new nod;  
		c->nr=p->nr;
  	c->culoare=p->culoare;
		c->adr=v;   v=c;
	}
}

void pop ( nod *& v ) {
	nod *c;
	if ( !v )  cout<<"stiva este vida;"<<endl;
	else {
	c=v;  cout<<"am scos bila: "<<c->nr<<";"<<endl;
	v=v->adr; delete c;
	}
}
//------------------------------------------------------------------------------

//Crearea pentru lista liniara simplu inlantuita--------------------------------
void creare ( nod *& prim, int n ) {
	nod *p, *q;
	p=new nod;
	cout<<"c->nr= ";  cin>>p->nr;
  cout<<"c->culoare= ";  cin>>p->culoare;
  p->adr=NULL; prim=p;
	for ( int i=2; i<=n; i++ ) {
		q=new nod;
		cout<<"c->nr= ";  cin>>q->nr;
  	cout<<"c->culoare= ";  cin>>q->culoare;
  	p->adr=q;   q->adr=NULL;   p=q;
 	}
cout<<endl;
}
//------------------------------------------------------------------------------

void mutare ( nod *& prim ) {
  nod *p, *q;
  p=prim;
  while ( p ) {
    push ( tija[p->culoare], p );
    p=p->adr;
  }
}

void listare ( int k ) {
  for ( int i=1; i<=k; i++ ) {
    cout<<"tija "<<i<<":"<<endl;
    pop ( tija[i] );
  }
}        
    
    
int main ( ) {
  int n, k;
  nod * tija1;
  cout<<"n= ";	cin>>n;
  cout<<"k= ";	cin>>k;
  creare ( tija1, n );
  mutare ( tija1 );
  listare ( k );
  getch ( );
  return 0;
}  
