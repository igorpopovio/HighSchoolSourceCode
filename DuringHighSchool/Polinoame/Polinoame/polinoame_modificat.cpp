#include <iostream.h>
#include <conio.h>

struct nod {
  float coeficient;
  unsigned grad;
  nod * adr;
};

void adaug ( nod *& prim, float cf, unsigned gr ) {
  nod * p, * q, * r;
  p=new nod;
  p->grad=gr;
  p->coeficient=cf;
  p->adr=NULL;
  if ( !prim ) prim=p;
  else {
    if ( prim->grad<p->grad ) {
      p->adr=prim;
      prim=p;
    }
    else {
      q=prim->adr;
      r=prim;
      while ( q ) {
        if ( q->grad<p->grad ) {
          r->adr=p;
          p->adr=q;
          break;
        }
        r=q;
        q=q->adr;
      }
    }
  }
}

void adaug2 ( nod *& prim, float cf, unsigned gr ) {
  nod * p, * q, * r;
  p=new nod;
  p->grad=gr;
  p->coeficient=cf;
  p->adr=NULL;
  q=prim;
  if ( q->grad<p->grad ) {
    p->adr=prim;
    prim=p;
  }
  else {
    while ( q->grad>p->grad ) {
      r=q;
      q=q->adr;
    } 
    p->adr=q;
    r->adr=p;
  }   
}

void adaug1 ( nod *& prim, float cf, unsigned gr ) {
  nod *c,*p;
  c=new nod;
  c->grad=gr;
  c->coeficient=cf;
  c->adr=NULL;
  if ( !prim ) prim=c;
  else {
    p=prim;
    while ( p->adr ) p=p->adr;
    p->adr=c;
    p=c;
  }
}        

void creare ( nod *& prim, unsigned & n ) {
  float cf;
  unsigned gr;
  for ( int i=0; i<n; i++ ) {
    cout<<"gradul= ";	cin>>gr;
    cout<<"coeficientul= ";		cin>>cf;
    adaug1 ( prim, cf, gr );
  }
}    

void sterg ( nod *& prim ) {
  nod * p=prim;
  while ( prim ) {
    prim=prim->adr;
    delete p;
    p=prim;
  }
}

void afiseaza ( nod *& prim ) {
  int i=0;
  nod * p=prim;
  while ( p ) {
    if ( i ) cout<<"+";
    cout<<p->coeficient<<"x^"<<p->grad;
    p=p->adr; i++;
  }
  cout<<endl<<endl;
}

nod * adunare ( nod * prim1, nod * prim2 ) {
  nod * p1=prim1;
  nod * p2=prim2;
  nod * prim;
  while ( p1 && p2 ) 
  if ( p1->grad==p2->grad ) {
    if ( p1->coeficient+p2->coeficient )
      adaug1 ( prim1, ( p1->coeficient+p2->coeficient ), p1->grad );
    p1=p1->adr;
    p2=p2->adr;
  }
  else 
    if ( p1->grad>p2->grad ) {
      adaug1 ( prim1, p1->coeficient, p1->grad );
      p1=p1->adr;
    }
    else {
      adaug1 ( prim1, p2->coeficient, p2->grad );
      p2=p2->adr; 
    } 
  if ( p1 ) {
    while ( p1 ) {
    	adaug1 ( prim1, p1->coeficient, p1->grad );
    	p1=p1->adr;
   	}
  }
  else {
  	while ( p2 ) {
    	adaug1 ( prim1, p2->coeficient, p2->grad );
    	p2=p2->adr;
  	} 
  } 	
  return prim1;
} 

nod * negativ ( nod * prim ) {
  nod * prim1=NULL;
  while ( prim ) {
    adaug1 ( prim1, -prim->coeficient, prim->grad );
    prim=prim->adr;
  }
  return prim1;
}

nod * mulmonom ( nod * prim, float cf, unsigned gr ) { 
  nod * prim1=NULL, * ultim1;
  while ( prim ) {
    adaug1 ( prim1, prim1->coeficient*cf, prim1->grad+gr );
    prim=prim->adr;
  }
  return prim1;
}

nod * mul ( nod * prim1, nod * prim2 ) {
  nod * prim=NULL;
  while ( prim2 ) {
    nod * aux=NULL, * aux1;
    aux=mulmonom ( prim1, prim2->coeficient, prim2->grad );
    aux1=prim;
    prim=adunare ( prim, aux );
    sterg ( aux );
    sterg ( aux1 );
    prim2=prim2->adr;
  }
  return prim;
}
       
void divp ( nod * deim, nod * imp, nod *& cat, nod *& rest ) {
  float coef;
  unsigned gradul;
  cat=rest=NULL;
  while ( deim ) {
    adaug1 ( rest, deim->coeficient, deim->grad );
    deim=deim->adr;
  }
  while ( rest->grad>=imp->grad ) {
    coef=rest->coeficient/imp->coeficient;
    gradul=rest->grad-imp->grad;
    adaug1 ( cat, coef, gradul );
    nod * factor=NULL;
    adaug1 ( factor, coef, gradul );
    nod * pol=mul ( imp, factor );
    sterg ( factor );
    nod * neg=negativ ( pol );
    sterg ( pol );
    rest=adunare ( rest, neg );
    sterg ( neg );
  }
}
           
int main ( ) {
  unsigned m,n;
  nod * prim1=NULL, *prim2=NULL, * cat, * rest, * aux;
  cout<<"Nr termeni primul polinom= ";
  cin>>m;
  creare ( prim1, m );
  afiseaza ( prim1 );
  cout<<"Nr termeni al doilea polinom= ";
  cin>>n;
  creare ( prim2, n );
  afiseaza ( prim2 );
  cout<<"suma:\n";
  aux=adunare ( prim1, prim2 );
  afiseaza ( aux );
  cout<<"diferenta:\n";
  aux=adunare ( prim1, negativ ( prim2 ) );
  afiseaza ( aux );
  cout<<"produs:\n";
  aux=mul ( prim1, prim2 );
  afiseaza ( aux );
  cout<<"cat:\n";
  divp ( prim1, prim2, cat, rest );
  afiseaza ( cat );
  cout<<"rest:\n";
  aux=adunare ( prim1, prim2 );
  if ( !rest ) cout<<"0";
  else afiseaza ( rest );
  getch ( );
  return 0;
}  
  
  
                                 
        
