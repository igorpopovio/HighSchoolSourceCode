//Sa se conceapa o structura de date dinamica pentru memorarea unei matrice rare
//( matrice de dimensiuni foarte mari care are majoritatea elementelor egale cu
//zero ). In structura de date sunt reprezentate numai valorile nenule din matrice
//pentru fiecare element nenul memorandu-se si pozitia acestuia in tablou.
//Scrieti un program care sa creeze structura conceputa citind din fisierul text
//"f.in" de pe prima linie valorile m si n reprezentand dimensiunile tabloului, iar
//de pe urmatoarele n linii  cate m numere naturale despartite prin spatii reprezentand
//elementele tabloului. Sa se afiseze cel mai mare element nenul cu proprietatea
//ca divide suma tuturor elementelor tabloului, precizand linia si coloana pe 
//care se afla.

#include <iostream.h>
#include <conio.h>
#include <fstream.h>

struct ref {
  int lin, col, inf;
  ref* urm;
};
ref *vf,*p,*q;
int s,i,j,info,m,n;

int main ( ) {
  ifstream f( "f.in" );
  f>>m>>n;
  vf=0;	s=0;
  for ( i=1; i<=m; i++ )
  for ( j=1; j<=n; j++ ) {
    f>>info;
    if ( info ) {
      p=new ref;
      p->lin=i;	p->col=j;
      p->inf=info;
      p->urm=vf;
      vf=p;
      s+=info;
    }
  }
  p=vf;	q=0;
  while ( p ) {
    if ( ( s%p->inf==0 ) && (!q || q->inf<p->inf ) ) q=p;
    p=p->urm;
  }
  if ( !q ) cout<<"Nu exista un astfel de element\n";
  else {
    cout<<"Elementul cerut este: "<<q->inf<<endl;
    cout<<"El se afla pe linia: "<<q->lin;
    cout<<", coloana: "<<q->col<<endl;
  }
  f.close ( );
  getch ( );
  return 0;
}         
