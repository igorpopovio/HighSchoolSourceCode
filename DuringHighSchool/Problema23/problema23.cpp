//Problema23
//------------------------------------------------------------------------------
//Gestionati informatia dintr-o agenda telefonica utilizand o lista alocata dinamic.
//Informatiile inscrise pentru un abonat telefonic sunt: nume, prenume, adresa
//si numar de telefon. Se vor avea in vedere urmatoarele operatii:
// - adaugarea unui nou abonat;
// - cautarea numarului de telefon al unui anumit abonat de la o anumita adresa;
// - schimbarea numarului de telefon sau a adresei unui anumit abonat;
// - stergerea unui anumit abonat;
//
//------------------------------------------------------------------------------

#include <iostream.h>
#include <string>
#include <conio.h>

struct nod {
	char nume[20],prenume[20],adresa[20],nrTel[10];
	nod *adr;
};

void listare ( nod *& prim ) {
	nod * p;
  p=prim;
  cout<<endl<<endl;
	while ( p ) {
    cout<<"p->nume= "<<p->nume<<endl;
    cout<<"p->prenume= "<<p->prenume<<endl;
    cout<<"p->adresa= "<<p->adresa<<endl;
    cout<<"p->nrTel= "<<p->nrTel<<endl; 
    cout<<endl<<endl; 
    p=p->adr;
  }
	cout<<endl<<endl;
}

void adaugare ( nod *& prim ) {
  nod *p;
  p=new nod;
  cout<<"p->nume= ";  cin>>p->nume;
	cout<<"p->prenume= ";  cin>>p->prenume;
	cout<<"p->adresa= ";  cin>>p->adresa;
	cout<<"p->nrTel= ";  cin>>p->nrTel;
	p->adr=NULL;
	if ( !prim ) prim=p;
	else {
	  p->adr=prim;
	  prim=p;
	}  
}

void stergere ( nod *& prim, char numePersoana[] ) {
  nod *p,*q,*r;
  if ( !stricmp ( prim->nume, numePersoana ) ) {
    r=prim;		prim=prim->adr;		delete r;
  }
  else {
    q=prim->adr;	p=prim;
    while ( q && !stricmp ( q->nume, numePersoana ) ) { p=q;	q=q->adr;}
    if ( !q ) cout<<"Persoana cu numele "<<numePersoana<<" nu exista in lista!";
    else {
      r=q;
      p->adr=q->adr;
      delete r;
      listare ( prim );
    }
  }
}

void cautatelefon ( nod *& prim, char adresaPersoana[] ) {
  nod *p,*q;
  p=prim->adr;	q=prim;
  if ( !stricmp ( prim->adresa, adresaPersoana ) )
  cout<<endl<<"Persoana cu adresa "<<prim->adresa
  				 <<" are nrTel= "<<prim->nrTel; 	cout<<endl;
  while ( !stricmp ( p->adresa, adresaPersoana ) && p ) { q=p;	p=p->adr;}
  if ( !p ) cout<<"Persoana cu adresa "<<adresaPersoana<<" nu exista in lista!";
  else cout<<endl<<"Persoana cu adresa "<<q->adresa
  				 <<" are nrTel= "<<q->nrTel;	cout<<endl;
}
	 
void schimbatelefon ( nod *& prim, char numePersoana[], char nrTel[] ) {
  nod *p,*q;
  p=prim->adr;	q=prim;
  if ( !stricmp ( prim->nume, numePersoana ) ) {
  	cout<<endl<<"Persoana cu numele "<<numePersoana
			  	<<" are vechiul nrTel= "<<prim->nrTel;
  	strcpy ( prim->nrTel, nrTel );
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are noul nrTel= "<<prim->nrTel;
  }		  
  while ( !stricmp ( p->nume, numePersoana ) && p ) {q=p;	p=p->adr;}
  if ( !p ) cout<<endl<<"Persoana cu numele "<<numePersoana<<" nu exista in lista!";
  else {
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are vechiul nrTel= "<<q->nrTel;	cout<<endl;
    strcpy ( p->nrTel, nrTel );
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are noul nrTel= "<<p->nrTel;
  }  
}
      
void schimbaadresa ( nod *& prim, char numePersoana[], char adresa[] ) {
  nod *p,*q;
  p=prim->adr;	q=prim;
  if ( !stricmp ( prim->nume, numePersoana ) ) {
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are vechea adresa= "<<prim->adresa;
    strcpy ( prim->adresa, adresa );
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are noua adresa= "<<prim->adresa;
  }  
  while ( !stricmp ( p->nume, numePersoana ) && p ) {q=p;	p=p->adr;}
  if ( !p ) cout<<endl<<"Persoana cu numele "<<numePersoana<<" nu exista in lista!";
  else {
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are vechea adresa= "<<p->adresa;
    strcpy ( p->adresa, adresa );
    cout<<endl<<"Persoana cu numele "<<numePersoana
			  <<" are noua adresa= "<<p->adresa;
  }  
} 

int main ( ) {
  nod *prim=NULL;
  char numePersoana[20],adresaPersoana[20],adresa[20],nrTel[10];
  unsigned i,n;
  cout<<"Cati abonati doriti sa introduceti: ";	cin>>n;
  for ( i=0; i<n; i++ ) adaugare ( prim );
  listare ( prim );
  cout<<"Cautare abonat"<<endl;
  cout<<"Numele persoanei pe care o cautati: ";	cin>>numePersoana;	cout<<endl;
  cout<<"Adresa persoanei pe care o cautati: ";	cin>>adresaPersoana;	cout<<endl;
  cautatelefon (  prim, adresaPersoana );	cout<<endl;
  cout<<"Schimba adresa "<<numePersoana<<endl;
  cout<<"Noua adresa: ";	cin>>adresa;	cout<<endl;
  schimbaadresa ( prim, numePersoana, adresa );	cout<<endl;
  cout<<"Schimba telefonul "<<numePersoana<<endl;
  cout<<"Noul telefon: ";	cin>>nrTel;	cout<<endl;
  schimbatelefon ( prim, numePersoana, nrTel );	cout<<endl;
  listare ( prim );
  getch ( );
  return 0;
}
   
   	
