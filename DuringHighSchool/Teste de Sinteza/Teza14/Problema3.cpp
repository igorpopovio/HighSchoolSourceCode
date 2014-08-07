//Se creeaza o lista continand numere naturale, citirea datelor facandu-se pana
//la intalnirea numarului 0. Crearea listei se va face pe principiul insertiei unui
//element nou la sfarsitul listei curente. Se aleg din lista acele numere care
//au exact k divizori proprii, se vor afisa si se vor sterge din lista;
//k este un numar natural citit de la tastatura.

#include <iostream.h>
#include <conio.h>

typedef struct celula {
  int nr;
  celula * leg;
}*adr;

adr cap, crt, ant;

void adaugare ( int inf ) {
  adr crt;
  crt=new celula;
  crt->nr=inf;
  crt->leg=cap;
  cap=crt;
}

void afisare ( ) {
  adr cr=cap;
  while ( cr!=NULL ) {
    cout<<cr->nr<<" ";
    cr=cr->leg;
  }
  cout<<endl;
}

int nr_diviz ( int n ) {
  int d=2, m=0, a=n/2;
  while ( d<=a ) {
    if ( n%d==0 ) m++;
    d++;
    return m;
  }
}

void sterg ( adr * crt, adr * ant ) {
  if ( *crt==cap ) {
    cap=cap->leg;
    *ant=cap;
  }
  else ( *ant )->leg=( *crt )->leg;
  delete ( *crt );
  *crt=*ant;
}

int main ( ) {
  int k, nr, s;
  cap=NULL;
  cout<<"Dati primul numar ";	cin>>nr;
  while ( nr ) {
    adaugare ( nr );
    cout<<"Dati urmatorul numar, zero pentru terminare ";
    cin>>nr;
  }
  cout<<"Dati numarul k ";	cin>>k;
  cout<<"afisare lista"<<endl;
  afisare ( );
  crt=cap;
  ant=cap;
  while ( crt ) {
    if ( nr_diviz ( crt->nr )==k ) {
      cout<<crt->nr<<" are exact "<<k<<" divizori proprii"<<endl;
      sterg ( &crt, &ant );
    }
    else {
      ant=crt;
      crt=ant->leg;
    }
  }
  cout<<"Rest lista "<<endl;
  afisare ( );
  getch ( );
  return 0;
}                      
