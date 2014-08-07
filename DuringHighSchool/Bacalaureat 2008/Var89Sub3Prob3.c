#include <iostream>

using namespace std;

unsigned long numar ( unsigned long n, unsigned c1, unsigned c2 ) {
  unsigned long x = 0;
  while ( n ) {
    x = x * 10 + n % 10;
    n /= 10;
  }
  while ( x ) {
    if ( x % 10 == c1 ) {
      n = n * 10 + c2;
      c2 = 0;
    }
    else n = n * 10 + x % 10;
    x /= 10;
  }
  return n;
}

int main ( ) {
  unsigned long n;
  unsigned c1, c2;
  cout << "n = ";
  cin >> n;
  cout << "c1 = ";
  cin >> c1;
  cout << "c2 = ";
  cin >> c2;

  cout << numar ( n, c1, c2 );
  cin.get ( );
  cin.get ( );
  return 0;
}
