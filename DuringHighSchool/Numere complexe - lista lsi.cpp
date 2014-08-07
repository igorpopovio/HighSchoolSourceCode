#include <conio.h>
#include <iostream.h>
struct nod
{
int re,im;
nod *adr;
}*p,*q,*prim;
int i,n,k;

void creare()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->re= ";  cin>>p->re;
cout<<"p->im= ";  cin>>p->im;
p->adr=NULL; prim=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->re= ";  cin>>q->re;
cout<<"p->im= ";  cin>>q->im;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void listare()
{
p=prim;
while(p)
{
cout<<"p->re= "<<p->re<<endl;
cout<<"p->im= "<<p->im<<endl;
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
cout<<"p->re= ";  cin>>q->re;
cout<<"p->im= ";  cin>>q->im;
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

void suma()
{
nod * suma=new nod;
suma->re=0;   suma->im=0;
p=prim;
while(p)
{
suma->re+=p->re;
suma->im+=p->im;
p=p->adr;
}
cout<<endl;
cout<<"suma->re= "<<suma->re<<endl;
cout<<"suma->im= "<<suma->im<<endl;
}

void main()
{
cout<<"1. creez o lista liniara simplu inlantuita cu n noduri\n"
    <<"ce memoreaza nr. complexe;"<<endl; creare();
cout<<"2. listez continutul listei;"<<endl;  listare();
cout<<"3. afisam suma nr. complexe din lista;"<<endl;   suma();
cout<<"4. adaugam un nod pe pozitia k;"<<endl;     adaugare();
cout<<"5. listez continutul listei;"<<endl;  listare();
cout<<"6. stergem un nod de pe pozitia k;"<<endl;  stergere();
cout<<"7. listez continutul listei;"<<endl;  listare();
getch();
}