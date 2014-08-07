//Stiva - implementare cu clase
//------------------------------------------------------------------------------

#include <iostream.h>
#include <conio.h>

typedef unsigned long Element;
void aduna5 ( Element & c );
void aduna1 ( Element & c );

class Stiva {

  private:
    enum {Max = 10};
    Element elemente[Max];
    int varf;
    int k;

  public:
    Stiva ( );
    bool evida ( ) const;
    bool eplina ( ) const;
    bool push ( const Element & elem );
    void vizita ( void ( * p ) ( Element & c ) );
    void set_varf ( ) {
      varf = 0;
    }

    void ( * p ) ( Element & c );
};

Stiva::Stiva ( ) {
  varf = 0;
}

bool Stiva::evida ( ) const {
  return varf == 0;
}

bool Stiva::eplina ( ) const {
  return varf == Max;
}

bool Stiva::push ( const Element & elem ) {
  k = 0;

  if ( varf < Max ) {
    elemente[varf++] = elem;
    k++;
    return true;
  } else
    return false;
}

void Stiva::vizita ( void ( * p ) ( Element & c ) ) {
  set_varf ( );

  for ( ; varf < k; varf++ ) {
    ( * p ) ( elemente[varf] );
    cout << elemente[varf] << "\n";
  }
}

int main ( ) {
  Stiva A;
  unsigned long a;
  cout << "Introduceti un element"
  << " in stiva (numar natural)\nsau \'p\' pentru procesare:\n";

  while ( cin >> a ) {
    if ( A.eplina ( ) ) {
      cout << "stiva este deja plina!\n";
      break;
    } else {
      A.push ( a );
      cout << "Introduceti un element"
      << " in stiva (numar natural)"
      << "\nsau \'p\' pentru procesare:\n";
    }
  }

  cin.clear ( );

  cout << "Acum voi aduna 5 fiecarui element din stiva!\n";
  A.vizita ( aduna5 );
  cout << "Acum voi aduna 1 fiecarui element din stiva!\n";
  A.vizita ( aduna1 );
  getch ( );
  return 0;
}

//------------------------------------------------------------------------------
void aduna5 ( Element & c ) {
  c += 5;
}

void aduna1 ( Element & c ) {
  c += 1;
}
