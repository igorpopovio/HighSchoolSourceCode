#include <iostream.h>
#include <fstream.h>
#include <conio.h>
struct nod
{
int info;
nod *adr;
}*prim,*p,*q;

nod *prim1,*prim2;
void citeste()
{
int k;
fstream fis("numere.in",ios::in);
fis>>k;
p=new nod;  p->info=k;  p->adr=NULL;  prim=p;
while(fis>>k && !fis.eof())
{
q=new nod;  q->info=k;
q->adr=NULL;  p->adr=q; p=q;
}
fis.close();
}

void separa()
{
nod *r,*s,*w,*v;
prim1=NULL;
prim2=NULL;
p=prim;
while(p)
{
if( p -> info % 2 == 0 )
  {if(prim1==NULL){r=new nod;    r->info=p->info;  r->adr=NULL;    prim1=r;}
    else   {s=new nod;    s->info=p->info;  s->adr=NULL;    r->adr=s;   r=s;}}
  else
    {if(prim2==NULL){w=new nod;    w->info=p->info;  w->adr=NULL;    prim2=w;}
      else   {v=new nod;    v->info=p->info;  v->adr=NULL;    w->adr=v;   w=v;}}

p=p->adr;
}
}

void afiseaza()
{
cout<<"nr.pare:"<<endl;
p=prim1;
while(p){cout<<p->info<<"  "; p=p->adr;}
cout<<endl<<"nr.impare:"<<endl;
p=prim2;
while(p){cout<<p->info<<"  "; p=p->adr;}
}

void memoreaza()
{
fstream fout("liste.out",ios::out);
fout<<"nr.pare:"<<endl;
p=prim1;
while(p){fout<<p->info<<"  "; p=p->adr;}
fout<<endl<<"nr.impare:"<<endl;
p=prim2;
while(p){fout<<p->info<<"  "; p=p->adr;}
fout.close();
}

void main()
{
citeste();  separa();
cout<<"Nr. se citesc din fisierul \"numere.in\""
    <<"\nsi se afiseaza in fisierul \"liste.out\"\n";
afiseaza(); memoreaza();

getch();
}



