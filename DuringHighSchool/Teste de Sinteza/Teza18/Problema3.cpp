//O matrice de dimensiuni m x n ( m impar ) continand numere reale se stocheaza
//intr-o lista simplu inlantuita, element cu element, ordinea de stocare find
//ordinea de parcurgere a matricei pe linii, dus-intors, ( prima linie de la stanga
//la dreapta, a doua linie de la dreapta spre stanga, urmatoarea linie de la
//stanga spre dreapta etc. ) parcurgerea tabloului incepand de la elementul de 
//coordonate ( m, 1 ) si sfarsind cu elementul ( 1, n ). Apoi din lista obtinuta, 
//se vor elimina elementele care se repeta. Sa se afiseze elementele listei astfel
//obtinute.
//Valorile m si n se citesc de pe prima linie a fisierului "matrice.in" de pe 
//urmatoarele m linii citindu-se cate n numere reale reprezentand elementele
//matricei, pe linii, in parcurgere normala ( de la stanga la dreapta ).
//Dimensiunile maxime ale matricei sunt 20 respectiv 30.

#include <conio.h>
#include <fstream.h>
#include <stdlib.h>
#include <iostream.h>

typedef struct celula {
  float nr;
  celula * leg;
}*adr;
adr caps, ant;
float a[10][10];
fstream f ( "matrice.in", ios::in );

void adaugare ( adr & cap, adr & ant, float inf ) {
  adr crt;
  crt=new celula;
  crt->nr=inf;
  if ( cap==NULL ) cap=crt;
  else ( ant )->leg=crt;
  crt->leg=NULL;
  ant=crt;
}

void afisare ( adr cap ) {
  adr crt;
  crt=cap;
  while ( crt ) {
    cout.precision ( 2 );
    cout<<crt->nr<<"  ";
    crt=crt->leg;
  }
  cout<<endl;
}

void elimin ( adr cap ) {
  adr cr, crt, ant;
  cr=cap;
  while ( cr->leg ) {
    crt=cr->leg;
    ant=cr;
    while ( crt ) {
      if ( cr->nr==crt->nr ) {
        ant->leg=crt->leg;
        delete crt;
        crt=ant;
      }
      ant=crt;
      crt=crt->leg;
    }
    cr=cr->leg;
  }
}

int main ( ) {
  int m, n, i, j;
  f>>m>>n;
  if ( m%2==0 ) exit ( 1 );
  for ( i=0; i<m; i++ )
    for ( j=0; j<n; j++ )
      f>>a[i][j];
  for ( i=m-1; i>-1; i-- )
    if ( ( i+1 )%2 )
      for ( j=0; j<n; j++ ) adaugare ( caps, ant, a[i][j] );
    else
      for ( j=n-1; j>-1; j-- ) adaugare ( caps, ant, a[i][j] );
  cout<<"afisare 1"<<endl;
  afisare ( caps );
  elimin ( caps );
  cout<<"afisare 2"<<endl;
  afisare ( caps );
  f.close ( );
  getch ( );
  return 0;
}  
                
