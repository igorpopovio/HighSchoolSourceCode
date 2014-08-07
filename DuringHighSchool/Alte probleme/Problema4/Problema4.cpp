//Creati ol ista ce prelucreaza numere complexe. Cerinte:
//  a) afisati lista;
//  b) determinati nr. complexe cu modulul cel mai mare;
//  c) determinati suma elementelor;
//  d) determinati produsul elementelor;

#include <conio.h>
#include <iostream.h>
#include <math.h>

struct nod {
  float re, im;
  nod *adr;
};

void creare ( nod *& prim, int n ) {
  nod *p,*q;
  p=new nod;
  cout<<"p->re= ";  cin>>p->re;
  cout<<"p->im= ";  cin>>p->im;
  p->adr=NULL; prim=p;
  for ( int i=2; i<=n; i++ ) {
    q=new nod;
    cout<<"p->re= ";  cin>>q->re;
    cout<<"p->im= ";  cin>>q->im;
    p->adr=q;   q->adr=NULL;   p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p=prim;
  while( p ) {
    cout<<p->re<<" + "<<p->im<<endl;  p=p->adr;
  }
  cout<<endl<<endl;
}

float modul ( nod & x ) {
  return sqrt ( x.re * x.re + x.im * x.im );
}  

nod modul_max ( nod *& prim ) {
  nod *p=prim->adr;
  nod max=*prim;
  while ( p ) {
    if ( modul ( *p ) > modul ( max ) ) max=*p;
    p=p->adr;
  }
  return max;
}

nod suma ( nod *& prim ) {
  nod suma=*prim;
  nod *p=prim->adr;
  while ( p ) {
    suma.re+=p->re;
    suma.im+=p->im;
    p=p->adr;
  }
  return suma;
}

nod produs ( nod *& prim ) {
  nod produs, prod=*prim;
  nod *p=prim->adr;
  while ( p ) {
    produs.re=prod.re * p->re - prod.im * p->im;
    produs.im=prod.re * p->im + prod.im * p->re;
    prod=produs;
    p=p->adr;
  }
  return produs;
}
            
int main ( ) {
  nod * prim=NULL;
  nod max, s, p;
  int n;
  cout<<"Cate nr. complexe doriti sa introduceti?"<<endl;
  cout<<"n= ";	cin>>n;
  creare ( prim, n );
  listare ( prim );
  max=modul_max ( prim );
  s=suma ( prim );
  p=produs ( prim );
  cout<<"Modul maxim al nr. din lista este: "<<max.re<<" + "<<max.im<<"*i"<<endl;
  cout<<"Suma= "<<s.re<<" + "<<s.im<<"*i"<<endl;
  cout<<"Produsul= "<<p.re<<" + "<<p.im<<"*i"<<endl;
  getch ( );
  return 0;  
}
