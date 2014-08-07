#include <iostream>
#include <cstdio>

using namespace std;

int main ( ) {
  unsigned a[20][20], n, i, j;
  cout << "n = ";

  do cin >> n;
  while ( n <= 2 || n >= 16 );

  for ( i = 0; i < n; i++ )
    for ( j = 0; j < n; j++ )
      if ( i == j || i + j == n - 1 ) a[i][j] = 0;
      else if ( i < j && i + j < n - 1 ) a[i][j] = 1;
      else if ( i > j && i + j > n - 1 ) a[i][j] = 2;
      else a[i][j] = 3;

  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < n; j++ ) cout << a[i][j] << " ";

    cout << endl;
  }

  cin.get ( );

  return 0;
}
