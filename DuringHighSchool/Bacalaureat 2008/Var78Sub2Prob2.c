#include <iostream>
using namespace std;

struct nod {
  int info;
  nod *urm;
};

int main ( ) {
  nod *prim, *p, *q;
  p = new nod;
  p->info = 1;
  prim = p;
  for ( int i = 1; i < 6; i++ ) {
    q = new nod;
    q->info = i + 1;
    p->urm = q;
    p = q;
  }
  q->urm = NULL;

  p = prim;
  while ( p->urm->urm->urm != NULL )
    p = p->urm;
  q = p->urm;
  p->urm = p->urm->urm;
  delete q;
  p = prim;
  while ( p ) {
    cout << p->info << " ";
    p = p->urm;
  }

  cin.get ( );
  return 0;
}
