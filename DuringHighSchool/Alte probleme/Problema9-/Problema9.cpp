//Fiind data o lista liniara dublu inlantuita cu informatii de tip intreg, se cere 
//sa se verifice daca lista are in fiecare nod al sau nr. prime. In caz contrar
//sa se faca eliminarea elementelor care nu sunt prime.

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL;   prim=ultim=p;
  for ( int i=2; i<=n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }
  ultim=p;
  cout<<endl;
}

int este_prim ( int & a ) {
  for ( int i=2; i < ( a/2 +1 ); i++ )
    if ( a % i == 0 ) return 0; 	
  return 1;
}

void stergere ( nod *& prim, nod *& ultim, int & n, int k ) {
  nod *r,*s;
  nod *p, *q;
  if ( k==1 ) {
    p=prim; prim=p->dr; prim->st=NULL;  delete p;
  }
  else if ( k==n ) {
    p=ultim;  ultim=p->st;  ultim->dr=NULL; delete p;
  }
  else {
    p=prim; for ( int i=1; i<k; i++ ) p=p->dr;
    r=p->st;  s=p->dr;
    r->dr=s;  s->st=r;  delete p;
  }
  cout<<endl; n--;
}

void elimina_neprime ( nod *& prim, nod *& ultim, int & n ) {
  int k=1;
  nod * p=prim;
  do {
    if ( !este_prim ( p->info ) ) {
      p=p->st;
      stergere ( prim, ultim, n, k );
    }  
    p=p->dr;	k++;
  } while ( p );
}    

void list_st_dr ( nod *& prim ) {
  nod * p;
  p=prim;
  while ( p ) {
    cout<<p->info<<"  ";
    p=p->dr;
  }
  cout<<endl<<endl;
}

int main ( ) {
  int n;
  nod * prim=NULL, * ultim=NULL;
  nod * p, * q;
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, ultim, n );
  elimina_neprime ( prim, ultim, n );
  cout<<"2. afisez lista de la stanga la dreapta cu nr prime;"<<endl;
  list_st_dr ( prim );
  
  getch();
  return 0;
}
