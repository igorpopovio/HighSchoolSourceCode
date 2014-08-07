//Un elev are un sistem propriu de a-si organiza banii economisiti: el isi depune
//sumele in diverse plicuri distincte scriind pe fiecare plic data cand a depus
//suma respectiva in plic. Cand are de facut cheltuieli, el ia suma necesara din 
//ultimele depuneri, desfiintand plicurile care nu mai contin nici un leu, modificand
//data plicurilor pe care le-a descompletat ( in locul datei depunerii el consemneaza
//pe plic data in care a cheltuit o parte din banii existentii in plicul respectiv )
//Stiind ca ultimii bani incasati sunt primii cheltuiti si nu se cheltuie mai multi
//bani decat cei economisiti si nici nu se i-au bani din doua plicuri in acelasi timp.
//Sa se inregistreze economiile elevului, afisand la final plicurile existente si 
//data inscrisa pe fiecare din acestea precum si suma totala detinuta.

#include <conio.h>
#include <iostream.h>
#include <string.h>

struct nod {
	float suma;
	char data[20];
	nod * adr;
};


void push ( nod *& v, float s, char * d ) {
	nod *c;
	if ( !v ) {
		v=new nod;  v->suma=s;
		strcpy ( v->data, d );
		v->adr=NULL;
	}
	else {
		c=new nod;  c->suma=s;
		strcpy ( c->data, d );
		c->adr=v;   v=c;
	}
}

void pop ( nod *& v, float & s, char *& d ) {
	nod *c;
	if ( !v )  cout<<"stiva este vida;"<<endl;
	else {
		c=v;  
		s=c->suma;
		strcpy ( d, c->data );
		v=v->adr; delete c;
	}
}

void meniu ( char & c ) {
	cout<<"1. Depune bani in plic;"<<endl;
	cout<<"2. Scoate bani din plic;"<<endl;
	cout<<"3. Afiseaza economiile elevului;"<<endl;
	cout<<"Optiunea dumneavoastra: "<<endl;
	cin>>c;
}

int main ( ) {
	nod * v=NULL;
	char c;
	float s, s1;
	char * d;
	d=new char [20];
	do {
		meniu ( c );
		switch ( c ) {
			case '1': 
				cout<<"suma de bani pe care doriti sa o depuneti: ";
				cin>>s;
				cout<<"data depunerii: ";
				cin>>d;
				push ( v, s, d );
				break;
				
			case '2':
				cout<<"suma de bani pe care doriti sa o scoateti: ";
				cin>>s;
				pop ( v, s1, d );
				if ( s1<s ) cout<<"nu puteti scoate o suma mai mare decat cea din ultimul plic!";
				else {
					cout<<"Introduceti noua data de depunere: ";
					cin>>d;
					push ( v, s1-s, d );
				}
				break;
				
			case '3':
				s1=0;
				while ( v ) {
					pop ( v, s, d );
					cout<<"plic: suma: "<<s<<endl;
					cout<<"      data: "<<d<<endl;
					s1+=s;
				}
				cout<<"Suma totala pastrata de elev: "<<s1<<endl;
				break;
				
			default: return 0;
		}
	} while ( c!='t' );
	getch ( );
	return 0;
}
