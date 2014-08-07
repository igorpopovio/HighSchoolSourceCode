#include <iostream.h>
#include <fstream.h>
void main()
{int a[50],i,n,k=0,g=0,aux;
fstream f1("Fisier numere nesortate.txt",ios::in);
fstream f2("Fisier numere sortate crescator.txt",ios::out);
f1>>n;
while(!f1.eof())
	{a[k++]=n;f1>>n;}
while(!g)
	{g=1;
    for(i=0;i<(k-1);i++)
    	if(a[i]>a[i+1])	{aux=a[i];
    					a[i]=a[i+1];
                        a[i+1]=aux;	g=0;}}
for(i=0;i<k;i++)
	f2<<a[i]<<";     ";
f1.close();	f2.close();}

