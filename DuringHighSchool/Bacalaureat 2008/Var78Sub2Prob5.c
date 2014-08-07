#include <iostream>
#include <cstring>

using namespace std;
int main ( ) {
  char s[100], cuv[15], *p, sep[] = " ";
  cout << "Introduceti sirul: ";
  cin.get ( s, 100 );
  cin.get();
  cout << "Introduceti cuvantul: ";
  cin.get ( cuv, 15 );
  p = strtok ( s, sep );

  while ( p ) {
    if ( strstr ( p, cuv ) ) cout << p << "? ";
    else cout << p << " ";

    p = strtok ( NULL, sep );
  }

  cin.get ( );

  return 0;
}
