#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod * adr;
}*v;
int n;

void push()
{
nod *c;
if(!v)
{
v=new nod;  cout<<"c->info= ";  cin>>v->info;
v->adr=NULL;
}
else
{
c=new nod;  cout<<"c->info= ";  cin>>c->info;
c->adr=v;   v=c;
}
}

void pop()
{
nod *c;
if(!v)  cout<<"stiva este vida;"<<endl;
else
{
c=v;  cout<<"am scos nodul cu informatia: "<<c->info<<";"<<endl;
v=v->adr; delete c;
}
}

void main()
{
char a;

cout<<"MENIU"<<endl;
cout<<"1. creare;"<<endl;
cout<<"2. adaugare;"<<endl;
cout<<"3. stergere;"<<endl;

cout<<"Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
while(cin>>a && a!='T' && a!='t')
{
switch(a)
{
case '1': push(); break;
case '2': push(); break;
case '3': pop();  cout<<"Apasati orice tasta pentru a continua . . . ";   getch();  break;
default: cout<<"Optiunea introdusa nu este disponibila!!!"<<endl;  break;
}
clrscr();
cout<<"MENIU"<<endl;
cout<<"1. creare;"<<endl;
cout<<"2. adaugare;"<<endl;
cout<<"3. stergere;"<<endl;

cout<<"Introduceti optiunea dvs.(nr.optiunii) -- pentru a termina apasati tasta \'t\': ";
}

}
