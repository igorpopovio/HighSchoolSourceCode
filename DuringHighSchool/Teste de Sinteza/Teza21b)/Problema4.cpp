//Sa se scrie un subprogram de cautare a unui element intr-o lista dublu inlantuita
//dupa o cheie c data. Elementele listei sunt numere intregi.
//Lista este accesibila dintr-un punct oarecare, aflat la adresa la care s-a gasit
//valoarea c cautata sau NULL daca valoare cautata nu se afla in lista.

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int & n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL; prim=ultim=p;
  for( int i=2; i<=n; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }
  ultim=p;
  cout<<endl;
}

nod * cauta ( nod *& adr, int & c ) {
  nod * p;
  while ( !p && p->info!=c ) p=p->dr;
  if ( !p ) return p;
  p=adr;
  while ( !p && p->info!=c ) p=p->st;
  return p;
}

int main ( ) {
  nod * prim ,* ultim;
  int n, c;
  cout<<"Nr. de elemente n= ";	cin>>n;
  creare ( prim, ultim, n );
  cout<<"Introduceti valoarea cautata c= ";	cin>>c;
  if ( cauta ( prim->dr->dr->dr, c ) ) cout<<"Elementul "<<c<<" a fost gasit!";
  else cout<<"Elementul "<<c<<" nu a fost gasit!";
  getch ( );
	return 0;
}  
