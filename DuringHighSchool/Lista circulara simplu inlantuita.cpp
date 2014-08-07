#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod *adr;
}*p,*q,*prim,*ultim;
int i,n,k;

void creare()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->info= ";  cin>>p->info;
prim=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->info= ";  cin>>q->info;
p->adr=q;   q->adr=prim;   ultim=p=q;
}
cout<<endl;
}

void listare()
{
cout<<"p->info= "<<prim->info<<"  ";  p=prim->adr;
while(p!=prim){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void adaugare()
{
cout<<"k= ";  cin>>k;
p=prim;
for(i=1;i<(k-1);i++) p=p->adr;
q=new nod;  cout<<"p->info= ";  cin>>q->info;
if(k==1)
{
q->adr=prim;  prim=q;   ultim->adr=prim;
}
else if(k==n)
{
ultim->adr=p;   p->adr=prim;
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
prim=prim->adr;  delete p;    ultim->adr=prim;
}
else if(k==n)
{
for(i=1;i<(n-1);i++)  p=p->adr;
delete ultim; ultim=p;  ultim->adr=prim;
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
cout<<"1. creez o lista circulara simplu inlantuita cu n noduri;"<<endl; creare();
cout<<"2. listez continutul listei;"<<endl;  listare();
cout<<"3. adaugam un nod pe pozitia k;"<<endl;     adaugare();
cout<<"4. listez continutul listei;"<<endl;  listare();
cout<<"5. stergem un nod de pe pozitia k;"<<endl;  stergere();
cout<<"6. listez continutul listei;"<<endl;  listare();
getch();
}