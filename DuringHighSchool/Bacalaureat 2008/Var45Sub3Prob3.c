#include <iostream>
using namespace std;

int test ( float *a, int n, float x ) {
  for ( int i = 0; i < n; i++ ) {
    if ( a[i] == x ) return 0;
  }
  return 1;
}

int main ( ) {
  float a[100];
  int i, n;
  cout << "n = ";
  cin >> n;
  for ( i = 0; i < n; i++ ) {
    cout << "a[" << i << "] = ";
    cin >> a[i];
  }
  cout << endl;
  for ( i = 0; i < n; i++ ) {
    if ( test ( a, n, a[i] ) == 1 ) cout << a[i] << " ";
  }
  cin.get ( );
  cin.get ( );
  return 0;
}
