/*
  Nume: Programul4.cpp
  Autor: Popov Igor
  Descriere: Testeaza metodele clasei Catalog
*/

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Catalog.h"

//prototipuri de functii
void meniu ( );

int main ( ) {
  char c;
  Catalog cat ( 20 );
  int p;
  char nume[30], prenume[30];
  float notaMate, notaInfo;

  do {
    system ( "CLS" );
    meniu ( );
    cout<<"Optiunea Dumneavoastra: ";  cin>>c;
    switch ( c ) {
      case '1':
        cout<<"Nume: ";       cin>>nume;
        cout<<"Prenume: ";    cin>>prenume;
        cout<<"Nota Mate: ";  cin>>notaMate;
        cout<<"Nota Info: ";  cin>>notaInfo;
        cat.adaugaInceput ( nume, prenume, notaMate, notaInfo );
        break;
      case '2':
        cout<<"Nume: ";       cin>>nume;
        cout<<"Prenume: ";    cin>>prenume;
        cout<<"Nota Mate: ";  cin>>notaMate;
        cout<<"Nota Info: ";  cin>>notaInfo;
        cat.adaugaSfarsit ( nume, prenume, notaMate, notaInfo );
        break;
      case '3':
        cout<<"Nume: ";       cin>>nume;
        cout<<"Prenume: ";    cin>>prenume;
        cout<<"Nota Mate: ";  cin>>notaMate;
        cout<<"Nota Info: ";  cin>>notaInfo;
        cout<<"pozitia: ";    cin>>p;
        cat.adaugaInterior ( nume, prenume, notaMate, notaInfo, p );
        break;
      case '4':
        cat.stergeInceput ( );
        break;
      case '5':
        cat.stergeSfarsit ( );
        break;
      case '6':
        cout<<"pozitia: ";  cin>>p;
        cat.stergeInterior ( p );
        break;
      case '7':
        cat.listareStDr ( );
        system ( "PAUSE" );
        break;
      case '8':
        cat.listareDrSt ( );
        system ( "PAUSE" );
        break;
      case '9':
        cat.openFile ( );
        break;
      default:
        c='t';
        cat.saveFile ( );
        break;
    }
  } while ( c!='t' );
  cout<<"La revedere!";
  cin.get ( );
  cin.get ( );
  return 0;
}

void meniu ( ) {
  cout<<"1. Adaugati un elev la inceputul catalogului;"<<endl;
  cout<<"2. Adaugati un elev la sfarsitul catalogului;"<<endl;
  cout<<"3. Adaugati un elev pe o pozitie p in interiorul catalogului;"<<endl;
  cout<<"4. Stergeti un elev de la inceputul catalogului;"<<endl;
  cout<<"5. Stergeti un elev de la sfarsitul catalogului;"<<endl;
  cout<<"6. Stergeti un elev de pe o pozitie p in interiorul catalogului;"<<endl;
  cout<<"7. Afisati catalogul de la stanga la dreapta;"<<endl;
  cout<<"8. Afisati catalogul de la dreapta la stanga;"<<endl;
  cout<<"9. Deschide fisier;"<<endl;
  cout<<"t. Termina programul ( si salveaza );"<<endl;
}
