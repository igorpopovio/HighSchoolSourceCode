//Fisierele depuse pe un hard-disc sunt memorate in directoare organizate exact 
//ca un arbore binar. Fiecare nod al arborelui contine cel mult doua subdirectoare 
//subordonate direct si o informatie ( numarul de fisiere din directorul 
//propriu-zis, in care nu sunt incluse fisierele din subdirectoarele subordonate ).
//Arborele memoreaza doar numerele de fisiere in campurile, nu si denumirile 
//subdirectoarelor.
//Se doreste sa selectam directoarele ce contin un numar de fisiere cuprins
//strict intre doua valori citite de la tastatura ( x,y numere naturale, x<y ).
//Numerele de fisiere din directoarele selectate se vor memora intr-o lista
//simplu inlantuita.

#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>

struct nod1 {
  int info1;
  nod1 * urm;
};

struct nod {
  int info;
  nod * st, *dr;
};

nod *r;
nod1 *p, *p3;
char m[80];
int x, y;

void read_arb ( char m[12], nod *& a ) {
  char ch, c[80];
  cout<<"Exista nodul "<<m<<" ? (y/n)";
  cin>>ch;
  if ( tolower ( ch )=='y' ) {
    a=new nod;
    cout<<"Nr. de fisiere din "<<m<<"= ";	cin>>a->info;
    strcpy ( c, m );	read_arb ( strcat ( c, "^.st" ), a->st );    
    strcpy ( c, m );	read_arb ( strcat ( c, "^.dr" ), a->dr );
  }
  else a=NULL;
}

void rsd ( nod * arb ) {
  if ( arb ) {
    cout<<arb->info<<" ";
    rsd ( arb->st );
    rsd ( arb->dr );
  }
}

void insereaza ( nod * q ) {
  nod1 * p1;
  p1=new nod1;
  p1->info1=q->info;
  p1->urm=NULL;
  if ( !p ) p=p1;
  else p3->urm=p1;
  p3=p1;
}

void proc ( nod * r ) {
  if ( r ) {
    if ( r->info>x && r->info<y ) insereaza ( r );
    proc ( r->st );
    proc ( r->dr );
  }
}

void scrie ( nod1 * p ) {
  while ( p ) {
    cout<<p->info1<<" --> ";
    p=p->urm;
  }
  cout<<"NULL"<<endl;
}

int main ( ) {
  cout<<"Nume radacina= ";	cin>>m;
  read_arb ( m, r );
  cout<<"Parcurgere radacina-stanga-dreapta: ";
  rsd ( r );  cout<<endl;
  do {
    cout<<"Valoarea limita stanga= ";	cin>>x;
    cout<<"Valaorea limita dreapta= ";	cin>>y;
  } while ( x>=y );
  p=NULL;
  proc ( r );
  if ( p ) scrie ( p );
  else cout<<"Lista este vida!"<<endl;
  getch ( );
  return 0;
}                    
