/*
  Nume: ListaCDI.cpp
  Autor: Popov Igor
  Descriere: Implementeaza metodele clasei ListaCDI
*/

#include <fstream>
#include <iostream>
using namespace std;
#include "ListaCDI.h"


//Constructorul clasei ListaCDI
//Seteaza capacitatea maxima a listei
ListaCDI::ListaCDI ( long unsigned marime ) {
  prim = new nod;
  ultim = new nod;
  capacitate = marime;
  nrElemente = 0;
}

//Testeaza daca lista e vida
bool ListaCDI::eVida ( ) {
  return nrElemente == 0;
}

//Testeaza daca lista e plina
bool ListaCDI::ePlina ( ) {
  return capacitate == nrElemente;
}

//Returneaza capacitatea maxima a listei
int ListaCDI::dimensiuneMax ( ) {
  return capacitate;
}

//Returneaza numarul de elemente stocate curent in lista
int ListaCDI::arataNrElem ( ) {
  return nrElemente;
}

//Adauga la inceputul listei un element cu informatia inf
bool ListaCDI::adaugaInceput ( int inf ) {
  if ( !ePlina ( ) ) {
    nod * p = new nod;
    p->info = inf;
    if ( !eVida ( ) ) {
      p->dr = prim;  prim->st = p;  p->st = ultim;
      ultim->dr = p;  prim = p;
    }
    else {
      prim = ultim = p;
      prim->st = ultim;   ultim->dr = prim;
    }
    nrElemente ++;
    return 1;
  }
  else return 0;
}

//Adauga la sfarsitul listei un element cu informatia inf
bool ListaCDI::adaugaSfarsit ( int inf ) {
  if ( !ePlina ( ) ) {
    nod * p = new nod;
    p->info = inf;
    if ( !eVida ( ) ) {
      ultim->dr = p;  p->st = ultim;
      prim->st = p;   p->dr = prim;  ultim = p;
    }
    else {
      prim = ultim = p;
      prim->st = ultim;   ultim->dr = prim;
    }
    nrElemente ++;
    return 1;
  }
  else return 0;
}

//Adauga in interiorul listei pe pozitia poz un element cu informatia inf
bool ListaCDI::adaugaInterior ( int inf, int poz ) {
  if ( !ePlina ( ) && 1 < poz < nrElemente ) {
    nod * q, * r, * p = prim;
    for ( int i = 1; i < ( poz - 1 ); i ++ ) p = p->dr;
    q = new nod;  q->info = inf;
    r = p->dr;  p->dr = q;  q->st = p;
    q->dr = r;  r->st = q;
    nrElemente ++;
    return 1;
  }
  else return 0;
}

//Sterge de la inceputul listei un element
bool ListaCDI::stergeInceput ( ) {
  if ( !eVida ( ) ) {
    nod * p = prim;  prim = p->dr;  prim->st = ultim;
    ultim->dr = prim;  //delete p;
    nrElemente --;
    return 1;
  }
  else return 0;
}

//Sterge de la sfarsitul listei un element
bool ListaCDI::stergeSfarsit ( ) {
  if ( !eVida ( ) ) {
    nod * p = ultim;    ultim = p->st;
    ultim->dr = prim;   prim->st = ultim;  //delete p;
    nrElemente --;
    return 1;
  }
  else return 0;
}

//Sterge din interiorul listei de pe pozitia poz un element
bool ListaCDI::stergeInterior ( int poz ) {
  if ( !eVida ( ) && 1 < poz < nrElemente ) {
    nod * r, * s, * p = prim;
    for ( int i = 1; i < poz; i++ ) p = p->dr;
    r = p->st;  s = p->dr;
    r->dr = s;  s->st = r;  //delete p;
    nrElemente --;
    return 1;
  }
  else return 0;
}

//Listeaza informatiile din lista de la stanga la dreapta
bool ListaCDI::listareStDr ( ) {
  if ( !eVida ( ) ) {
    nod * p = prim;
    do {
      cout<<p->info<<"  ";  p = p->dr;
    } while ( p != prim );
    cout<<endl;
    return 1;
  }
  else return 0;
}

//Listeaza informatiile din lista de la dreapta la stanga
bool ListaCDI::listareDrSt ( ) {
  if ( !eVida ( ) ) {
    nod * p = ultim;
    do {
      cout<<p->info<<"  ";  p = p->st;
    } while ( p != ultim );
    cout<<endl;
    return 1;
  }
  else return 0;
}

//returneaza elementu de pe pozitia poz din lista
int ListaCDI::getInfoFromPoz ( int poz ) {
  nod * p = prim;
  int x;
  int k;
  for ( k = 0; k < ( poz - 1 ); k ++ ) p = p->dr;
  x = p->info;
  return x;
}

//returneaza primul element al listei
nod * ListaCDI::getPrim ( ) {
  return prim;
}

//returneaza ultimul element al listei
nod * ListaCDI::getUltim ( ) {
  return ultim;
}

//Constructorul de copiere al clasei ListaCDI
ListaCDI::ListaCDI ( ListaCDI & lista ) {
  if ( !eVida ( ) ) {
    nod * p = lista.getPrim ( );
    do {
      adaugaSfarsit ( p->info );
    } while ( p != lista.getPrim ( ) );
  }
}

//Operatorul de atribuire al clasei ListaCDI
ListaCDI & ListaCDI::operator= ( ListaCDI & lista ) {
  if ( this == &lista ) return *this;
  else {
    if ( !eVida ( ) ) {
      nod * p = lista.getPrim ( );
      do {
        adaugaSfarsit ( p->info );
      } while ( p != lista.getPrim ( ) );
    }
  }
}

//sterge toate elementele din lista
void ListaCDI::distruge ( ) {
  while ( !eVida ( ) ) stergeInceput ( );
}


//Destructorul clasei ListaCdI
//Se asigura ca lista e goala, daca nu atunci sterge fiecare element
ListaCDI::~ListaCDI ( ) {
  while ( !eVida ( ) ) stergeInceput ( );
}

//Citirea elementelor listei dintr-un fisier
void ListaCDI::readFile ( char * adrFisier ) {
  fstream f ( adrFisier, ios::in );
  int x;
  while ( !f.eof ( ) ) {
    f>>x;
    this->adaugaSfarsit ( x );
  }
  f.close ( );
}
