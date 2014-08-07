//Problema13
//------------------------------------------------------------------------------
//Pe aeroportul Ben Habib bagajele sunt aduse de la aeronava intr-o sala de
//preluat bagaje. In aceasta sala se afla o banda rulanta care are doua capete:
//unul este in exteriorul salii, unde bagajele sunt depuse unul cate unul, iar
//celalalt capat se afla in interior, de unde fiecare calator isi poate ridica
//bagajul atunci cand acesta a ajuns la acest capat. Pe banda intra cel mult 20
//de bagaje. Cunoscand numarul calatorilor care coboara dintr-un avion (fiecare
//are un singur bagaj pe care este scris numele si prenumele), scrieti un 
//program care simuleaza intrarea bagajelor pe banda rulanta si preluarea lor de 
//catre calatori pe baza unui meniu cu optiunile:
// I - intrare bagaj;
// P - preluare bagaj;
// S - sfarsit program;

#include <iostream.h>
#include <conio.h>

struct nod {
	char nume[20],prenume[20];
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

void meniu ( char & op ) {
  cout<<"1. intrare bagaj;"<<endl;
  cout<<"2. preluare bagaj;"<<endl;
  cout<<"3. afisare banda;"<<endl;
  cout<<"4. sfarsit program;"<<endl;
  cout<<"Optiunea dvs.: ";	cin>>op;
  cout<<endl<<endl;
}

void listare ( nod * v ) {
  nod *p;
  p=v;
  while ( p ) {
    cout<<p->nume<<"  "<<p->prenume<<endl;  
    p=p->adr;
  }
}    

int main ( ) {
  nod *v=NULL,*c,*sf;
  char op;
  do {
    meniu ( op );
    switch ( op ) {
      case '1': c=new nod;
        				cout<<"Introduceti numele: ";		cin>>c->nume;
								cout<<"Introduceti prenumele: ";		cin>>c->prenume;
								push ( v, sf, c );
								delete c;
								break;
			case '2': if ( !pop ( v, sf, c ) ) 
   							cout<<"Nu mai sunt bagaje pe banda!"<<endl;
   							break;
			case '3': listare ( v );
								break;
			case '4': break;
		}
  } while ( op !='4' );
}    		
          							
  
