//Sa se elaboreze subprogramul corespunzator obtinerii unei liste de tip coada
//cu numerele ordonate crescator din elementele celor doua stive care sunt primite
//ca parametri si care contin ( de la baza spre varf ) numere naturale asezate in 
//ordine descrescatoare. Se vor respecta principiile de operare in stiva, respectiv 
//in coada. ( Exemplu practic: intr-un triaj se doreste obtinerea unei garnituri 
//de tren rapid, cu vagoanele numerotate crescator incepand de la locomotiva,
//avand la dispozitie doua trenuri configurate in acelasi fel, deja garate si ale 
//caror vagoane trebuie plasate in noul tren. Trenurile au, teoretic, orice lungime,
//iar decuplarile de vagoane se fac de la coada trenului ).

#include <conio.h>
#include <iostream.h>

typedef struct celula {
  unsigned int nr;
  celula * leg;
}*adr;

adr cap1, cap2, capc;
unsigned int nr;

void creare ( adr & cap ) {
  adr p, crt;
  cap=NULL;
  cout<<"Dati primul numar ";	cin>>nr;
  while ( nr ) {
    crt=new celula;
    crt->nr=nr;
    if ( !cap || nr<=cap->nr ) {
      crt->leg=cap;
      cap=crt;
    }
    else {
      p=cap;
      while ( p->leg && p->leg->nr<nr ) p=p->leg;
      crt->leg=p->leg;
      p->leg=crt;
    }
    cout<<"Dati urmatorul numar: ";		cin>>nr;
  }
}

void afisare ( adr cap ) {
  while ( cap ) {
    cout<<cap->nr<<"  ";
    cap=cap->leg;
  }
  cout<<endl;
}

void adauga ( unsigned int nr, adr & cap, adr & ant ) {
  adr crt;
  crt=new celula;
  crt->nr=nr;
  crt->leg=NULL;
  if ( cap==NULL ) cap=crt;
  else ant->leg=crt;
  ant=crt;
}

void coada ( adr c1, adr c2, adr & cap ) {
  adr ant;
  cap=NULL;
  ant=cap;
  while ( c1 && c2 ) 
    if ( c1->nr<=c2->nr ) {
      adauga ( c1->nr, cap, ant );
      c1=c1->leg;
    }
    else {
      adauga ( c2->nr, cap, ant );
      c2=c2->leg;
    }
    if ( c1==NULL ) 
      while ( c2 ) {
        adauga ( c2->nr, cap, ant );
        c2=c2->leg; 
      }
    else 
      while ( c1 ) {
        adauga ( c1->nr, cap, ant );
        c1=c1->leg; 
      }
}

int main ( ) {
  cout<<"Dati numerele naturale ale listei 1, zero la sfarsit"<<endl;
  creare ( cap1 );
  cout<<"Dati numerele naturale ale listei 2, zero la sfarsit"<<endl;
  creare ( cap2 );
  coada ( cap1, cap2, capc );
  cout<<"Afisare lista-coada"<<endl;
  afisare ( capc );
  getch ( );
  return 0;
}  
                         
