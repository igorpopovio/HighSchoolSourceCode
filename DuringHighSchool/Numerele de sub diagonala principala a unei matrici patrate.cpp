#include <iostream.h>
#include <conio.h>
void main() {
  int a[50][50], i, n, j;
  cout << "n=";
  cin >> n;
  for ( i = 0;i < n;i++ )
    for ( j = 0;j < n;j++ ) {
      cout << "a[" << ( i + 1 ) << "][" << ( j + 1 ) << "]=";
      cin >> a[i][j];
    }
  for ( i = 0;i < ( n - 1 );i++ )
    for ( j = i + 1;j < n;j++ )
      cout << "linia " << ( j + 1 ) << ", coloana " << ( i + 1 ) << ";" << endl;
  getch();
}
