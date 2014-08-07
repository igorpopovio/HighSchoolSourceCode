//Programul de generare a permutarilor
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

int n, sol[50];

void init ( int k ) {
  sol[k] = 0;
}

int succesor ( int k ) {
  if ( sol[k] < n ) {
    sol[k]++;
    return 1;
  }
  else return 0;
}

int valid ( int k ) {
  int i, ev = 1;
  for ( i = 1; i <= ( k - 1 ); i++ )
    if ( sol[k] == sol[i] ) ev = 0;
  return ev;
}

int solutie ( int k ) {
  return ( k == n + 1 );
}

void tipar ( ) {
  for ( int i = 1; i <= n; i++ ) cout << sol[i];
  cout << endl;
}

void back ( int k ) {
  if ( solutie ( k ) ) tipar ( );
  else {
    init ( k );
    while ( succesor ( k ) )
      if ( valid ( k ) ) back ( k + 1 );
  }
}

int main ( ) {
  cout << "n= ";
  cin >> n;
  back ( 1 );
  getch ( );
  return 1;
}
