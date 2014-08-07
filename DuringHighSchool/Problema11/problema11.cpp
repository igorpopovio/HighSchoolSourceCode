//Problema11
//------------------------------------------------------------------------------
//La un cabinet stomatologic cu un singur medic, pacientii sunt consultati in 
//ordinea sosirii. Exceptiile sunt cazurile de urgenta care intra la consultatie
//imediat ce se elibereaza scaunul. Scrieti un program care lucreaza pe baza
//unui meniu pentru planificarea consultatiilor. Pacientii se identifica prin
//nume. Meniul va avea urmatoarele optiuni:
// P - sosire pacient;
// U - sosire urgenta;
// E - eliberare scaun;
// L - listarea pacientiilor de la rand;
//
//------------------------------------------------------------------------------
#include <iostream.h>
#include <conio.h>

struct nod {
	char nume[20];
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

int pop ( nod *& v, nod *& sf, nod *& c ) {
	if ( !v )  return 0;
	else {
	c=v;  v=v->adr; delete c;	return 1;
	}
}

int push_emergency ( nod *& v, nod *& sf, nod *& c ) {
  nod *p;
  p=new nod;
  strcpy ( p->nume, c->nume );
  p->adr=v->adr;
  v->adr=p;
  return 1;
}  

void meniu ( char & op ) {
  cout<<"P - sosire pacient;"<<endl;
  cout<<"U - sosire urgenta;"<<endl;
  cout<<"E - eliberare scaun;"<<endl;
  cout<<"L - listarea pacientilor de la rand;"<<endl;
  cout<<"Optiunea dvs.: ";	cin>>op;
  cout<<endl<<endl;
}

void listare ( nod * v ) {
  nod *p;
  p=v;
  while ( p ) {
    cout<<p->nume<<endl;  
    p=p->adr;
  }
}    

int main ( ) {
  nod *v=NULL,*c,*sf;
  char op;
  do {
    meniu ( op );
    switch ( op ) {
      case 'P': c=new nod;
        				cout<<"Introduceti numele: ";		cin>>c->nume;
								push ( v, sf, c );
								delete c;
								break;
			case 'E': if ( !pop ( v, sf, c ) ) 
   							cout<<"Nu mai sunt pacienti la coada!"<<endl;
   							break;
			case 'L': listare ( v );
								break;
			case 'U': c=new nod;
        				cout<<"Introduceti numele: ";		cin>>c->nume;
								push_emergency ( v, sf, c );
								delete c;
        				break;
		}
  } while ( op !='4' );
}    		
          							
  
