//Sa se construiasca un arbore binar care cuprinde stramosii unei persoane al carei
//nume figureaza in radacina arborelui. Nodul care se afla in stanga unui nod oarecare
//cuprinde numele tatalui persoanei din nodul respectiv, iar nodul din dreapta pe cel
//al mamei. Stramosii se citesc corespunzator parcurgerii in preordine a arborelui,
//un descendent stang sau drept ( tatal sau mama ) necunoscut precizandu-se prin
//introducerea numelui format numai din caracterul '.'.
//Fiind dat numele unei persoane oarecare din familie, sa se afiseze numele bunicilor,
//daca acestia figureaza in arbore. Sa se utilizeze structuri dinamice de date
//pentru memorarea arborelui.

#include <iostream.h>
#include <string.h>
#include <conio.h>

struct nod {
  char nume[15];
  nod * st, * dr;
};

nod * rad=NULL;
char nume_dat[15], nume[15];

void arbore ( nod *& p ) {
  //creare arbore binar
  cout<<"numele: ";		
  cin>>nume;
  if ( strcmp ( nume, "." )!=0 ) {
    p=new nod;
    strcpy ( p->nume, nume );
    arbore ( p->st );
    arbore ( p->dr );
  }
  else p=NULL;
}

void preord ( nod * p ) {
  //parcurgerea arborelui in preordine
  if ( p )
  	if ( strcmp ( p->nume, nume_dat )==0 ) {
     if ( p->st ) {
       cout<<"bunicii din partea tatalui:\n";
       if ( p->st->st ) cout<<p->st->st->nume<<endl;
       if ( p->st->dr ) cout<<p->st->dr->nume<<endl;
     }
     if ( p->dr ) {
       cout<<"bunicii din partea mamei:\n";
       if ( p->dr->st ) cout<<p->dr->st->nume<<endl;
       if ( p->dr->dr ) cout<<p->dr->dr->nume<<endl;
     }
   }
   else {
     preord ( p->st );
     preord ( p->dr );
   }
} 

int main ( ) {
  arbore ( rad );
  cout<<endl;
  cout<<"Dati numele pe care il cautati: ";		cin>>nume_dat;
  preord ( rad );
  getch ( );
  return 0; 
}
                 
