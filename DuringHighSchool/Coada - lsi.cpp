#include <conio.h>
#include <iostream.h>
struct nod {
  int info;
  nod * adr;
}*v, *sf;
int n;

void pune() {
  nod *c;
  if ( !v ) {
    v = new nod;
    cout << "c->info= ";
    cin >> v->info;
    v->adr = NULL;
    sf = v;
  } else {
    c = new nod;
    sf->adr = c;
    cout << "c->info= ";
    cin >> c->info;
    c->adr = NULL;
    sf = c;
  }
}

void scoate() {
  nod *c;
  if ( !v )  cout << "coada este vida;" << endl;
  else {
    cout << "am scos nodul cu informatia: " << v->info << ";" << endl;
    c = v;
    v = v->adr;
    delete c;
  }
}

void listare() {
  nod * c = v;
  while ( c ) {
    cout << "c->info= " << c->info << endl;
    c = c->adr;
  }
  cout << endl;
}

void main() {
  char a;

  cout << "MENIU" << endl;
  cout << "1. creare;" << endl;
  cout << "2. adaugare;" << endl;
  cout << "3. stergere;" << endl;
  cout << "4. listare;" << endl;

  cout << "Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
  while ( cin >> a && a != 'T' && a != 't' ) {
    switch ( a ) {
      case '1':
        pune();
        break;
      case '2':
        pune();
        break;
      case '3':
        scoate();
        cout << "Apasati orice tasta pentru a continua . . . ";
        getch();
        break;
      case '4':
        listare();
        cout << "Apasati orice tasta pentru a continua . . . ";
        getch();
        break;
      default:
        cout << "Optiunea introdusa nu este disponibila!!!" << endl;
        break;
    }
    clrscr();
    cout << "MENIU" << endl;
    cout << "1. creare;" << endl;
    cout << "2. adaugare;" << endl;
    cout << "3. stergere;" << endl;
    cout << "4. listare;" << endl;

    cout << "Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
  }

}
