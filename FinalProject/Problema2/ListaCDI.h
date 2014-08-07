/*
  Nume: ListaCDI.h
  Autor: Popov Igor
  Descriere: Contine declaratiile claselor nod si ListaCDI
*/

#ifndef __ListaCDI__H__
#define __ListaCDI__H__

struct nod {
    int info;
    nod * st, * dr;
};

const int NR_MAX = 50;

class ListaCDI {
  private:
    nod * prim;
    nod * ultim;
    long unsigned capacitate;
    long unsigned nrElemente;
  public:
    ListaCDI ( long unsigned marime = NR_MAX );
    bool eVida ( );
    bool ePlina ( );
    int dimensiuneMax ( );
    int arataNrElem ( );
    bool adaugaInceput ( int inf );
    bool adaugaSfarsit ( int inf );
    bool adaugaInterior ( int inf, int poz );
    bool stergeInceput ( );
    bool stergeSfarsit ( );
    bool stergeInterior ( int poz );
    int getInfoFromPoz ( int poz );
    nod * getPrim ( );
    nod * getUltim ( );
    bool listareStDr ( );
    bool listareDrSt ( );
    void distruge ( );
    ListaCDI ( ListaCDI & lista );
    ListaCDI & operator= ( ListaCDI & lista );
    ~ListaCDI ( );
    void readFile ( char * adrFisier="lista.txt" );
};

#endif
