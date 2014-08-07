#include <iostream>
#include <fstream>
using namespace std;

void cifra ( float &x, unsigned &y ) {
  y = ( unsigned ) x;
  y = y % 10;
}

int main ( ) {
  fstream fin ( "medii.txt", ios::in );
  float x, y;
  unsigned a, b, k = 0;
  while ( !fin.eof ( ) ) {
    fin >> x >> y;
    cifra ( x, a );
    cifra ( y, b );
    if ( b == a + 1 ) k++;
  }
  fin.close ( );
  cout << "Numarul de inregistrari ce satisfac cerinta este: " << k;
  cin.get ( );
  return 0;
}
