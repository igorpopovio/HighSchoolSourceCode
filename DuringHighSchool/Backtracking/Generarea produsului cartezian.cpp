//Programul de generare a produsului cartezian
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

int n, a[50], i, sol[50];

void back ( int k ) {
  if ( k==n+1 ) {
    for ( i=1; i<=n; i++ ) cout<<sol[i];
    cout<<endl;
  }
  else {
    sol[k]=0;
    while ( sol[k]<a[k] ) {
      sol[k]++; back ( k+1 );
    }
  }        
}

int main ( ) {
  cout<<"Nr de multimi= ";	cin>>n;
  for ( int i=1; i<=n; i++ ) {
    cout<<"a["<<i<<"]= ";	cin>>a[i];
  }  
  back ( 1 );
  getch ( );
  return 1;
}                   
