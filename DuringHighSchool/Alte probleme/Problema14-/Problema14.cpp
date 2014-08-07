//In fisierul "poligon.in" se citeste de pe prima linie numarul de varfuri
//ale unui poligon convex, apoi se citesc coordonatele varfurilor poligonului,
//date in ordinea trigonometrica. Sa se construiasca o lista simplu inlantuita
//circulara, care sa memoreze in ordinea data varfurile poligonului, apoi
//sa se determine aria.

#include <iostream.h>
#include <fstream.h>
#include <conio.h>

struct nod {
  float x,y;
  nod *adr;
};

void creare ( nod *& prim, nod *& ultim ) {
  nod *p,*q;
  unsigned n; 
  fstream fis ( "poligon.in", ios::in );
  fis>>n;
  p=new nod;
  fis>>p->x;     fis>>p->y;
  prim=p;
  for ( int i=2; i<=n; i++ ) {
  	q=new nod;
  	fis>>p->x;     fis>>p->y;
  	p->adr=q;      q->adr=prim;   ultim=p=q;
  }
  fis.close ( );
  cout<<endl;
}

void listare ( nod * prim ) {
  nod *p;
  cout<<"p->x= "<<prim->x<<"  "<<"p->y= "<<prim->y<<endl;  p=prim->adr;
  while ( p!=prim ) {
    cout<<"p->x= "<<p->x<<"  "<<"p->y= "<<p->y<<endl;  p=p->adr;
  }
  cout<<endl<<endl;
}


int main ( ) {
  nod *prim,*ultim;
  cout<<"1. creez o lista circulara simplu inlantuita cu n noduri"<<endl;
  cout<<"ce contine coordonatele varfurilor unui poligon convex"<<endl;
  cout<<"din fisierul \"poligon.in\":"<<endl;        creare ( prim, ultim );
  cout<<"2. listez continutul listei;"<<endl;        listare ( prim );
  getch ( );
  return 0;
}
