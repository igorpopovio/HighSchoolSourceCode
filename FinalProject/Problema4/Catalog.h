/*
  Nume: Catalog.h
  Autor: Popov Igor
  Descriere: Contine declaratiile claselor nod si Catalog
*/

#ifndef __CATALOG__H__
#define __CATALOG__H__

struct nod {
    char nume[30], prenume[30];
    float notaMate, notaInfo, media;
    nod * st, * dr;
};

const int NR_MAX = 50;

class Catalog {
  private:
    nod * prim;
    nod * ultim;
    int capacitate;
    int nrElemente;
  public:
    Catalog ( int marime = NR_MAX );
    bool eVida ( );
    bool ePlina ( );
    int dimensiuneMax ( );
    int arataNrElem ( );
    bool adaugaInceput ( char * nume, char * prenume,
                         float notaMate, float notaInfo );
    bool adaugaSfarsit ( char * nume, char * prenume,
                         float notaMate, float notaInfo );
    bool adaugaInterior ( char * nume, char * prenume,
                          float notaMate, float notaInfo, int poz );
    bool stergeInceput ( );
    bool stergeSfarsit ( );
    bool stergeInterior ( int poz );
    int getInfoFromPoz ( int poz );
    nod * getPrim ( );
    nod * getUltim ( );
    bool listareStDr ( );
    bool listareDrSt ( );
    void distruge ( );
    Catalog ( Catalog & lista );
    Catalog & operator= ( Catalog & lista );
    ~Catalog ( );
    void saveFile ( );
    void openFile ( );
};

#endif
