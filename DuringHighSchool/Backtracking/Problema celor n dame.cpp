//Problema celor n dame
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>
#include <math.h>

int n, i, sol[50];

int valid ( int k ) {
  for ( i=1; i<k; i++ )
  if ( sol[k]==sol[i] || abs ( sol[k]-sol[i] ) == abs ( k-i ) ) return 0;
  return 1;
}

void back ( int k ) {
  if ( k==n+1 ) {
    for ( i=1; i<=n; i++ ) cout<<sol[i];
    cout<<endl;
  }
  else {
    sol[k]=0;
    while ( sol[k]<n ) {
      sol[k]++;
      if ( valid ( k ) ) back ( k+1 );
    }    
  }
}

int main ( ) {
  cout<<"n= ";	cin>>n;
  back ( 1 );
  getch ( );
  return 1;
}                   
