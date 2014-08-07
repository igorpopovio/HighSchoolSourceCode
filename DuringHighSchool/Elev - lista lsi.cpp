#include <conio.h>
#include <iostream.h>
struct nod
{
char nume[20],prenume[20],clasa[5];
float medie;
nod *adr;
}*p,*q,*prim;
int i,n,k;

void creare()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->nume= ";  cin>>p->nume;
cout<<"p->prenume= ";  cin>>p->prenume;
cout<<"p->clasa= ";  cin>>p->clasa;
cout<<"p->medie= ";  cin>>p->medie;
p->adr=NULL; prim=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->nume= ";  cin>>q->nume;
cout<<"p->prenume= ";  cin>>q->prenume;
cout<<"p->clasa= ";  cin>>q->clasa;
cout<<"p->medie= ";  cin>>q->medie;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void listare()
{
p=prim;
while(p)
{
cout<<"p->nume= "<<p->nume<<endl;
cout<<"p->prenume= "<<p->prenume<<endl;
cout<<"p->clasa= "<<p->clasa<<endl;
cout<<"p->medie= "<<p->medie<<endl;
p=p->adr;
}
cout<<endl<<endl;
}

void adaugare()
{
cout<<"k= ";  cin>>k;
p=prim;
for(i=1;i<(k-1);i++) p=p->adr;
q=new nod;
cout<<"p->nume= ";  cin>>q->nume;
cout<<"p->prenume= ";  cin>>q->prenume;
cout<<"p->clasa= ";  cin>>q->clasa;
cout<<"p->medie= ";  cin>>q->medie;
if(k==1)
{
q->adr=prim;  prim=q;
}
else
{
q->adr=p->adr;  p->adr=q;
}
cout<<endl;  n++;
}

void stergere()
{
cout<<"k= ";  cin>>k;  p=prim;
if(k==1)
{
prim=p->adr;  delete p;
}
else
{
for(i=1;i<k;i++) {q=p;  p=p->adr;}
q->adr=p->adr;  delete p;
}
cout<<endl; n--;
}

void main()
{
cout<<"1. creez o lista liniara simplu inlantuita cu n noduri "
    <<"in care se memoreaza\ndatele unui elev: "
    <<"nume, prenume, clasa, medie;"<<endl; creare();
cout<<"2. listez continutul listei;"<<endl;  listare();
cout<<"3. adaugam un nod pe pozitia k;"<<endl;     adaugare();
cout<<"4. listez continutul listei;"<<endl;  listare();
cout<<"5. stergem un nod de pe pozitia k;"<<endl;  stergere();
cout<<"6. listez continutul listei;"<<endl;  listare();
getch();
}