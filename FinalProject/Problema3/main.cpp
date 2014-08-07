#include "ListaCDI.h"
#include <iostream>

using namespace std;

int main ( ) {
  ListaCDI lista ( 20 );
  int n, i, x;
  unsigned long numar;
  cout<<"Cate elemente introduceti in lista?"<<endl;
  cout<<"n= ";  cin>>n;
  cout<<"Introduceti elementele in lista"<<endl;
  for ( i=0; i<n; i++ ) {
    cout<<( i+1 )<<": ";  cin>>x;
    lista.adaugaSfarsit ( x );
  }
  numar = lista.numar ( );
  cout<<"Numarul obtinut prin lipirea cifrelor din lista este: "<<numar;
  cin.get ( );
  cin.get ( );
  return 0;
}
