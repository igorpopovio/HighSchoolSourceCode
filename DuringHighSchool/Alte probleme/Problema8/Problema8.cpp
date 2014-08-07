//Fiind data o lista liniara dublu inlantuita sa se separe in doua liste 
//numerele pare si nepare.

#include <conio.h>
#include <iostream.h>

struct nod {
  int info;
  nod * st, * dr;
};

void creare ( nod *& prim, nod *& ultim, int n ) {
  nod * p, * q;
  p=new nod;
  cout<<"p->info= ";  cin>>p->info;
  p->st=p->dr=NULL;   prim=ultim=p;
  for ( int i=2; i<=n ; i++ ) {
    q=new nod;
    cout<<"p->info= ";  cin>>q->info;
    p->dr=q;  q->st=p;
    q->dr=NULL;   p=q;
  }
  ultim=p;
  cout<<endl;
}

void separa ( nod *& prim, nod *& par, nod *& impar ) {
  nod * p, * r, * s, * w, * v;
  p=prim;
  while ( p ) {
    if (  p->info%2==0 ) {
      if ( par == NULL ) { r=new nod;    r->info=p->info;  r->st=r->dr=NULL;    par=r;
      }
        else   { s=new nod;    s->info=p->info;  s->dr=NULL;  s->st=r;  r->dr=s;   r=s;
        }
      }
        else { if ( impar == NULL ) { w=new nod;    w->info=p->info;  w->st=w->dr=NULL;    impar=w;
               }
               else   {v=new nod;    v->info=p->info;  v->dr=NULL;  v->st=w;   w->dr=v;   w=v;
               }
    }

  p=p->dr;
  }
}

void list_st_dr ( nod *& prim ) {
  nod * p;
  p=prim;
  while ( p ) {
    cout<<p->info<<"  ";
    p=p->dr;
  }
  cout<<endl<<endl;
}

int main ( ) {
  int n;
  nod * prim, * ultim, * par=NULL, * impar=NULL;
  nod * p, * q;
  cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl;
  cout<<"n= ";  cin>>n;   creare ( prim, ultim, n );
  separa ( prim, par, impar );
  cout<<"2. afisez lista de la stanga la dreapta cu nr pare;"<<endl;
  list_st_dr ( par );
  cout<<"3. afisez lista de la stanga la dreapta cu nr impare;"<<endl;
  list_st_dr ( impar );
  getch ( );
  return 0;
}
