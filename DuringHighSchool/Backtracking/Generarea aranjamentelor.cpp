//Programul de generare a aranjamentelor
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

int n, p, sol[50];

int valid ( int k ) {
  int i;
  for ( i=1; i<k; i++ )
  if ( sol[k]==sol[i] ) return 0;
  return 1;
}

void back ( int k ) {
  int i,j;
  if ( k==p+1 ) {
    for ( j=1; j<=p; j++ ) cout<<sol[j];
    cout<<endl;
  }
  else 
  for ( i=1; i<=n; i++ ) {
    sol[k]=i;
    if ( valid ( k ) ) back ( k+1 );
  }    
}

int main ( ) {
  cout<<"n= ";	cin>>n;
  cout<<"p= ";	cin>>p;
  back ( 1 );
  getch ( );
  return 1;
}                   
