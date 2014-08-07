#include <iostream.h>
#include <conio.h>
#include <fstream.h>
struct biblioteca
{
	char nume_carte[20],nume_autor[20];
    unsigned nr_carti;
};
void main()
biblioteca teora[5];
fstream f ("biblioteca.txt",ios::in);
int i,n=5;
for(i=0;i<5;i++)
{f.get(teora[i].nume_carte,20);	f.get();
f.get(teora[i].nume_autor,20);	f.get();
f>>teora[i].nr_carti;}
f.close();
for (i=0;i<n;i++)
{cout<<teora[i].nume_carte<<"  "<<teora[i].nume_autor<<"  "<<teora[i].nr_carti<<endl;}
getch();}
