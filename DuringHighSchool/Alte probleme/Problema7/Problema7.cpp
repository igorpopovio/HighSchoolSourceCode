//Se considera o lista liniara dublu inlantuita ce memoreaza pentru un produs:
//  cod_produs, nume, pret.

#include <conio.h>
#include <iostream.h>


struct nod {
  int cod_produs;
  char nume[20];
  float pret;
  nod *st,*dr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod *p, *q;
  p=new nod;
  cout<<"p->cod_produs= ";  cin>>p->cod_produs;
  cout<<"p->nume= ";  cin>>p->nume;
  cout<<"p->pret= ";  cin>>p->pret;
  p->st=p->dr=NULL; prim=ultim=p;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
    cout<<"p->cod_produs= ";  cin>>q->cod_produs;
    cout<<"p->nume= ";  cin>>q->nume;
    cout<<"p->pret= ";  cin>>q->pret;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }
  ultim=p;
  cout<<endl;
}

void list_st_dr ( nod *& prim ) {
  nod *p=prim;
  while ( p ) {
    cout<<"p->cod_produs= "<<p->cod_produs<<endl;  
    cout<<"p->nume= "<<p->nume<<endl;  
    cout<<"p->pret= "<<p->pret<<endl<<endl;  
    p=p->dr;}
  cout<<endl;
}

void list_dr_st( nod *& ultim ) {
  nod *p=ultim;
  while ( p ) {
    cout<<"p->cod_produs= "<<p->cod_produs<<endl;  
    cout<<"p->nume= "<<p->nume<<endl;  
    cout<<"p->pret= "<<p->pret<<endl<<endl;  
    p=p->st;}
  cout<<endl;
}

void adaugare ( nod *& prim, nod *& ultim, int & n, int k ) {
  nod *p, *q;
  nod *r;
  if ( k==1 ) {
  	p=new nod;
    cout<<"p->cod_produs= ";  cin>>p->cod_produs;
    cout<<"p->nume= ";  cin>>p->nume;
    cout<<"p->pret= ";  cin>>p->pret;
    prim->st=p; p->dr=prim;   p->st=NULL;   prim=p;
  }
  else if ( k==n ) {
  	p=new nod;  
    cout<<"p->cod_produs= ";  cin>>p->cod_produs;
    cout<<"p->nume= ";  cin>>p->nume;
    cout<<"p->pret= ";  cin>>p->pret;
    ultim->dr=p;  p->st=ultim;  p->dr=NULL; ultim=p;
  }
  else {
    p=prim;
    for ( int i=1; i<(k-1); i++ ) p=p->dr;
    q=new nod; 
    cout<<"p->cod_produs= ";  cin>>p->cod_produs;
    cout<<"p->nume= ";  cin>>p->nume;
    cout<<"p->pret= ";  cin>>p->pret;
    r=p->dr;  p->dr=q;  q->st=p;
    q->dr=r;  r->st=q;
  }
  cout<<endl;  n++;
}

void stergere ( nod *& prim, nod *& ultim, int & n, int k ) {
  nod *r, *s;
  nod *p, *q;
  if ( k==1 ) {
    p=prim; prim=p->dr; prim->st=NULL;  delete p;
  }
  else if ( k==n ) {
    p=ultim;  ultim=p->st;  ultim->dr=NULL; delete p;
  }
  else {
    p=prim; 
    for ( int i=1; i<k; i++ ) p=p->dr;
    r=p->st;  s=p->dr;
    r->dr=s;  s->st=r;  delete p;
  }
  cout<<endl; n--;
}

int main ( ) {
  nod * prim=NULL, * ultim=NULL;
  int n, k;
  
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl; 
  cout<<"n= ";		cin>>n;
  creare ( prim, ultim, n );
  cout<<"2. listez de la stanga la dreapta;"<<endl;  list_st_dr ( prim );
  cout<<"3. listez de la dreapta la stanga;"<<endl;  list_dr_st ( ultim );
  cout<<"4. adaugam un nod pe pozitia k;"<<endl;     
  cout<<"k= ";	cin>>k;
  adaugare ( prim, ultim, n, k );
  cout<<"5. listez de la stanga la dreapta;"<<endl;  list_st_dr ( prim );
  cout<<"6. stergem un nod de pe pozitia k;"<<endl;  
  cout<<"k= ";	cin>>k;
  stergere ( prim, ultim, n, k );
  cout<<"7. listez de la stanga la dreapta;"<<endl;  list_st_dr ( prim );
  getch ( );
  return 0;
}
