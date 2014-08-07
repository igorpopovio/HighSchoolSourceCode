//Generati permutarile de intregi ale unei liste circulare simplu inlantuita

#include <conio.h>
#include <iostream.h>
 
struct nod {
int info;
nod *adr;
};

void creare ( nod *& prim, nod *& ultim, int n) {
  nod *p, *q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  prim=p;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
 		cout<<"p->info= ";  cin>>q->info;
 		p->adr=q;   q->adr=prim;   ultim=p=q;
  }
  cout<<endl;
}

void listare ( nod *& prim ) {
  nod *p, *q;
  p=prim;
  do {
    cout<<p->info<<"  ";
    q=p->adr;
    while ( q!=p ) {
      cout<<q->info<<"  ";
      q=q->adr;
    }
    cout<<endl;
    p=p->adr;
  } while ( p!=prim );
  cout<<endl<<endl;
}

int main ( ) {
  nod * prim=NULL , * ultim=NULL;
  int n;
  cout<<"n= ";	cin>>n;
  creare ( prim, ultim, n );
  listare ( prim );
  getch();
  return 0;
}
