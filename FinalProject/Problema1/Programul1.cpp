/*
  Nume: Programul1.cpp
  Autor: Popov Igor
  Descriere: Testeaza metodele clasei ListaCDI
*/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "ListaCDI.h"

//prototipuri de functii
void meniu ( );

int main ( ) {
  char c;
  ListaCDI lista ( 20 );
  int inf, p;

  do {
    system ( "CLS" );
    meniu ( );
    cout<<"Optiunea Dumneavoastra: ";  cin>>c;
    switch ( c ) {
      case '1':
        cout<<"informatia: ";  cin>>inf;
        lista.adaugaInceput ( inf );
        break;
      case '2':
        cout<<"informatia: ";  cin>>inf;
        lista.adaugaSfarsit ( inf );
        break;
      case '3':
        cout<<"informatia: ";  cin>>inf;
        cout<<"pozitia: ";  cin>>p;
        lista.adaugaInterior ( inf, p );
        break;
      case '4':
        lista.stergeInceput ( );
        break;
      case '5':
        lista.stergeSfarsit ( );
        break;
      case '6':
        cout<<"pozitia: ";  cin>>p;
        lista.stergeInterior ( p );
        break;
      case '7':
        lista.listareStDr ( );
        system ( "PAUSE" );
        break;
      case '8':
        lista.listareDrSt ( );
        system ( "PAUSE" );
        break;
      case '9':
        lista.distruge ( );
        break;
      default:
        c='t';
        break;
    }
  } while ( c!='t' );
  cout<<"La revedere!";
  cin.get ( );
  cin.get ( );
  return 0;
}

void meniu ( ) {
  cout<<"1. Adaugati un element la inceputul listei;"<<endl;
  cout<<"2. Adaugati un element la sfarsitul listei;"<<endl;
  cout<<"3. Adaugati un element pe o pozitie p in interiorul listei;"<<endl;
  cout<<"4. Stergeti un element de la inceputul listei;"<<endl;
  cout<<"5. Stergeti un element de la sfarsitul listei;"<<endl;
  cout<<"6. Stergeti un element de pe o pozitie p in interiorul listei;"<<endl;
  cout<<"7. Afisati lista de la stanga la dreapta;"<<endl;
  cout<<"8. Afisati lista de la dreapta la stanga;"<<endl;
  cout<<"9. Distrugeti lista;"<<endl;
  cout<<"t. Termina programul;"<<endl;
}
