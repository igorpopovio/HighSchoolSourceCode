//Un grup de n orase sunt legate intre ele printr-un traseu circular. O masina
//trebuie sa parcurga toate statele plecand dintr-o localitate si resosind la sfarsit
//in aceeasi localitate. Parcurgerea se poate face in ambele sensuri. Se cunoaste
//cantitatea de benzina existenta in fiecare statie, distantele dintre oricare 
//doua orase vecine si consumul de benzina al masinii la 100 de Km. Se cere sa se
//determine un traseu posibil de parcurgere astfel incat sa nu se ramana in pana de 
//benzina. (Implementare prin lista circulara dublu inlantuita).

#include <conio.h>
#include <iostream.h>

struct nod {
  int ord;
	float distanta;
	float combustibil;
	nod *st, *dr;
};

float rezervor, consum;

void creare ( nod *& prim, nod *& ultim, int n ) {
	nod *p, *q;
  p=new nod;
  cout<<"p->distanta= ";  cin>>p->distanta;
  cout<<"p->combustibil= ";  cin>>p->combustibil;
  prim=ultim=p;
  prim->st=ultim;   ultim->dr=prim;
  prim->ord=1;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
  	cout<<"p->distanta= ";  	cin>>q->distanta;
  	cout<<"p->combustibil= ";  cin>>q->combustibil;
  	q->ord=i;
    p->dr=q;  q->st=p;
  	p=q;
 	}
 	p->dr=prim;
 	ultim=p;
 	prim->st=ultim;
 	cout<<endl;
}

void list_st_dr ( nod *& prim ) {
	nod *p=prim;
	cout<<"ordinea de parcurgere:"<<endl;
  do {
    cout<<p->ord<<" ";
    p=p->dr;
  } while ( p!=prim );
  cout<<endl;
}

void list_dr_st ( nod *& ultim ) {
  nod *p=ultim;
	cout<<"ordinea de parcurgere:"<<endl;
  do {
    cout<<p->ord<<" ";
    p=p->st;
  } while ( p!=ultim );
  cout<<endl;
}

void parcurgere ( nod *& prim, nod *& ultim ) {
  nod *p, *q;
  p=prim;
  do {
    q=p;
    rezervor=0;
    do {
      rezervor+=q->combustibil;
      rezervor-=consum * q->distanta;
      q=q->dr;
    } while ( q!=p && rezervor>0 );
    if ( q!=p ) list_st_dr ( p );
    p=p->dr;
  } while ( p!=prim );
  p=ultim; 
  do {
    q=p;
    rezervor=0;
    do {
      rezervor+=q->combustibil;
      rezervor-=consum * q->distanta;
      q=q->st;
    } while ( q!=p && rezervor>0 );
    if ( q!=p ) list_dr_st ( p );
    p=p->st;
  } while ( p!=ultim );
}

int main ( ) {
  int n;
  nod * prim=NULL, *ultim=NULL;
  cout<<"n= ";	cin>>n;
  cout<<"Consumul (la 100 de Km exprimat in litri)= ";	cin>>consum;
  consum=consum/100; 
  creare ( prim, ultim, n );
  parcurgere ( prim, ultim );
  getch ( );
  return 0;
}  
