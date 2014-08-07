//Se cer toate solutiile de asezare in linie a m caini si n pisici asfel incat
//sa nu existe o pisica asezata intre doi caini.
//Observatie: am facut codificarea astfel:
  //sol[k]=0, pentru caine
  //sol[k]=1, pentru pisica    
//------------------------------------------------------------------------------
                  
#include <iostream.h>
#include <conio.h>

int n, m, sol[50];

void init ( int k ) {
  sol[k]=-1;
}

int succesor ( int k ) {
  if ( sol[k]<1 ) {
    sol[k]++;
    return 1;
  }
  else return 0;
}

int valid ( int k ) { 
  if ( k>=3 && sol[k-2]==0 && sol[k-1]==1 && sol[k]==0 ) return 0;
  return 1;
}

int solutie ( int k ) {
  int sm=0, sn=0;
  for ( int i=1; i<=k; i++ )
    if ( sol[i]==0 ) sm++;
   	else sn++;
  return ( sm==m && sn==n );
}

void tipar ( ) {
  for ( int i=1; i<=m+n; i++ ) cout<<sol[i];
  cout<<endl;
}

void back ( int k ) {
  if ( solutie ( k ) ) tipar ( );
  else {
    init ( k );
    while ( succesor ( k ) ) 
    if ( valid ( k ) ) back ( k+1 );
  }
}

int main ( ) {
  cout<<"n= ";	cin>>n;
  cout<<"m= ";  cin>>m;
  back ( 1 );
  getch ( );
  return 1;
}                   
