//Se considera o lista liniara de tip coada care retine temperatura intr-un 
//interval de timp ( temperatura + zi + luna ). Cerinte:
//  a) afisati temperatura minima din acea perioada;
//  b) calculati temperatura medie;
//  c) stergeti un element;

#include <conio.h>
#include <iostream.h>

struct nod {
  float temp;
  int zi, luna;
  nod * adr;
};

void pune ( nod *& v, nod *& sf ) {
  nod *c;
  if ( !v ) {
    v=new nod;  
    cout<<"c->temperatura= ";  cin>>v->temp;
    cout<<"c->ziua= ";  cin>>v->zi;
    cout<<"c->luna= ";  cin>>v->luna;
    v->adr=NULL;  sf=v;
  }
  else {
    c=new nod;  sf->adr=c;  
    cout<<"c->temperatura= ";  cin>>c->temp;
    cout<<"c->ziua= ";  cin>>c->zi;
    cout<<"c->luna= ";  cin>>c->luna;
    c->adr=NULL;   sf=c;
  }
}

void scoate ( nod *& v, nod *& sf ) {
  nod *c;
  if ( !v )  cout<<"coada este vida;"<<endl;
  else {
    cout<<"am scos nodul cu informatia: "<<endl;
    cout<<"c->temperatura= "<<v->temp<<endl;
    cout<<"c->ziua= "<<v->zi<<endl;
    cout<<"c->luna= "<<v->luna<<endl;
    c=v;  v=v->adr; delete c;
}
}

void listare ( nod *& v ) {
  nod * c=v;
  while ( c ) {
    cout<<"c->temperatura= "<<c->temp<<endl;
    cout<<"c->ziua= "<<c->zi<<endl;
    cout<<"c->luna= "<<c->luna<<endl;
    c=c->adr;
  }
cout<<endl;
}

float minim ( nod *& v ) {
  nod * c=v->adr;
  float min=v->temp;
  while ( c ) {
    if ( min>c->temp ) min=c->temp;
    c=c->adr;
  }
  return min;
}    

float medie ( nod *& v ) {
  nod * c=v;
  float m=0;
  int k=0;
  while ( c ) {
    m+=c->temp;
    k++;
    c=c->adr;
  }
  return m/k;
}  

int main ( ) {
  char a;
  nod * v=NULL, * sf=NULL;

  cout<<"MENIU"<<endl;
  cout<<"1. creare;"<<endl;
  cout<<"2. adaugare;"<<endl;
  cout<<"3. stergere;"<<endl;
  cout<<"4. listare;"<<endl;
  cout<<"5. minim;"<<endl;
  cout<<"6. medie;"<<endl;

  cout<<"Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
  while ( cin>>a && a!='T' && a!='t' ) {
    switch ( a ) {
      case '1': pune ( v, sf ); break;
      case '2': pune ( v, sf ); break;
      case '3': scoate ( v, sf );  cout<<endl<<"Apasati orice tasta pentru a continua . . . ";   getch ( );  break;
      case '4': listare ( v ); cout<<endl<<"Apasati orice tasta pentru a continua . . . ";   getch ( );  break;
      case '5': cout<<minim ( v ); cout<<endl<<"Apasati orice tasta pentru a continua . . . ";   getch ( ); break;
      case '6': cout<<medie ( v ); cout<<endl<<"Apasati orice tasta pentru a continua . . . ";   getch ( ); break;
      default: cout<<"Optiunea introdusa nu este disponibila!!!"<<endl;  break;
    }
    cout<<"MENIU"<<endl;
    cout<<"1. creare;"<<endl;
    cout<<"2. adaugare;"<<endl;
    cout<<"3. stergere;"<<endl;
    cout<<"4. listare;"<<endl;
    cout<<"5. minim;"<<endl;
    cout<<"6. medie;"<<endl;

    cout<<"Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
  }

}
