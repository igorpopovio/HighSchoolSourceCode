//Se considera un teanc de n halate colorate, pentru fiecare halat, pornind de la
//baza teancului, identificam culoarea sa cu o litera mare, k angajati ( k<=15 )
//identificati prin numere de la 1 la k iau la inceputul programului din teanc
//cate un halat ( cel situat deasupra programului ), il folosesc un timp si-l
//aseaza la loc deasupra teancului existent.
//Se precizeaza pentru fiecare angajat durata de utilizare a halatului.
//Daca doi angajati aduc halatul in acelasi timp, cel mai tanar ( cu nr. de ordine
//mai mare ) da prioritate celui mai in varsta.
//Sa se determine ordinea finala a halatelor in teanc.

#include <conio.h>
#include <iostream.h>

struct nod {
  char culoare;
	nod * adr;
};

struct angajat {
	int NrCrt;	//numarul de ordine al angajatului
	int durata; //durata de utilizare a halatului
	char cul;		//culoarea halatului imprumutat
};

void push ( nod *& v, char x ) {
	nod *c;
	if ( !v ) {
		v=new nod;  v->culoare=x;
		v->adr=NULL;
	}
	else {
		c=new nod;  c->culoare=x;
		c->adr=v;   v=c;
	}
}

void pop ( nod *& v, char & x ) {
	nod *c;
	if ( !v )  cout<<"stiva este vida;"<<endl;
	else {
		c=v;  x=c->culoare;
		v=v->adr; delete c;
	}
}

void sortare ( angajat a[], int n ) {
	int g=0;
	angajat aux;
	while ( !g ) {
		g=1;
		for ( int i=0; i<(n-1); i++ ) {
			if ( a[i].durata>a[i+1].durata ) {
				aux=a[i];
				a[i]=a[i+1];
				a[i+1]=aux;
				g=0;
			}
		}
	}
}

void listare ( nod * v ) {
	while ( v ) cout<<v->culoare;
}

int main ( ) {
	nod * v=NULL;		// pointerul v este folosit pentru a memora teancul de halate
	int n, k;
	char x;
	angajat personal[15]; 
	// vectorul personal este folosit pentru a sorta crescator angajatii dupa durata
	// de utilizare a halaturilor
	cout<<"Introduceti numarul de halate:\nn= ";	cin>>n;
	cout<<"Introduceti numarul de angajati:\nk= ";	cin>>k;
	cout<<"Introduceti culoarea fiecarui halat ( un singur caracter pentru fiecare halat ):";
	for ( int i=0; i<n; i++ ) {
		cout<<"halatul "<<(i+1)<<": ";	cin>>x;
		push ( v, x );
	}
	cout<<"Introduceti duratele de utilizare a halatelor pentru fiecare angajat:"<<endl;
	for ( int i=0; i<k; i++ ) {
		pop ( v, x );
		personal[i].cul=x;
		cout<<"Angajatul "<<(i+1)<<": ";	cin>>personal[i].durata;
		personal[i].NrCrt=i;
	}
	sortare ( personal, k );
	for ( int i=0; i<k; i++ ) {
		push ( v, personal[i].cul );
	}
	cout<<"Ordinea halatelor dupa terminarea programului: ";
	for ( int i=0; i<n; i++ ) {
		pop ( v, x );
		cout<<x;
	}
	getch ( );
	return 0;
}
		
