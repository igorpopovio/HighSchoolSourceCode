#include <iostream>
#include <fstream>
using namespace std;

unsigned long st[256], n, k, a = 0, s, i;

fstream fin ( "c:\\trepte_in.txt", ios::in );
fstream fout ( "c:\\trepte_out.txt", ios::out );

void init() {
  st[k] = 0;
}

int am_succesor() {
  if ( st[k] < 2 ) {
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
  a++;
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
  fout << a << endl;
}

int main() {
  while ( fin >> n ) {
    a = 0;
    back();
  }
  return 0;
}


