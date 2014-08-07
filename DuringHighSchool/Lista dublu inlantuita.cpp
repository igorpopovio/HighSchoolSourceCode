#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod *st,*dr;
}*p,*q,*prim,*ultim;
int i,n,k;

void creare()
{
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->info= ";  cin>>p->info;
p->st=p->dr=NULL; prim=ultim=p;
for(i=2;i<=n;i++)
{
q=new nod;
cout<<"p->info= ";  cin>>q->info;
p->dr=q;  q->st=p;
q->dr=NULL;   p=q;
}
ultim=p;
cout<<endl;
}

void list_st_dr()
{
p=prim;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->dr;}
cout<<endl;
}

void list_dr_st()
{
p=ultim;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->st;}
cout<<endl;
}

void adaugare()
{
cout<<"k= ";  cin>>k;   nod *r;
if(k==1)
{
p=new nod;  cout<<"p->info= ";  cin>>p->info;
prim->st=p; p->dr=prim;   p->st=NULL;   prim=p;
}
else if(k==n)
{
p=new nod;  cout<<"p->info= ";  cin>>p->info;
ultim->dr=p;  p->st=ultim;  p->dr=NULL; ultim=p;
}
else
{
p=prim;
for(i=1;i<(k-1);i++) p=p->dr;
q=new nod;  cout<<"p->info= ";  cin>>q->info;
r=p->dr;  p->dr=q;  q->st=p;
q->dr=r;  r->st=q;
}
cout<<endl;  n++;
}

void stergere()
{
cout<<"k= ";  cin>>k; nod *r,*s;
if(k==1)
{
p=prim; prim=p->dr; prim->st=NULL;  delete p;
}
else if(k==n)
{
p=ultim;  ultim=p->st;  ultim->dr=NULL; delete p;
}
else
{
p=prim; for(i=1;i<k;i++) p=p->dr;
r=p->st;  s=p->dr;
r->dr=s;  s->st=r;  delete p;
}
cout<<endl; n--;
}

void main()
{
cout<<"1. creez o lista liniara dublu inlantuita cu n noduri;"<<endl; creare();
cout<<"2. listez de la stanga la dreapta;"<<endl;  list_st_dr();
cout<<"3. listez de la dreapta la stanga;"<<endl;  list_dr_st();
cout<<"4. adaugam un nod pe pozitia k;"<<endl;     adaugare();
cout<<"5. listez de la stanga la dreapta;"<<endl;  list_st_dr();
cout<<"6. stergem un nod de pe pozitia k;"<<endl;  stergere();
cout<<"7. listez de la stanga la dreapta;"<<endl;  list_st_dr();
getch();
}
