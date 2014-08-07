//Se considera o lista liniara simplu inlantuita ce memoreaza: nume, prenume,
//varsta, telefon. Cerinte:
//  a) media de varsta;
//  b) afisati numele persoanelor minore;
//  c) stergerea unui element;
//  d) adaugarea unui element pe o pozitie k;

#include <conio.h>
#include <iostream.h>

struct nod {
  char nume[20], prenume[20], tel[10];
  int varsta;
  nod * adr;
};

void creare ( nod *& prim, int n ) {
  nod *p,*q;
  p=new nod;
  cout<<"p->nume= ";  cin>>p->nume;
  cout<<"p->prenume= ";  cin>>p->prenume;
  cout<<"p->telefon= ";  cin>>p->tel;
  cout<<"p->varsta= ";  cin>>p->varsta;
  p->adr=NULL; prim=p;
  for ( int i=2; i<=n; i++ ) {
    q=new nod;
    cout<<"p->nume= ";  cin>>q->nume;
    cout<<"p->prenume= ";  cin>>q->prenume;
    cout<<"p->telefon= ";  cin>>q->tel;
    cout<<"p->varsta= ";  cin>>q->varsta;
    p->adr=q;   q->adr=NULL;   p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p;
  p=prim;
  while ( p ) { 
    cout<<"p->nume= "<<p->nume<<endl;
    cout<<"p->prenume= "<<p->prenume<<endl;
    cout<<"p->telefon= "<<p->tel<<endl;
    cout<<"p->varsta= "<<p->varsta<<endl;
    p=p->adr;
  }
  cout<<endl<<endl;
}

void adaugare ( nod *& prim, int & n, int k ) {
  nod *p,*q;
  p=prim;
  for ( int i=1; i<(k-1); i++) p=p->adr;
  q=new nod;  
  cout<<"p->nume= ";  cin>>q->nume;
  cout<<"p->prenume= ";  cin>>q->prenume;
  cout<<"p->telefon= ";  cin>>q->tel;
  cout<<"p->varsta= ";  cin>>q->varsta;
  if ( k==1 ) {
    q->adr=prim;  prim=q;
  }
  else {
    q->adr=p->adr;  p->adr=q;
  }
  cout<<endl;  n++;
}

void stergere ( nod *& prim, int & n ) {
  nod * p=prim;
  prim=p->adr;  delete p;
  cout<<endl; n--;
}

float media ( nod *& prim ) {
  nod *p;
  p=prim;
  float m=0; int k=0;
  while ( p ) {
    m+=p->varsta; k++;
    p=p->adr;
  }
  return m/k;
}

void minori ( nod *& prim ) {
  nod * p=prim;
  while ( p ) {
  if ( p->varsta<18 ) cout<<p->nume<<"  "<<p->prenume<<endl;
  p=p->adr;
  }
}  
      
int main ( ) {
  nod *prim;
  int n, k;
  cout<<"1. creez o lista liniara simplu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;  creare ( prim, n );
  cout<<"2. listez continutul listei;"<<endl;  listare ( prim );
  cout<<"3. adaugam un nod pe pozitia k;"<<endl; 
  cout<<"k= ";	cin>>k;    adaugare ( prim, n, k );
  cout<<"4. listez continutul listei;"<<endl;  listare ( prim );
  cout<<"5. stergem un nod de pe pozitia k;"<<endl;  stergere ( prim, n );
  cout<<"6. listez continutul listei;"<<endl;  listare ( prim );
  cout<<"7. afisam media de varsta;"<<endl;   
  cout<<"Media de varsta= "<<media ( prim );
  cout<<"8. afisam persoanele minore;"<<endl;
  minori ( prim );
  getch ( );
  return 0;
}
