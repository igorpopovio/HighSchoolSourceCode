#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <conio.h>

#include <iostream>
using namespace std;

const int DIM = 49;

struct Ball {
  int ballNumber;
  unsigned long occurrence;
};

unsigned long MyRandomNr ( void );
void sort ( Ball * pointer, int size );

int main ( ) {

  cout<<"\"Loto 6 din 49\"\n";
  cout<<"Program developed by Igor Popov\n";
  cout<<"Version 1.0.0.0\n";
  cout<<"--------------------------------\n\n";

  unsigned long n;
  cout<<"Please enter the number of simulations: ";
  cin>>n;
  const unsigned long SIMULATIONS = n;

  Ball aquarium[ DIM ];

  for ( int i = 0; i < DIM; i++ ) {
    aquarium[ i ].ballNumber = i + 1;
    aquarium[ i ].occurrence = 0;
  }

  //initializing the random numbers generator
  time_t t;
  srand ( ( unsigned ) time ( &t ) );

  cout<<"Beginning to simulate...\nPlease be patient, this can take a while\n";
  cout<<"depending on how much CPU you have\n\n";
  //cout<<"Progress... ";
  for ( unsigned long i = 0; i < 6 * SIMULATIONS; i++ ) {
    //gotoxy ( 12, 11 );
    //cout<<i / ( 6 * SIMULATIONS ) * 100<<" %";
    aquarium[ MyRandomNr ( ) - 1 ].occurrence++;
  }
  sort ( aquarium, DIM );
  cout<<endl<<endl;
  cout<<"Simulating complete...\nHere are the results:\n";
  cout<<"The six numbers which occur almost every time are: ";
  for ( int i = 0; i < 6; i++ ) {
    cout<<aquarium[ i ].ballNumber<<" ";
  }

  cout<<"\nPress enter to exit the program...";
  cin.get ( );
  cin.get ( );
  return 0;
}

//we need a number between 1 and 49
unsigned long MyRandomNr ( void ) {
  return ( 1 + rand ( ) % 48 );
}

//bubble sort
//we need to sort descending
void sort ( Ball * pointer, int size ) {
  bool sorted = false;
  Ball aux;

  while ( !sorted ) {
    sorted = true;
    for ( int i = 0; i < ( size - 1 ); i++ )
      if ( pointer[ i ].occurrence < pointer[ i + 1 ].occurrence ) {
        aux = pointer[ i ];
        pointer[ i ] = pointer[ i + 1 ];
        pointer[ i + 1 ] = aux;
        sorted = false;
      }
  }
}
