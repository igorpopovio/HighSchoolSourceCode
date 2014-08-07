#include <iostream>
#include <fstream>
using namespace std;

void cifra ( unsigned long n, unsigned & x ) {
  x = n % 10;
  n /= 10;
  while ( n ) {
    if ( n % 10 > x ) x = n % 10;
    n /= 10;
  }
}

void sort ( unsigned long a[], int n ) {
  int i, j;
  unsigned long aux;
  for ( i = 0; i < n - 1; i++ )
    for ( j = i + 1; j < n; j++ )
      if ( a[i] > a[j] ) {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
      }
  if ( a[0] == 0 ) {
    i = 1;
    while ( !a[i] ) i++;
    a[0] = a[i];
    a[i] = 0;
  }
}

int main ( ) {
  unsigned long x, *nrMare;
  unsigned c;
  int n;
  fstream fin ( "numere.in", ios::in );
  fin >> n;
  nrMare = new unsigned long [n];
  for ( int i = 0; i < n; i++ ) {
    fin >> x;
    cifra ( x, c );
    nrMare[i] = c;
  }
  fin.close();
  sort ( nrMare, n );
  fstream fout ( "numere.out", ios::out );
  for ( int i = 0; i < n; i++ ) fout << nrMare[i];
  fout.close();
  cout << "Rezultatul este in fisierul \"numere.out\"!" << endl;
  cin.get ( );
  return 0;
}
