#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod *adr;
}*p,*q,*prim;
int i,n;

void creare()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->info= ";  cin>>p->info;
p->adr=NULL; prim=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->info= ";  cin>>q->info;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void listare()
{
p=prim;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void inversare()
{
int aux;
p=prim;   while(p->adr!=NULL) p=p->adr;
aux=prim->info;   prim->info=p->info;   p->info=aux;
}

void elibereaza_spatiul()
{
p=prim;
while(p)  {q=p; p=p->adr; delete q;}
}

void main()
{
cout<<"1. creez o lista liniara simplu inlantuita cu n noduri;"<<endl; creare();
cout<<"2. inversez primul nod cu ultimul nod;"<<endl;   inversare();
cout<<"3. listez nodurile in noua ordine;"<<endl;   listare();
cout<<"4. eliberez spatiul ocupat de lista lsi;"<<endl;   elibereaza_spatiul();

getch();
}

