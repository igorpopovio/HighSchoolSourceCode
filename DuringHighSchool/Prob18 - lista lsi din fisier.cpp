#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream.h>

struct nod
{
int cifra;
nod * adr;
}*p,*q,*prim;

void creare()
{
char a[2];
fstream fis("cifre.in",ios::in);
fis.get(a,2);   p=new nod;  p->cifra=atoi(a); p->adr=NULL;
prim=p;
while(fis.get(a,2) && !fis.eof())
{
q=new nod;  q->cifra=atoi(a); q->adr=NULL;  p->adr=q;   p=q;
}
fis.close();
}

void afisare()
{
p=prim;
while(p){ cout<<"p->cifra= "<<p->cifra<<endl;   p=p->adr;}
}

void main()
{
creare();   afisare();

getch();
}


