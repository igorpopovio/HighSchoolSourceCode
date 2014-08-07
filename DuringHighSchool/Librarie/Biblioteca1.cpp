#include <iostream.h>
#include <conio.h>
#include <string.h>

#define N 5

class carte
{
private:
char autor[20];
char nume[30];
public:
carte(const char * a="anonim",const char * c="nedenumita");
~carte();
void afiseaza();
};

void sortare(carte * a);
void citeste(carte * a);

void main()
{
carte biblioteca[N];
citeste(&biblioteca[0]);
sortare(bibilioteca);
for (int i=0;i<N;i++)
biblioteca.afiseaza();
getch();

}

carte::carte(const char * a,const char * c)
{
strcpy(autor,a);
strcpy(nume,c);
}

carte::~carte()
{
}

carte::afiseaza()
{
cout<<endl;
cout<<"Nume carte: "<<nume<<endl;
cout<<"Autor: "<<autor;
}

void sortare(carte * a)
{
carte aux;
int g=0;

while(!g)
{
g=1;
for (int i=0;i<(N-1);i++)
{
if (strcmp(a[i].autor,a[i+1].autor))>0)
{
aux=a[i];
a[i]=a[i+1];
a[i+1]=aux;
g=1;
}
}
}
}

void citeste(carte * a)
{
for (int i=0;i<N;i++)
{
cout<<(i+1)<<": nume - ";	cin>>nume;
cout<<" : autor - ";	cin>>autor;
}
