#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include "agenda.h"

extern char nume[20];
extern agenda ag[100];

char meniu(void)
{
char op;
clrscr();
cout<<"1. creare - agenda"<<endl
	<<"2. deschide - agenda"<<endl
    <<"3. adauga in agenda"<<endl
    <<"4. sterge din agenda"<<endl
    <<"5. inchide programul"<<endl;
cout<<"Optiunea dumneavoastra:     ";		cin>>op;
return op;
}

void deschide(void)
{
char ch;
int i,n;
fstream f("Agenda.txt",ios::in);
clrscr();
while(!f.eof())
{
f>>ch;      cout<<ch;
}
f.close();
cout<<"\nNume agenda:    ";		cin.get(nume,19,'\n');
fstream f1(nume,ios::in);
clrscr();
cout<<"Agenda:    "<<nume<<endl;
f1>>n;
for (i=0;i<n;i++)
{
f1>>ag[i].nume;
f1>>ag[i].prenume;
f1>>ag[i].telefon;
}
f1.close();
for (i=0;i<n;i++)
cout<<ag[i].nume<<"    "<<ag[i].prenume<<"    "<<ag[i].telefon<<endl;
cout<<"Apasati o tasta pentru a continua ... ";		cin.get();
}

void creare(void)
{
fstream f2("Agenda.txt",ios::app);
cout<<"Nume - agenda:    ";		cin.get(nume,19,'\n');
f2<<nume<<'\n';
f2.close();
fstream f3(nume,ios::app);
f3<<"0"<<'\n';
f3.close();
}

void adauga(void)
{
char ch;
clrscr();
fstream f4("Agenda.txt",ios::in);
while(!f4.eof())
{
f4>>ch;		cout<<ch;
}
f4.close();
cout<<"Agenda in care doriti sa adaugati:   ";		cin.get(nume,19,'\n');
citeste();
}

void citeste(void)
{
int i,n,g=0;
agenda aux;
fstream f5(nume,ios::in);
f5>>n;
for (i=0;i<n;i++)
{
f5>>ag[i].nume;
f5>>ag[i].prenume;
f5>>ag[i].telefon;
}
f5.close();
for (i=0;i<n;i++)
cout<<ag[i].nume<<"    "<<ag[i].prenume<<"    "<<ag[i].telefon<<endl;
cout<<"Apasati orice tasta pentru a adauga ...";	cin.get();
clrscr();
cout<<"Nume: ";		cin>>ag[n].nume;
cout<<"Prenume: ";	cin>>ag[n].prenume;
cout<<"Telefon: ";	cin>>ag[n].telefon;
n++;
while (!g)
{
g=1;
for (i=0;i<(n-1);i++)
if (strcmp(ag[i].nume,ag[i+1].nume)>0)	{aux=ag[i];
										 ag[i]=ag[i+1];
                                         ag[i+1]=aux;
                                         g=0;}
}
fstream f6(nume,ios::out);
f6<<n<<endl;
for (i=0;i<n;i++)
{
f6<<ag[i].nume<<"    "<<ag[i].prenume<<"    "<<ag[i].telefon<<endl;
}
f6.close();
}

void sterge(void)
{
char ch,pers[20];
int i,n,g=0,p;
agenda aux;
clrscr();
fstream f7("Agenda.txt",ios::in);
while(!f7.eof())
{
f7>>ch;		cout<<ch;
}
cout<<"Agenda din care doriti sa stergeti:   ";		cin.get(nume,19,'\n');
f7.close();
fstream f8(nume,ios::in);
f8>>n;
for (i=0;i<n;i++)
{
f8>>ag[i].nume;
f8>>ag[i].prenume;
f8>>ag[i].telefon;
}
f8.close();
for (i=0;i<n;i++)
cout<<ag[i].nume<<"    "<<ag[i].prenume<<"    "<<ag[i].telefon<<endl;
cout<<"Apasati orice tasta pentru a sterge ...";	cin.get();
clrscr();
cout<<"Introduceti numele persoanei pe care doriti sa o stergeti din agenda "<<nume<<":\n";
cout<<"Nume: ";		cin.get(pers,19,'\n');
for (i=0;i<n;i++)
if (!strcmp(ag[i].nume,pers))	p=i;
for (i=p;i<(n-1);i++)
ag[i]=ag[i+1];
n=n-1;
while (!g)
{
g=1;
for (i=0;i<(n-1);i++)
if (strcmp(ag[i].nume,ag[i+1].nume)>0)	{aux=ag[i];
										 ag[i]=ag[i+1];
                                         ag[i+1]=aux;
                                         g=0;}
}
fstream f9(nume,ios::out);
f9<<n<<endl;
for (i=0;i<n;i++)
{
f9<<ag[i].nume<<"    "<<ag[i].prenume<<"    "<<ag[i].telefon<<endl;
}
f9.close();
}

