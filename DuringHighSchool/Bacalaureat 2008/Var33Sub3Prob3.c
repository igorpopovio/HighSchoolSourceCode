#include <iostream>
#include <fstream>
using namespace std;

int max_cif ( int *x, int n ) {
  int max = 0;
  for ( int i = 0; i < n; i++ ) {
    if ( x[i] > max && ( x[i] < 1000 && x[i] > 99 ) ) max = x[i];
  }
  return max;
}

int main ( ) {
  int *x, n, max = 0;
  fstream fin ( "numere.txt", ios::in );
  fin >> n;
  x = new int [n];
  for ( int i = 0; i < n; i++ ) {
    for ( int j = 0; j < n; j++ ) fin >> x[j];
    max = max > max_cif ( x, n ) ? max : max_cif ( x, n );
  }
  fin.close ( );
  cout << "Valoarea maxima de trei cifre este: " << max;
  cin.get ( );
  return 0;
}
