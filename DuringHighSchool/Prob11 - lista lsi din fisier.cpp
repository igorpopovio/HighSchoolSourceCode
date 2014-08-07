#include <fstream.h>
#include <conio.h>
#include <iostream.h>
struct nod
{
unsigned long info;
nod *adr;
}*p,*q,*prim;
int i,n=0;
unsigned long k;

void creare()
{
fstream fis("lista.in",ios::in);
p=new nod;
fis>>k;   p->info=k; n++;
p->adr=NULL; prim=p;
while(fis>>k && !fis.eof())
{
q=new nod;  n++;   q->info=k;
p->adr=q;  p=q;
}
p->adr=NULL; 
fis.close();
}

void listare()
{
p=prim;   i=0;
while(p){cout<<p->info<<"  ";   if(i%12==11) cout<<endl; i++; p=p->adr;}
cout<<endl<<endl;
}

void main()
{
cout<<"1. creez o lista liniara simplu inlantuita "
    <<"cu numerele din fisierul \"lista.in\";"<<endl; creare();
cout<<"2. listez continutul listei;"<<endl;  listare();
getch();
}