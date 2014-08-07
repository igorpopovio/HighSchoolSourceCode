//Se cere sa se scrie o procedura care sa citeasca de la tastatura numere 
//naturale ce reprezinta note obtinute de un grup de elevi la un examen ( cate o nota
//pentru fiecare elev ). Citirea se termina atunci cand se introduce numarul 0.
//Notele mai mari decat 4 se vor introduce intr-o lista simplu inlantuita, iar
//celelalte in alta lista, tot simplu inlantuita.
//Procedura va intoarce patru valori:
  //-doua numere naturale m si n reprezentand numarul de note de promovare
  //(adica numarul de note mai mari decat 4), respectiv numarul celorlalte note;
  //-doi pointeri la inceputul celor doua liste. Daca o lista este vida, pointerul
  //respectiv va contine constanta NULL.
//Cerinte:
  //a) sa se scrie procedura descrisa mai sus;
  //b) sa se precizeze declaratiile necesare din programul principal;
  //c) sa se scrie instructiunea din programul principal care apeleaza aceasta
  //procedura.
  
#include <iostream.h>
#include <conio.h>

struct pnod {
  int info;
  pnod * urm;
};
pnod * c1, * c2;
void listare ( pnod * v ) {
  pnod * c=v;
  while ( c ) {
    cout<<c->info<<endl;
    c=c->urm;
  }
}

void p ( int & m, int & n, pnod *& v1, pnod *& v2 ) {
  int a;
  cout<<"a= ";	cin>>a;
  if ( a>4 ) {
    if ( !v1) {
      v1=new pnod;	v1->info=a;
      v1->urm=NULL;	c1=v1;
    }
    else {
      c1->urm=new pnod;	c1=c1->urm;
      c1->urm=NULL;	c1->info=a;
    }
    m++; p( m, n, v1, v2 );
  }  
  else 
 		if ( a>0 ) {
      if ( !v2 ) {
          v2=new pnod;	v2->info=a;
          v2->urm=NULL;	c2=v2;
      }  
      else {
        c2->urm=new pnod;	c2->urm->urm=NULL;
        c2->urm->info=a;	c2=c2->urm;
      }
      n++;	p( m, n, v1, v2 );
    }
  else return;
}

int main ( ) {
  pnod * v1=NULL, * v2=NULL;
  int m=0, n=0;;
  p ( m, n, v1, v2 );
  listare ( v1 ); cout<<"elemente "<<m<<endl;
  listare ( v2 ); cout<<"elemente "<<n<<endl;  
  getch ( );
  return 0;
}
                    
