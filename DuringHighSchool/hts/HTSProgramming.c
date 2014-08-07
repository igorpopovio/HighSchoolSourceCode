#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct cuvant {
  char cuv1[30];
  char cuv2[30];
};

char * sort ( char * sir ) {
  int n = strlen ( sir ), i, j;
  char aux;
  char * s = new char[n + 1];
  for ( i = 0; i < n; i++ ) s[i] = sir[i];
  s[n] = '\0';
  for ( i = 0; i < n - 1; i++ )
    for ( j = i + 1; j < n; j++ )
      if ( s[i] > s[j] ) {
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
      }
  return s;
}

int main ( ) {
  char sir1[30], sir2[30], sir3[30];
  typedef char * sir;
  sir list[11];
  cuvant words[1276];
  int i = 0, j = 0, n, m;
  fstream f ( "lista.txt", ios::in );
  fstream g ( "example.txt", ios::in );
  while ( !g.eof ( ) ) {
    list[i] = new char[30];
    g >> list[i];
    list[i] = sort ( list[i] );
    i++;
  }

  n = i + 1;
  while ( !f.eof ( ) ) {
    f >> words[j].cuv1 >> words[j].cuv2;
    j++;
  }
  m = j + 1;
  fstream fis ( "required.txt", ios::out );
  for ( i = 0; i < n; i++ ) {
    for ( j = 0; j < m; j++ )
      if ( !strcmp ( words[j].cuv1, list[i] ) ) fis << words[j].cuv2 << ",";
  }
  f.close ( );
  g.close ( );
  fis.close ( );
  system ( "cd D:\\My Documents\\Programe C++\\HTS\\" );
  system ( "required.txt" );

  return 0;
}
