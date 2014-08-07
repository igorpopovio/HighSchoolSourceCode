//Intr-o lista liniara simplu inlantuita se pastreaza coeficientii nenuli ai unui
//polinom P(x) impreuna cu gradul monomului respectiv. Cerinte:
//  a) valoarea polinomului pentru o valoare data x;
//  b) suma a doua polinoame;
//  c) produsul a doua polinoame;

#include <iostream.h>
#include <conio.h>
#include <math.h>

struct nod {
  float coeficient;
  unsigned grad;
  nod * adr;
};

void adaug ( nod *& prim, float cf, unsigned gr ) {
  nod * p, * q, * r;
  p=new nod;
  p->grad=gr;
  p->coeficient=cf;
  p->adr=NULL;
  if ( !prim ) prim=p;
  else {
    if ( prim->grad<p->grad ) {
      p->adr=prim;
      prim=p;
    }
    else {
      q=prim->adr;
      r=prim;
      while ( q ) {
        if ( q->grad<p->grad ) {
          r->adr=p;
          p->adr=q;
          break;
        }
        r=q;
        q=q->adr;
      }
    }
  }
}

void creare ( nod *& prim, unsigned & n ) {
  float cf;
  unsigned gr;
  for ( int i=0; i<n; i++ ) {
    cout<<"gradul= ";	cin>>gr;
    cout<<"coeficientul= ";		cin>>cf;
    adaug ( prim, cf, gr );
  }
}    

void sterg ( nod *& prim ) {
  nod * p=prim;
  while ( prim ) {
    prim=prim->adr;
    delete p;
    p=prim;
  }
}

void afiseaza ( nod *& prim ) {
  int i=0;
  nod * p=prim;
  while ( p ) {
    if ( i ) cout<<"+";
    cout<<p->coeficient<<"x^"<<p->grad;
    p=p->adr; i++;
  }
  cout<<endl<<endl;
}

nod * adunare ( nod * prim1, nod * prim2 ) {
  nod * p1=prim1;
  nod * p2=prim2;
  nod * prim;
  while ( p1 && p2 ) 
  if ( p1->grad==p2->grad ) {
    if ( p1->coeficient+p2->coeficient )
      adaug ( prim, ( p1->coeficient+p2->coeficient ), p1->grad );
    p1=p1->adr;
    p2=p2->adr;
  }
  else 
    if ( p1->grad>p2->grad ) {
      adaug ( prim, p1->coeficient, p1->grad );
      p1=p1->adr;
    }
    else {
      adaug ( prim, p2->coeficient, p2->grad );
      p2=p2->adr; 
    } 
  if ( p1 ) {
    while ( p1 ) {
    	adaug ( prim, p1->coeficient, p1->grad );
    	p1=p1->adr;
   	}
  }
  else {
  	while ( p2 ) {
    	adaug ( prim, p2->coeficient, p2->grad );
    	p2=p2->adr;
  	} 
  } 	
  return prim;
} 

nod * negativ ( nod * prim ) {
  nod * prim1=NULL;
  while ( prim ) {
    adaug ( prim1, -prim->coeficient, prim->grad );
    prim=prim->adr;
  }
  return prim1;
}

nod * mulmonom ( nod * prim, float cf, unsigned gr ) { 
  nod * prim1=NULL, * ultim1;
  while ( prim ) {
    adaug ( prim1, prim1->coeficient*cf, prim1->grad+gr );
    prim=prim->adr;
  }
  return prim1;
}

nod * mul ( nod * prim1, nod * prim2 ) {
  nod * prim=NULL;
  while ( prim2 ) {
    nod * aux=NULL, * aux1;
    aux=mulmonom ( prim1, prim2->coeficient, prim2->grad );
    aux1=prim;
    prim=adunare ( prim, aux );
    sterg ( aux );
    sterg ( aux1 );
    prim2=prim2->adr;
  }
  return prim;
}

float eval ( nod *& prim, float x ) {
  nod * p=prim;
  float rez=0;
  while ( p ) {
		rez+=p->coeficient*pow ( x, p->grad );
		p=p->adr;
  }
  return rez;
}

int main ( ) {
  nod * prim;
  unsigned n;
  float x;
  cout<<"Nr de monoame: ";	cin>>n;
  creare ( prim, n );
  cout<<"Introduceti o valoare pentru a evalua polinomul: ";	cin>>x;
  cout<<"f(x)= "<<eval ( prim, x );
  getch ( );
  return 0;
}
  
