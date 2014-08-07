//Problema2
//------------------------------------------------------------------------------

#include <iostream>
#include <conio.h>

using namespace std;

int distinct ( unsigned n ) {
  unsigned cifre[10],i;
  for ( i=0; i<10; i++ ) cifre[i]=0;
  while ( n ) {
    cifre[n%10]++; n/=10;
  }
  for ( i=0; i<10; i++ )  //i reprezinta cifra din numar
    if ( cifre[i]>=2 ) return 0;
  return 1;
}

int main ( ) {
  int n,i,j,a,b,numere[50];
  cout<<"a= ";	cin>>a;
  cout<<"b= ";	cin>>b;
  i=0;
  n=0;
  for ( j=a; j<=b; j++ ) 
 	if ( distinct ( j ) ) {
  	numere[i++]=j;	n++;
 	}
  if ( !n ) cout<<"NU EXISTA"<<endl;
  else 
  	for ( i=0; i<n; i++ ) {
     	if ( i%10==0 ) cout<<endl;	
      cout<<numere[i]<<"  ";
    }
  getch ( );
  return 0;
}           
