#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

unsigned long st[256], n, k, a = 0, s, i;
fstream fout ( "text.out", ios::out );

void init() {
  st[k] = 0;
}

int am_succesor() {
  if ( st[k] < n ) {
    st[k]++;
    return 1;
  } else return 0;
}

int e_valid() {
  s = 0;
  for ( i = 1;i <= k;i++ ) s += st[i];
  if ( s <= n ) return 1;
  else return 0;
}

int solutie() {
  return ( s == n );
}

void tipar() {
  for ( i = 1; i <= k; i++ ) fout << st[i] << " ";
  fout << endl;
}

void back() {
  int AS;
  k = 1;
  init();
  while ( k > 0 ) {
    do {} while ( ( AS = am_succesor() ) && !e_valid() );
    if ( AS ) {
      if ( solutie() ) tipar();
      else {
        k++;
        init();
      }
    } else k--;
  }
}

int main( int argc, char **argv ) {
  cout<<"n = ";  cin>>n;
  //n = atoi ( argv[1] );
  a = 0;
  back();
  fout.close ( );
  return 0;
}


