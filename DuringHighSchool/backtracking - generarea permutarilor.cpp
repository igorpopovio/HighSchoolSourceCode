#include <iostream>

using namespace std;
int st[10], n, k, a = 0;

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
  for ( int i = 1;i < k;i++ )
    if ( st[i] == st[k] ) return 0;

  return 1;
}

int solutie() {
  return ( k == n );
}

void tipar() {
  for ( int i = 1;i <= n;i++ ) cout << st[i] << "  ";

  cout << endl;
}

void back() {
  int AS;
  k = 1;
  init();

  while ( k > 0 ) {
    do {} while ( ( AS = am_succesor() ) && !e_valid() );

    if ( AS ) {
      if ( solutie() ) {
        tipar();
        a++;
      } else {
        k++;
        init();
      }
    } else k--;
  }
}

int main() {
  cout << "n=  ";
  cin >> n;
  cout << endl;
  back();
  cout << "Numarul permutarilor este " << a;
  cin.get ( );
  cin.get ( );
  return 0;
}
