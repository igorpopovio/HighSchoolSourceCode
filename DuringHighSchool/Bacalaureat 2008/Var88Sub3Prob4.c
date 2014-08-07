#include <iostream>
#include <fstream>

using namespace std;

int prim ( unsigned n ) {
  for ( unsigned i = 2; i < n / 2; i++ )
    if ( n % i == 0 ) return 0;
  return 1;
}

int main ( ) {
  unsigned x, vf[100], i, gasit;
  fstream fin ( "bac.txt", ios::in );
  for ( i = 0; i < 100; i++ ) vf[i] = 0;
  while ( !fin.eof ( ) ) {
    fin >> x;
    vf[x]++;
  }
  fin.close ( );
  gasit = 0;
  for ( i = 99; i >= 0 && !gasit; i-- ) {
    if ( vf[i] != 0 && prim ( i ) ) gasit = 1;
  }
  cout << i + 1 << "  " << vf[i+1];
  cin.get ( );
  cin.get ( );
  return 0;
}
