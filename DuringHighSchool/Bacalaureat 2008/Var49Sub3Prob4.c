#include <iostream>
#include <fstream>
using namespace std;

void cmax ( unsigned a, unsigned &b ) {
  while ( a ) {
    if ( a % 10 > b ) b = a % 10;
    a = a / 10;
  }
}

int main ( ) {
  fstream fin ( "bac.txt", ios::in );
  unsigned a, b = 0;
  while ( !fin.eof() ) {
    fin >> a;
    cmax ( a, b );
  }
  fin.close();
  cout << "Cifra maxima este: " << b;
  cin.get();
  return 0;
}
