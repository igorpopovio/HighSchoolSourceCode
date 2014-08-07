#include <iostream>
#include <math.h>
using namespace std;

struct polynomial {
  double * coef;
  unsigned gr;
};
void NSolve ( polynomial & rpol, double a, double b, 
              double sol[], int & k );
double Eval ( polynomial & rpol, double x );
void ReadPol ( polynomial & rpol );
void WriteSol ( double sol[], int k );
void Solve ( polynomial & rpol );

void ReadPol ( polynomial & rpol ) {
  cout<<"Introduceti gradul polinomului: ";
  cin>>rpol.gr;
  cout<<"Introduceti coeficientii polinomului in ordine"<<endl;
  cout<<"f ( x ) = a0 + a1 * x^1 + a2 * x^2 + ... + an * x^n"<<endl;
  rpol.coef=new double [rpol.gr+1];
  for ( int i=0; i<=rpol.gr; i++ ) {
    cout<<"monomul de grad "<<i<<" = ";	cin>>rpol.coef[i];
  }
}

double Eval ( polynomial & rpol, double x ) {
  double y=0;
  for ( int i=0; i<=rpol.gr; i++ )
    y+=rpol.coef[i]*pow ( x, i );
  return y;
}

void NSolve ( polynomial & rpol, double a, double b, 
              double sol[], int  & k ) {
  if ( abs ( a-b )/2  > pow ( 10., -15 ) ) {
    if ( Eval ( rpol, a ) * Eval ( rpol, ( a+b )/2 ) < 0 ) 
      NSolve ( rpol, a, ( a+b )/2, sol[], k );
    if ( Eval ( rpol, ( a+b )/2 ) * Eval ( rpol, b ) )
      NSolve ( rpol, ( a+b )/2, b, sol[], k );
  }
  else sol[k++] = ( a+b )/2;
}

void WriteSol ( double sol[], int  k ) {
  if ( k==-1 ) cout<<"Nu are solutii reale";
  else {
    for ( int i=0; i<k; i++ )
      cout<<"X"<<( i+1 )<<"= "<<sol[i]<<endl;
  }  
}

void Solve ( polynomial & rpol ) {
  double sol[50];
  int k=-1;
  NSolve ( rpol, -100000000, 100000000, sol, k );
  WriteSol ( sol, k );
}  

int main ( ) {
  polynomial pol;
  ReadPol ( pol );
  cout<<"Solutia ecuatiei f ( X ) = 0 este:"<<endl;
  Solve ( pol );
  cout<<endl;
  system ( "PAUSE" );
  return 0;
}
               
