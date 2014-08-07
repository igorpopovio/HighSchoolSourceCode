#include <iostream>
using namespace std;

unsigned long fibonacci ( unsigned n ) {
  if ( n == 0 ) return 0;
  else if ( n == 1 ) return 1;
  else return ( fibonacci ( n - 1 ) + fibonacci ( n - 2 ) );
}

void matrice ( unsigned long v[][16], unsigned n ) {
  unsigned i, j, k = 0;
  for ( i = 0; i < n; i++ ) {
    if ( i % 2 == 0 ) {
      for ( j = 0; j < n; j++ ) {
        v[i][j] = fibonacci ( k );
        k++;
      }
    }
    else  {
      for ( j = n - 1; j >= 0; j-- ) {
        v[i][j] = fibonacci ( k );
        k++;
      }
    }
  }
}

int main ( ) {
  unsigned long v[16][16];
  unsigned n;
  do {
    cout << "1 <= n <= 16" << endl;
    cout << "n = ";
    cin >> n;
  } while ( n < 1 || n > 16 );
  matrice ( v, n );
  for ( unsigned i = 0; i < n; i++ ) {
    for ( unsigned j = 0; j < n; j++ ) cout << v[i][j] << " ";
    cout << endl;
  }
  cin.get ( );
  cin.get ( );
  return 0;
}


