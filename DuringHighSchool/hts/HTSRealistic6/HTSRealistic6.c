#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void readFile ( char * name, int v[], int & n ) {
  fstream file ( name, ios::in );
  char c;
  int x1, x2, x3;
  n = 0;
  while ( !file.eof ( ) ) {
    file >> c >> x1 >> c >> x2 >> c >> x3;
    v[n] = x1 + x2 + x3;
    n++;
  }
  file.close ( );
}

int getMax ( int v[], int n ) {
  int max = v[0];
  for ( int i = 1; i < n; i++ )
    if ( max < v[i] ) max = v[i];
  return max;
}

int getMin ( int v[], int n ) {
  int min = v[0];
  for ( int i = 1; i < n; i++ )
    if ( min > v[i] ) min = v[i];
  return min;
}

int * freqVec ( int * v, int n ) {
  int * a = new int[n];
  for ( int i = 0; i < n; i++ ) a[i] = 0;
  for ( int i = 0; i < n; i++ ) a[v[i]]++;
  return a;
}

int main ( ) {
  char * name = "input.txt", c;
  int v[500], n, max;
  int * a;
  readFile ( name, v, n );

  //deocamdata nu se executa
#if 0
  for ( int i = 0; i < n; i++ ) cout << v[i] << " ";
  cout << endl << "Maximul este: " << getMax ( v, n ) << endl;
  cout << "Minimul este: " << getMin ( v, n ) << endl;
#endif
  for ( int i = 0; i < n; i++ ) v[i] -=762;
  //a = freqVec ( v, n );
  //max = getMax ( a, n );
  fstream fout ( "output.txt", ios::out );
  for ( int i = 0; i < n; i++ ) {
    fout << ( char ) v[i];
  }
  fout.close ( );
  //cout << "etaoi" << ( int ) ' '<< ( int ) 'e'<< " " << ( int ) 't' << " "<< ( int ) 'a' << " "<< ( int ) 'o' << " "<< ( int ) 'i';
    /*for ( int i = 0; i < n; i++ ) {
    v[i] = v[i] - max + ' ';
    cout << ( char ) v[i];

  }
*/
  //cout << ( int ) 'A' << " " << ( int ) 'z';
  cin.get ( );
  cin.get ( );
  return 0;
}

