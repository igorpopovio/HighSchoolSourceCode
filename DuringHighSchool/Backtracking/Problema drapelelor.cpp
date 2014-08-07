//Problema drapelelor
//------------------------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

int sol[4];
char * culori[6] = { "alb", "galben", "rosu", "verde", "albastru", "negru" };

void init ( int k ) {
  sol[k] = -1;
}

int succesor ( int k ) {
  if ( sol[k] < 5 ) {
    sol[k]++;
    return 1;
  } else return 0;
}

int solutie ( int k ) {
  return ( k == 4 && ( !strcmp ( culori[sol[2]], "galben" ) ||
                       !strcmp ( culori[sol[2]], "verde" ) ) );
}

int valid ( int k ) {
  for ( int i = 1; i < k; i++ )
    if ( sol[k] == sol[i] ) return 0;
  return 1;
}

void tipar ( ) {
  cout << "solutie:" << endl;
  for ( int i = 1; i <= 3; i++ )
    cout << culori[sol[i]] << "  ";
  cout << endl << endl;
}

void back ( int k ) {
  if ( solutie ( k ) ) tipar ( );
  else {
    init ( k );
    while ( succesor ( k ) )
      if ( valid ( k ) )
        back ( k + 1 );
  }
}

int main ( ) {
  back ( 1 );
  cin.get();
  return 0;
}
