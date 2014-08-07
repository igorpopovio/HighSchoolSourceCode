/*
  Nume: Catalog.cpp
  Autor: Popov Igor
  Descriere: Implementeaza metodele clasei Catalog
*/

#include <fstream>
#include <iostream>
using namespace std;
#include "Catalog.h"


//Constructorul clasei Catalog
//Seteaza capacitatea maxima a listei
Catalog::Catalog ( int marime ) {
  prim = new nod;
  ultim = new nod;
  capacitate = marime;
  nrElemente = 0;
}

//Testeaza daca lista e vida
bool Catalog::eVida ( ) {
  return nrElemente == 0;
}

//Testeaza daca lista e plina
bool Catalog::ePlina ( ) {
  return capacitate == nrElemente;
}

//Returneaza capacitatea maxima a listei
int Catalog::dimensiuneMax ( ) {
  return capacitate;
}

//Returneaza numarul de elemente stocate curent in lista
int Catalog::arataNrElem ( ) {
  return nrElemente;
}

//Adauga la inceputul listei un element cu informatia inf
bool Catalog::adaugaInceput ( char * nume, char * prenume,
                              float notaMate, float notaInfo ) {
  if ( !ePlina ( ) ) {
    nod * p = new nod;
    strcpy ( p->nume, nume );
    strcpy ( p->prenume, prenume );
    p->notaMate = notaMate;
    p->notaInfo = notaInfo;
    p->media = ( notaMate + notaInfo )/2;
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
bool Catalog::adaugaSfarsit ( char * nume, char * prenume,
                              float notaMate, float notaInfo ) {
  if ( !ePlina ( ) ) {
    nod * p = new nod;
    strcpy ( p->nume, nume );
    strcpy ( p->prenume, prenume );
    p->notaMate = notaMate;
    p->notaInfo = notaInfo;
    p->media = ( notaMate + notaInfo )/2;
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
bool Catalog::adaugaInterior ( char * nume, char * prenume,
                              float notaMate, float notaInfo, int poz ) {
  if ( !ePlina ( ) && 1 < poz < nrElemente ) {
    nod * q, * r, * p = prim;
    for ( int i = 1; i < ( poz - 1 ); i ++ ) p = p->dr;
    q = new nod;
    strcpy ( q->nume, nume );
    strcpy ( q->prenume, prenume );
    q->notaMate = notaMate;
    q->notaInfo = notaInfo;
    q->media = ( notaMate + notaInfo )/2;
    r = p->dr;  p->dr = q;  q->st = p;
    q->dr = r;  r->st = q;
    nrElemente ++;
    return 1;
  }
  else return 0;
}

//Sterge de la inceputul listei un element
bool Catalog::stergeInceput ( ) {
  if ( !eVida ( ) ) {
    nod * p = prim;  prim = p->dr;  prim->st = ultim;
    ultim->dr = prim;  //delete p;
    nrElemente --;
    return 1;
  }
  else return 0;
}

//Sterge de la sfarsitul listei un element
bool Catalog::stergeSfarsit ( ) {
  if ( !eVida ( ) ) {
    nod * p = ultim;    ultim = p->st;
    ultim->dr = prim;   prim->st = ultim;  //delete p;
    nrElemente --;
    return 1;
  }
  else return 0;
}

//Sterge din interiorul listei de pe pozitia poz un element
bool Catalog::stergeInterior ( int poz ) {
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
bool Catalog::listareStDr ( ) {
  if ( !eVida ( ) ) {
    nod * p = prim;
    do {
      cout<<"Nume: "<<p->nume<<endl;
      cout<<"Prenume: "<<p->prenume<<endl;
      cout<<"NotaMate: "<<p->notaMate<<endl;
      cout<<"NotaInfo: "<<p->notaInfo<<endl;
      cout<<"Media: "<<p->media<<endl<<endl;
      p = p->dr;
    } while ( p != prim );
    cout<<endl;
    return 1;
  }
  else return 0;
}

//Listeaza informatiile din lista de la dreapta la stanga
bool Catalog::listareDrSt ( ) {
  if ( !eVida ( ) ) {
    nod * p = ultim;
    do {
      cout<<"Nume: "<<p->nume<<endl;
      cout<<"Prenume: "<<p->prenume<<endl;
      cout<<"NotaMate: "<<p->notaMate<<endl;
      cout<<"NotaInfo: "<<p->notaInfo<<endl;
      cout<<"Media: "<<p->media<<endl<<endl;
      p = p->st;
    } while ( p != ultim );
    cout<<endl;
    return 1;
  }
  else return 0;
}

//returneaza primul element al listei
nod * Catalog::getPrim ( ) {
  return prim;
}

//returneaza ultimul element al listei
nod * Catalog::getUltim ( ) {
  return ultim;
}

//Constructorul de copiere al clasei Catalog
Catalog::Catalog ( Catalog & lista ) {
  if ( !eVida ( ) ) {
    nod * p = lista.getPrim ( );
    do {
      adaugaSfarsit ( p->nume, p->prenume, p->notaMate, p->notaInfo );
    } while ( p != lista.getPrim ( ) );
  }
}

//Operatorul de atribuire al clasei Catalog
Catalog & Catalog::operator= ( Catalog & lista ) {
  if ( this == &lista ) return *this;
  else {
    if ( !eVida ( ) ) {
      nod * p = lista.getPrim ( );
      do {
        adaugaSfarsit ( p->nume, p->prenume, p->notaMate, p->notaInfo );
      } while ( p != lista.getPrim ( ) );
    }
  }
}

//sterge toate elementele din lista
void Catalog::distruge ( ) {
  while ( !eVida ( ) ) stergeInceput ( );
}


//Destructorul clasei Catalog
//Se asigura ca lista e goala, daca nu atunci sterge fiecare element
Catalog::~Catalog ( ) {
  while ( !eVida ( ) ) stergeInceput ( );
}

void Catalog::saveFile ( ) {
  fstream f ( "Catalog.cat", ios::out );
  nod * p = prim;
  do {
    f<<p->nume<<endl;
    f<<p->prenume<<endl;
    f<<p->notaMate<<endl;
    f<<p->notaInfo<<endl<<endl;
    p = p->dr;
    } while ( p != prim );
  f.close ( );
}

void Catalog::openFile ( ) {
  fstream f ( "Catalog.cat", ios::in );
  this->distruge ( );
  char nume[30], prenume[30];
  float notaMate, notaInfo;
  while ( !f.eof ( ) ) {
    f>>nume>>prenume>>notaMate>>notaInfo;
    this->adaugaSfarsit ( nume, prenume, notaMate, notaInfo );
  }
}

