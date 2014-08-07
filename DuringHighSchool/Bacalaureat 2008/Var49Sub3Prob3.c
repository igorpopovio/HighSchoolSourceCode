#include <iostream>
using namespace std;

int main ( ) {
  int a, b, n, i, aux, v[50];
  cout << "a = ";
  cin >> a;
  cout << "b = ";
  cin >> b;
  cout << "n = ";
  cin >> n;
  if ( b < a ) {
    aux = a;
    a = b;
    b = aux;
  }
  if ( ( a / n ) * n == a ) i = a;
  else i = ( a / n + 1 ) * n;
  while ( i <= b ) {
    cout << i << " ";
    i = i + n;
  }
  cin.get ( );
  return 0;
}
