//Pentru numarul natural nenul n<30000 ( dat de la tastatura ), se considera
//toate numerele naturale de la 1 la n asezate, in ordine, pe un cerc. Pe colierul
//de numere astfel format, deplasandu-se de la 1 spre 2, 3, ..., n, 1, 2, 3 ...
//se efectueaza urmatoarele operatii: se elimina 1, se sare peste 2, apoi se elimina
//secventa formata din urmatoarele doua numere, se sare peste urmatoarele doua numere
//se elimina secventa formata din urmatoarele 3 numere, se trece peste urmatoarele
//3 numere, etc. Sirul de operatii se incheie cand nu mai este posibila eliminarea
//integrala a unei secvente ( nemaiexistand suficiente elemente pe cerc ).
//Se cere sa se afiseze pe ecran numarul de elemnte ramase in final si sa se scrie
//in fisierul "colier.out" numerele ramase, in ordine crescatoare.

#include <conio.h>
#include <fstream.h>
#include <iostream.h>

fstream f ( "colier.out", ios::out );
int i, j, n;
struct element {
  int n;
  element * next;
};

element *p, *q, *r;

void insereaza ( int i ) {
  r=new element;
  r->n=i;
  if ( !p ) p=r;
  else q->next=r;
  delete r;
}

void elimina ( ) {
  r=q->next;
  q->next=q->next->next;
  delete r;
}

int main ( ) {
  cout<<"n= ";	cin>>n;
  if ( n==1 ) f<<0;
  else {
    //crearea listei
    p=NULL;
    for ( i=1; i<=n; i++ ) insereaza ( i );
    q->next=p;	//legatura de inchidere a colierului
    i=1;
    do {
      for ( j=1; j<=i; j++ ) elimina ( );
      for ( j=1; j<=i; j++ ) q=q->next;
      n=n-i;
      i++;
    } while ( n>=i );
    cout<<n;
    if ( n>0 ) {
      //cautarea inceputului secventei crescatoare
      while ( q->n<q->next->n ) q=q->next;
      p=q;
      do {
        //listare
        q=q->next;
        f<<q->n<<" ";
      } while ( q!=p );
    }
  }
  f.close ( );
  getch ( );
  return 0;
}
              
