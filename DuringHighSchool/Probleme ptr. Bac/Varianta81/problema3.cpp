//Problema3
//------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>

using namespace std;

void impar ( unsigned n ) {
  if ( n/10!=0 ) impar ( n/10 );
  if ( n%2 ) cout<<n%10;
}

int main ( ) {
  unsigned n;
  cout<<"n= ";	cin>>n;
  impar ( n );
  getch ( );
  return 0;
}
