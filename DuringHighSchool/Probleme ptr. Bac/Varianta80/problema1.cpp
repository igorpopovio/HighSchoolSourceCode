//Problema1
//------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>

using namespace std;

int main ( ) {
	int a[50][50],i,j,n,k;
	cout<<"n= ";	cin>>n;
	k=1;
	for ( j=0; j<n; j++ ) 
  for ( i=0; i<n; i++ )
  	a[i][j]=k++;
 	for ( i=0; i<n; i++ )
 	for ( j=0; j<n; j++ ) {
 	  cout<<a[i][j]<<"  ";
 	  if ( j==( n-1 ) ) cout<<'\n';
  }
  getch ( );
  return 0;
}  
