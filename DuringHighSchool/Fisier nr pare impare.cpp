#include <iostream.h>
#include <conio.h>
#include <fstream.h>
void main() {
  char nume2[20], nume3[20];
  int nr;
  cout << "Numele fisierului sursa este: Fisier sursa!";
  cout << "Numele fisierului cu numere pare este: ";
  cin >> nume2;
  cout << "Numele fisierului cu numere impare este: ";
  cin >> nume3;
  fstream f1 ( "Fisier sursa.txt", ios::in ), f2 ( nume2, ios::out ), f3 ( nume3, ios::out );
  f1 >> nr;
  while ( !f1.eof() ) {
    if ( nr % 2 == 0 ) f2 << nr << endl;
    else f3 << nr << endl;
    f1 >> nr;
  }
  f1.close();
  f2.close();
  f3.close();
  getch();
}
