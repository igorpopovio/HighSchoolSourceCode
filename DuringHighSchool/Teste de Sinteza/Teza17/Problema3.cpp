//Se creeaza doua liste simplu-inlantuite, A si B, de numere naturale, incarcarea 
//lor oprindu-se, pentru fiecare, cand se intalneste un numar nul. Sa se gaseasca
//un procedeu eficient de obtinere a valorii maxime a sumei a1*b1+a2*b2+...+ak*bk,
//unde elemnele de tip a sunt numere oarecare din lista A, elementele de tip b
//sunt numere de tip oarecare din lista B, k fiind un numar natural citit si 
//k<=min {lung A, lung B}.

#include <conio.h>
#include <iostream.h>

typedef struct celula {
  unsigned int nr;
  celula * leg;
}*adr;
adr capa, crta, capb, crtb;
unsigned la, lb, nr, s;

void creare ( adr & cap, unsigned & l ) {
  adr crt;
  cout<<"Dati primul numar ";	cin>>nr;
  while ( nr ) {
    l++;
    crt=new celula;
    crt->nr=nr;
    crt->leg=cap;
    cap=crt;
    cout<<"Dati alt nr. ";	cin>>nr;
  }
}

void afisare ( adr cap ) {
  while ( cap ) {
    cout<<cap->nr<<"  ";
    cap=cap->leg;
  }
  cout<<endl;
}

void ordon ( adr cap ) {
  adr crt;
  int f;
  unsigned aux;
  do {
    f=1;
    crt=cap;
    while ( crt->leg ) {
      if ( crt->nr<crt->leg->nr ) {
        aux=crt->nr;
        crt->nr=crt->leg->nr;
        crt->leg->nr=aux;
        f=0;
      }
      crt=crt->leg;
    }
  } while ( !f );
}

int main ( ) {
  int i, k, min;
  la=0;
  lb=0;
  cout<<"Citire numere pentru lista A ( zero la sfarsit )"<<endl;
  capa=NULL;
  creare ( capa, la );
  ordon ( capa );
  afisare ( capa );   
  cout<<"Citire numere pentru lista B ( zero la sfarsit )"<<endl;
  capb=NULL;
  creare ( capb, lb );
  ordon ( capb );
  afisare ( capb ); 
  min=la;
  if ( min>lb ) min=lb;
  do {
    cout<<"Dati valoarea lui k( k<"<<min+1<<" )= ";	cin>>k;
  } while ( k>min );
  s=0;
  crta=capa;
  crtb=capb;
  for ( i=1; i<=k; i++ ) {
    s=s+crta->nr*crtb->nr;
    crta=crta->leg;
    crtb=crtb->leg;
  }
  cout<<"Suma maxima este: "<<s<<endl;
  getch ( );
  return 0;
}    
    
                       
