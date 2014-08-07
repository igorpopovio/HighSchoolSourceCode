//Se citeste un sir de cuvinte care se termina cu un cuvant care incepe cu semnul .
//( punct ). Cuvintele se introduc de la tastatura, cate unul pe linie. Sa se
//afiseze cuvintele in ordine alfabetica, folosind pentru memorarea cuvintelor
//o singura lista alocata dinamic. Un cuvant are cel mult 20 de caractere.

#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct celula {
  char cuv[20];
  celula * leg;
}*adr;
adr caps;
char cuv[20];

void creare ( adr & cap, char inf[] ) {
  adr crt;
  crt=new celula;
  strcpy ( crt->cuv, inf );
  crt->leg=cap;
  cap=crt;
}
void afisare_lista ( adr cap ) {
  while ( cap ) {
    puts ( cap->cuv );
    cap=cap->leg;
  }
}

void ordon ( adr cap ) {
  adr crt;
  int f;
  char aux[20];
  do {
    f=1;
    crt=cap;
    while ( crt->leg ) {
      if ( strcmp ( crt->cuv, crt->leg->cuv )>0 ) {
        strcpy ( aux, crt->cuv );
        strcpy ( crt->cuv, crt->leg->cuv );
        strcpy ( crt->leg->cuv, aux );
        f=0;
      }
      crt=crt->leg;
    }
  } while ( !f );
}

int main ( ) {
  caps=NULL;
  puts ( "Dati un cuvant " );
  gets ( cuv );
  while ( cuv[0]!='.' ) {
    creare ( caps, cuv );
    puts ( "Dati alt cuvant, pana incepe cu . " );
    gets ( cuv );
  }
  ordon ( caps );  
  puts ( "Afisare lista " );
  afisare_lista ( caps );
  getch ( );
  return 0; 
}
          
          
