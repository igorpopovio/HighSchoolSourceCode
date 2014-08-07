//Problema6
//------------------------------------------------------------------------------
//In fisierul "examen.in" se gasesc informatiile referitoare la 
//un examen cu doua probe. Pe fiecare linieeste inregistrata
//cate o persoana: nume, nota1, nota2. Creati fisierul "examen.out"
//cu persoanele admise in ordinea descrescatoare a mediilor ( cu
//mediile mai mari sau egale cu 5 ) si fisierul "respinsi.out"
//cu persoanele respinse ( in ordine alfabetica ). Scrierea in 
//fisierele de iesire se va face pe linii numerotate.
//------------------------------------------------------------------------------

#include <conio.h>
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdlib.h>

struct nod {
  char nume[20];
  float nota1, nota2;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int & n ) {
  nod * p, * q;
  char sir[50];
  n=0;
  p=new nod;
  fstream examen ( " examen.in " , ios :: in );
  examen.getline ( sir, 50 );
  strcpy ( p->nume, strtok ( sir, " " ) );
  p->nota1=atof (strtok ( sir, " " ) );
  p->nota2=atof (strtok ( sir, " " ) );
  p->st=p->dr=NULL; prim=ultim=p;   n++;

  while ( ! examen.eof ( ) ) {
    q=new nod;
    examen.getline ( sir, 50 );
    strcpy ( p->nume, strtok ( sir, " " ) );
    p->nota1=atof (strtok ( sir, " " ) );
    p->nota2=atof (strtok ( sir, " " ) );
    p->st=p->dr=NULL; prim=ultim=p;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
    n++;
  }

  examen.close ( );
  ultim=p;
  cout<<endl;
}

void list_st_dr ( nod *& prim ) {
  nod * p;
  p=prim;
  while ( p ) {
  cout<<"p->nume= "<<p->nume<<"  "<<p->nota1<<" "<<p->nota2;  p=p->dr;
  }
  cout<<endl;
}


void memoreaza ( nod *& prim, int & n ) {
  nod * p;
  int k1=-1, k2=-1;
  float medie;
  fstream examen ( " examen.out " , ios :: out );
  fstream respinsi ( " respinsi.out " , ios :: out );
  p=prim;

  while ( p ) {
    if ( ( medie =( p->nota1 + p->nota2 ) / 2 ) >= 5 )
      examen<<k1++<<". "<<p->nume<<" "<<medie<<endl;
    else
      respinsi<<k2++<<". "<<p->nume<<" "<<medie<<endl;
    p=p->dr;
  }
  examen.close ( );
  respinsi.close ( );
}


int main ( ) {
  cout<<"Fisierul \"examen.out\" contine elevii admisi, iar fisierul \"respinsi.out\" contine elevii respinsi!";
  nod * prim, * ultim;
  int n=0;
  creare ( prim, ultim, n );
  list_st_dr ( prim );
  memoreaza ( prim, n );
  getch();
  return 0;
}
