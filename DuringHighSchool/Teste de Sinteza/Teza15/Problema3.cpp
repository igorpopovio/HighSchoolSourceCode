//Dupa ce se creeaza o lista simplu-inlantuita circulara care contine numarul
//de ordine ( incepand cu 1 ) si numele fiecarui copil dintr-un grup de copii
//asezati in cerc, se va realiza listarea numarului si numelui acelui copil
//care mai ramane in lista dupa ce s-au eliminat din lista fiecare al p-lea
//copil, incepand de la primul care a fost inscris in lista, p fiind un numar 
//natural citit. Citirea numerelor si numelor copiilor se termina cand s-a intalnit
//sfarsitul de fisier standard de intrare ( CTRL + Z )

#include <conio.h>
#include <iostream.h>
#include <string.h>

typedef struct cel {
  int nr;
  char nume[10];
  cel * leg;
}*adr;
adr cap, ant;

void adaugare ( int inf, char sir[] ) {
  adr crt;
  crt=new cel;
  crt->leg=NULL;
  crt->nr=inf;
  strcpy ( crt->nume, sir );
  if ( cap==NULL ) cap=crt;
  else ant->leg=crt;
  ant=crt;
}

void afisare ( ) {
  adr crt;
  crt=cap;
  do {
    cout<<crt->nr<<" "<<crt->nume<<endl;
    crt=crt->leg;
  } while ( cap!=crt->leg );
}

void elimin ( int p ) {
  adr crt;
  int i;
  crt=cap;
  while ( crt!=crt->leg ){
    for ( i=1; i<p; i++ ) {
      ant=crt;
      crt=crt->leg;
    }
    ant->leg=crt->leg;
  }
  cout<<"a ramas "<<crt->nr<<" "<<crt->nume;
}

int main ( ) {
  int nr, p;
  char den[10];
  cap=NULL;
  ant=cap;
  while ( cin.good ( ) ) {
    cin>>nr>>den;
    adaugare ( nr, den );
  }
  cin.clear ( );
  cout<<"Pasul de eliminare ";	cin>>p;
  ant->leg=cap;
  afisare ( );
  elimin ( p );
  getch ( );
  return 0;
}                 
