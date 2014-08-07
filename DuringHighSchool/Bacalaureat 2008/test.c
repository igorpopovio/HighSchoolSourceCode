#include <iostream>
using namespace std;

unsigned long fibonacci ( unsigned n ) {
  if ( n == 0 ) return 0;
  else if ( n == 1 ) return 1;
  else return ( fibonacci ( n - 1 ) + fibonacci ( n - 2 ) );
}
int main ( ) {
  for ( int i = 0; i < 20; i++ ) cout << fibonacci ( i ) << " ";
  cin.get ( );
  return 0;
}
