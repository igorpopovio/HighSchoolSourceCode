//Problema3
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

struct sir {
  char cuvant[50];
  unsigned lungime;
};

unsigned citire ( sir *& vectorCuvinte ) {
  fstream fin ( "cuvinte.in", ios::in );
  unsigned i,n;
  fin>>n;
  vectorCuvinte=new sir [n];
  for ( i=0; i<n; i++ ) {
    fin>>vectorCuvinte[i].cuvant;
    vectorCuvinte[i]->lungime=strlen ( vectorCuvinte[i]->cuvant );
  }
  fin.close ( );
  return n;
}

void sortare ( sir *& vectorCuvinte, unsigned & n ) {
  unsigned g=1;
  sir aux;
  while ( g ) {
    g=0;
    for ( int i=0; i<( n-1 ); i++ )
    for ( int j=0; j<n; j++ ) 
    if ( vectorCuvinte[i]->lungime > vectorCuvinte[j]->lungime ) {
      aux=vectorCuvinte[i];
      vectorCuvinte[i]=vectorCuvinte[j];
      vectorCuvinte[j]=aux;
      g=1;
    }
  }
}

void scriere ( sir *& vectorCuvinte, unsigned & n ) {
	fstream fout ( "cuvinte.out", ios::out );
	for ( int i=0; i<n; i++ )
 	fout<<vectorCuvinte[i]->cuvant<<endl;
  fout.close ( );
}

int main ( ) {
  sir * vectorCuvinte;
  unsigned n;
  n=citire ( vectorCuvinte );
  sortare ( vectorCuvinte, n );
  scriere ( vectorCuvinte, n );
  for ( int i=0; i<n; i++ ) cout<<vectorCuvinte->cuvant<<endl;
  cout<<"cuvintele sunt ordonate in fisierul \"cuvinte.out\""<<endl;
  getch ( );
  return 0;
}
           
