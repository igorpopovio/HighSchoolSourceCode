//Sa se creeze un arbore binar de cautare din numere naturale pana la intalnirea
//sfarsitului de fisier standard de intrare, dupa care se va incerca inserarea
//unei noi valori citite in continuare. Daca inserarea s-a realizat, se va crea
//si afisa o lista a valorilor din nodurile arborelui ordonata descrescator.

#include <conio.h>
#include <iostream.h>

typedef struct arb {
  int n;
  arb *s, *d;
}*nod;

typedef struct cel {
  int n;
  cel *leg;
}*adr;

nod r;
adr lis, ant, cap;
int m, id;

void crarb ( nod & r, int m ) {
  if ( r==NULL ) {
    r=new arb;
    r->n=m;
    r->s=NULL;
    r->d=NULL;
  }
  else if ( r->n!=m )
  			 if ( r->n>m ) crarb ( r->s, m );
         else crarb ( r->d, m );
       else id++;
}

void crlis ( int m ) {
  lis=new cel;
  lis->n=m;
  lis->leg=NULL;
  if ( cap==NULL ) cap=lis;
  else ant->leg=lis;
  ant=lis;
}

void drs ( nod r ) {
  if ( r ) {
    drs ( r->d );
    crlis ( r->n );
    drs ( r->s );
  }
}

void afisare ( adr crt ) {
  while ( crt ) {
    cout<<crt->n<<" ";
    crt=crt->leg;
  }
  cout<<endl;
}

int main ( ) {
  cout<<"dati valori pt. arbore, la sf. CTRL+Z ";	cin>>m;
  id=0;
  while ( cin.good ( ) ) {
    crarb ( r, m );
    cout<<"Dati o noua valoare ";	cin>>m;
  }
  id=0;
  crarb ( r, m );
  if ( id ) {
    cap=NULL;
    ant=cap;
    drs ( r );
    cout<<"Valorile din arbore ordonate descrescator ";
    afisare ( cap );
  }
  else cout<<"Lista nu s-a creat. Noua valoare exista deja";
  getch ( );
  return 0;
}
      
                      
