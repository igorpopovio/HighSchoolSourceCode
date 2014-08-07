#include <iostream>
using namespace std;
#include <conio.h>

struct nod {
  int info;
  nod * st, *dr;
};
int st[50],dr[50],n;

void citire ( ) {
  cout<<"Introduceti numarul de noduri: "<<endl;
  cin>>n;
  cout<<"Introduceti vectorii st si dr: "<<endl;
  for ( int i=0; i<n; i++ ) {
    cout<<"st["<<(i+1)<<"]= ";	cin>>st[i]; 
    cout<<"dr["<<(i+1)<<"]= ";	cin>>dr[i];
  }
  cout<<endl; 
}

nod * creare ( int varf ) {
  if ( varf ) {
    nod * c;
    c = new nod;
    c->info=varf;
    c->st=creare ( st[varf] );
    c->dr=creare ( dr[varf] );
  }
  else return NULL;
}

void SVD ( nod * c ) {
  if ( c ) {
    SVD ( c->st );
    cout<<c->info;
    SVD ( c->dr );
  }
}

void VSD ( nod * c ) {
  if ( c ) {
    cout<<c->info;
    VSD ( c->st );
    VSD ( c->dr );
  }
}

void SDV ( nod * c ) {
  if ( c ) {
    SDV ( c->st );
    SDV ( c->dr );
    cout<<c->info;
  }
}

int maxim=0, k=0;

void inaltime ( nod *& c ) {
  if ( c ) { 
  	maxim=k++;	
    inaltime ( c->st );
    inaltime ( c->dr );
  }
  else k=0;
}

int main ( ) {
  nod * c = NULL;
  maxim=k=0;
  citire ( );
  c = creare ( 1 );
  cout<<"parcurgerea in inordine ( SVD ):   ";	SVD ( c );	cout<<endl; 
  cout<<"parcurgerea in preordine ( VSD ):  ";	VSD ( c );	cout<<endl;
  cout<<"parcurgerea in postordine ( SDV ): ";	SDV ( c );	cout<<endl; 
  cout<<"inaltimea arborelui binar este: "<<maxim;
  getch ( );
  return 0;
}                   
