#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod *adr;
}*p,*q,*prim1,*prim2,*prim3;
int i,n,m;

void creare1()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->info= ";  cin>>p->info;
p->adr=NULL; prim1=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->info= ";  cin>>q->info;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void creare2()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->info= ";  cin>>p->info;
p->adr=NULL; prim2=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->info= ";  cin>>q->info;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}

void listare1()
{
p=prim1;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void listare2()
{
p=prim2;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void listare3()
{
p=prim3;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void concatenare()
{
nod * r;
p=prim1->adr;
prim3=new nod;
prim3->info=prim1->info;    r=prim3;
while(p)
{
q=new nod;
q->info=p->info;
r->adr=q;   r=r->adr;   p=p->adr;
}
p=prim2;
while(p)
{
q=new nod;
q->info=p->info;
r->adr=q;   r=r->adr;   p=p->adr;
}
r->adr=NULL;
}

void impar()
{
p=prim3;
while(p)
{
if(p->info%2==1) cout<<p->info<<";  ";
p=p->adr;
}
cout<<endl;
}

void par()
{
p=prim3;
while(p)
{
if(p->info%2==0) cout<<p->info<<";  ";
p=p->adr;
}
cout<<endl;
}

void main()
{
cout<<"1. creez i lista liniara simplu inlantuita cu n noduri;"<<endl; creare1();
cout<<"2. creez a ii lista liniara simplu inlantuita cu n noduri;"<<endl; creare2();
cout<<"3. listez continutul i liste;"<<endl;  listare1();
cout<<"4. listez continutul celei de-a ii liste;"<<endl;  listare2();
cout<<"5. concatenez cele 2 liste introduse;"<<endl;  concatenare();
cout<<"6. listez continutul celei de-a iii liste;"<<endl;  listare3();
cout<<"7. afisez nr. pare din cea de-a iii lista;"<<endl;  par();
cout<<"8. afisez nr. impare din cea de-a iii lista;"<<endl;  impar();
getch();
}
