//Un subprogram primeste ca parametru adresa radacinii unui arbore binar
//oarecare, care contine in fiecare nod un numar natural. Realizati acest subprogram
//astfel incat el sa creeze o lista simplu-inlantuita ordonata crescator din elementele
//de pe frunzele arborelui, numai daca acestea sunt distincte, altfel se intoarce
//o adresa nula, prin care se codifica faptul ca nu s-a creat lista.

#include <iostream.h>
#include <conio.h>

typedef struct arb {
  int n;
  arb *s, *d;
}*nod;
typedef struct cel {
  int n;
  cel * leg;
}*adr;
int n;
nod r;
adr lis;

void crearb ( nod & r ) {
  int n;
  cin>>n;
  if ( n==0 ) r=NULL;
  else {
    r=new arb;
    r->n=n;
    crearb ( r->s );
    crearb ( r->d );
  }
}

void inser ( adr & cap, int inf ) {
  adr crt;
  crt=new cel;
  crt->n=inf;
  crt->leg=cap;
  cap=crt;
}

void afisare ( adr cap ) {
  while ( cap ) {
    cout<<cap->n<<endl;
    cap=cap->leg;  
  }
}

void ordon ( adr cap ) {
  adr crt;
  int f, aux;
  do {
    f=1;
    crt=cap;
    while ( crt->leg ) {
      if ( crt->n > crt->leg->n ) {
        aux=crt->n;
        crt->n=crt->leg->n;
        crt->leg->n=aux;
        f=0;
      }
      crt=crt->leg;
    }
  } while ( !f );
}

void lisfrunze ( nod r ) {
  if ( r ) {
    if ( r->s==NULL && r->d==NULL ) inser ( lis, r->n );
    lisfrunze ( r->s );
    lisfrunze ( r->d );
  }
}

void subprg ( nod r ) {
  adr crt, urm;
  int f;
  lisfrunze ( r );
  ordon ( lis );
  crt=lis;
  f=1;
  while ( crt->leg && f ) {
    urm=crt->leg;
    while ( urm && f ) {
      if ( crt->n==urm->n ) f=0;
      urm=urm->leg;
    }
    crt=crt->leg;
  }
  if ( !f ) lis=NULL;
}

int main ( ) {
  cout<<"Dati nr. in arbore, 0 pt. descendent inexistent"<<endl;
  crearb ( r );
  subprg ( r );
  if ( lis ) afisare ( lis );
  else cout<<"Nu se poate"<<endl;
  getch ( );
  return 0;
}
                                 
