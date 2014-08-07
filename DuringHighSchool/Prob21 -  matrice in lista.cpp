#include <conio.h>
#include <iostream.h>
struct nod
{
int info;
nod *adr;
}*p,*q;
int a[50][50],i,j,n,m;
nod * liste[50];

void creare()
{
for(i=0;i<n;i++)
{
p=new nod;  p->info=a[i][0];
p->adr=NULL; liste[i]=p;
for(j=1;j<m;j++)
{
q=new nod;
q->info=a[i][j];
p->adr=q;   q->adr=NULL;   p=q;
}
}
cout<<endl;
}

void listare(nod * prim)
{
p=prim;
while(p){cout<<"p->info= "<<p->info<<"  ";  p=p->adr;}
cout<<endl<<endl;
}

void main()
{
cout<<"Introduceti o matrice cu n linii si m coloane"<<endl;
cout<<"n= ";  cin>>n;
cout<<"m= ";  cin>>m;
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{
cout<<"a["<<i<<"]["<<j<<"]= ";  cin>>a[i][j];
}
cout<<"1. Se creeaza n liste din matricea introdusa;";  creare();
cout<<"2. Se afiseaza cele n liste;";
for(i=0;i<n;i++) {cout<<endl<<"lista de pe linia "<<i<<": ";  listare(liste[i]);}

getch();
}