//Programul de generare a combinarilor
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

int n, p, sol[50];

void back ( int k ) {
  int i;
  if ( k==p+1 ) {
    for ( i=1; i<=p; i++ ) cout<<sol[i];
    cout<<endl;
  }
  else {
    if ( k>1 ) sol[k]=sol[k-1];
    else  sol[k]=0;
    while ( sol[k]<n-p+k ) {
      sol[k]++;
      back ( k+1 );
    }    
  }
}

int main ( ) {
  cout<<"n= ";	cin>>n;
  cout<<"p= ";	cin>>p;
  back ( 1 );
  getch ( );
  return 1;
}                   
