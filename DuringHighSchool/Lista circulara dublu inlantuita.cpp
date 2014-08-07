#include <iostream>
using namespace std;

struct nod {
  int info;
  nod * st,* dr;
};

struct ListaCDI {
  nod * prim;
  nod * ultim;
  int n;
};

void creare ( ListaCDI & lista ) {
  nod * p, * q;
  p = new nod;
  cout<<"p->info= ";  cin>>p->info;
  lista.prim = lista.ultim = p;
  lista.prim->st = lista.ultim;   lista.ultim->dr = lista.prim;
  for ( int i = 2; i <= lista.n; i++ ) {
    q = new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr = q;  q->st = p;
    p = q;
  }
  p->dr = lista.prim;
  lista.ultim = p;
  lista.prim->st = lista.ultim;
  cout<<endl;
}

void list_st_dr ( ListaCDI & lista ) {
  nod * p = lista.prim;
  do {
    cout<<p->info<<"  ";  p = p->dr;
  } while ( p != lista.prim );
  cout<<endl<<endl;
}

void list_dr_st ( ListaCDI & lista ) {
  nod * p = lista.ultim;
  do {
    cout<<p->info<<"  ";  p = p->st;
  } while ( p != lista.ultim );
  cout<<endl<<endl;
}

void adaugare ( ListaCDI & lista, int k ) {
  nod * p, * q, * r;
  if ( k == 1 ) {
    p = new nod;  cout<<"p->info= ";  cin>>p->info;
    lista.ultim->dr = p;  lista.prim->st = p;  p->dr = lista.prim;
    p->st = lista.ultim;  lista.prim = p;
  }
  else if ( k == lista.n ) {
    p = new nod;  cout<<"p->info= ";  cin>>p->info;
    lista.ultim->dr = p;  p->st = lista.ultim;
    lista.prim->st = p;   p->dr = lista.prim;  lista.ultim = p;
  }
  else {
    p = lista.prim;
    for ( int i = 1; i < ( k - 1 ); i ++ ) p = p->dr;
    q = new nod;  cout<<"p->info= ";  cin>>q->info;
    r = p->dr;  p->dr = q;  q->st = p;
    q->dr = r;  r->st = q;
  }
  cout<<endl;  lista.n ++;
}

void stergere ( ListaCDI & lista, int k ) {
  nod * r, * s, * p, * q;
  if ( k==1 ) {
    p = lista.prim;  lista.prim = p->dr;  lista.prim->st = lista.ultim;
    lista.ultim->dr = lista.prim;  delete p;
  }
  else if ( k == ( lista.n - 1 ) ) {
    p = lista.ultim;  lista.ultim = p->st;
    lista.ultim->dr = lista.prim;   lista.prim->st = lista.ultim;  delete p;
  }
  else {
    p = lista.prim;
    for ( int i = 1; i < k; i++ ) p = p->dr;
    r = p->st;  s = p->dr;
    r->dr = s;  s->st = r;  delete p;
  }
  cout<<endl; lista.n --;
}

int main ( ) {
  ListaCDI lista;
  int k;

  cout<<"1. creez o lista circulara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>lista.n;  creare ( lista );
  cout<<"2. listez de la stanga la dreapta;"<<endl;  list_st_dr ( lista );
  cout<<"3. listez de la dreapta la stanga;"<<endl;  list_dr_st ( lista );
  cout<<"4. adaugam un nod pe pozitia k;"<<endl;
  cout<<"k= ";  cin>>k;  adaugare ( lista, k );
  cout<<"5. listez de la stanga la dreapta;"<<endl;  list_st_dr ( lista );
  cout<<"6. stergem un nod de pe pozitia k;"<<endl;
  cout<<"k= ";  cin>>k;  stergere ( lista, k );
  cout<<"7. listez de la stanga la dreapta;"<<endl;  list_st_dr ( lista );

  cin.get ( );
  cin.get ( );
  return 0;
}
