#include <iostream>
using namespace std;

int tablou ( int i, int v [] ) {
  int n;
  if ( i < 0 ) {
    cout << "return 0" << endl;
    return 0;
  } else {
    cout << "n = " << v[i] << endl;
    n = v[i];
    while ( n ) {
      if ( n % 2 ) {
        cout << "sunt in tablou ( " << i << ", v );" << endl;
        cout << n << " % 2 = " << n % 2 << endl;
        cout << "return 1 + tablou ( " << i - 1 << ", v );" << endl;
        return 1 + tablou ( i - 1, v );
      }
      n = n / 10;
    }
    cout << "return tablou ( " << i - 1 << ", v );" << endl;
    return tablou ( i - 1, v );
  }
}

int main ( ) {
  int v[6] = { 420, 48, 635, 628, 837, 93 };
  //cout << "a = " << tablou ( 3, v ) << endl;
  //cout << "b = " << tablou ( 4, v ) << endl;
  cout << "c = " << tablou ( 5, v ) << endl;
  //cout << "d = " << tablou ( 0, v ) << endl;
  cin.get ( );
  return 0;
}
