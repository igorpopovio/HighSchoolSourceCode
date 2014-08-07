#include <iostream>
using namespace std;

int main ( ) {
  int z, i, j, t[8][8], k = 1;;
  for ( i = 0; i < 8; i++ )
    for ( j = 0; j < 8; j++ ) t[i][j] = k++;
  z = 0;
  for ( i = 0; i < 8; i++ ) {
    for ( j = 0; j < 8 - i; j++ ) {
      z = z + t[i][j];
      cout << t[i][j] << " ";
    }
    cout << endl;
  }
  cin.get ( );
  return 0;
}
