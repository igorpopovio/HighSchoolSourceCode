//Problema16
//------------------------------------------------------------------------------
//La intrarea intr-o sala de spectacole sunt doua randuri de persoane pastrate
//in doua liste simplu inlantuite de tip coada. Pentru ca exista doar un singur
//angajat care verifica biletele, pe poarta poate sa intre la un moment dat o
//singura persoana. Stiind ca angajatul este corect si permite sa intre alternativ
//cate o persoana din fiecare rand, se cere sa se afiseze ordinea de intrare a
//persoanelor in sala de spectacol (fiecare persoana este identificata prin
//numarul biletului sau)
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

struct nod {
	unsigned bilet;
	nod * adr;
};

int push ( nod *& v, nod *& sf, nod *& c ) {
  nod *p;
 	if ( !v ) {
		v=new nod; 	*v=*c; 
		v->adr=NULL;  sf=v;
	}
	else {
  p=new nod;
  *p=*c;
  sf->adr=p;  
  p->adr=NULL;   sf=p;
  }
  return 1;
}

void meniu ( char & op ) {
  cout<<"1. intrare la prima coada;"<<endl;
  cout<<"2. intrare la a doua coada;"<<endl;
  cout<<"3. afiseaza ordinea de intrare la spectacol;"<<endl;
  cout<<"4. sfarsit program;"<<endl;
  cout<<"Optiunea dvs.: ";	cin>>op;
  cout<<endl<<endl;
}

void listare ( nod *& v1, nod *& v2 ) {
  nod *p,*q;
  p=v1;
  q=v2;
  while ( p && q ) {
    cout<<p->bilet<<"  "; 
    cout<<q->bilet<<"  "; 
    p=p->adr;		q=q->adr;
  }
  if ( !p ) {
    while ( q )	{
      cout<<q->bilet<<"  "; 
      q=q->adr;
    }
  }
  else {
    while ( p ) {
      cout<<p->bilet<<"  "; 
      p=p->adr;
    }
  }        
}    

int main ( ) {
  nod *v1=NULL,*v2=NULL,*c,*sf1,*sf2;
  char op;
  do {
    meniu ( op );
    switch ( op ) {
      case '1': c=new nod;
        				cout<<"Introduceti nr. biletului: ";		cin>>c->bilet;
								push ( v1, sf1, c );
								delete c;
								break;
		  case '2': c=new nod;
        				cout<<"Introduceti nr. biletului: ";		cin>>c->bilet;
								push ( v2, sf2, c );
								delete c;
								break;
			case '3': listare ( v1, v2 );
								break;
		}
  } while ( op !='3' );
  getch ( );
  return 0;
}    		
          							
  
