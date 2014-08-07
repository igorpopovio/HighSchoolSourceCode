#include <iostream.h>
#include <conio.h>

struct nod
{
int cifra;
nod *adr;
}*prim,*p,*q;

void creare()
{

int n;
cout<<"n= ";  cin>>n;
p=new nod;
cout<<"p->cifra= ";  cin>>p->cifra;
p->adr=NULL; prim=p;
for(int i=2;i<=n;i++)
{
q=new nod;
cout<<"p->cifra= ";  cin>>q->cifra;
p->adr=q;   q->adr=NULL;   p=q;
}
cout<<endl;
}


void calculare()
{
unsigned long numar=0;
p=prim;
while(p)
{
numar=numar*10 + p->cifra;
p=p->adr;
}
cout<<"numarul format din lista este: "<<numar;
}

void main()
{
cout<<"Se creeaza o lista liniara simplu inlantuita cu n noduri (1<=n<=6)\n"
    <<"ce memoreaza cifrele unui numar natural\n"
    <<"(programul afiseaza numarul format din cifrele memorate in lista)\n";
creare();
calculare();

getch();
}


