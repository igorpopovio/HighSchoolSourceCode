#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{long int a,b,i,g;
cout<<"Introduceti intervalul [a,b]. Programul va afisa toate numerele prime din acest interval in fisierul \"Numere prime.txt\""<<endl;
cout<<"a= ";	cin>>a;
cout<<"b= ";	cin>>b;
fstream f("Numere prime.txt",ios::out);
f<<resetiosflags(ios::skipws)<<"Numerele prime din intervalul ["<<a<<","<<b<<"] sunt:"<<endl;
for(;a<=b;a++)
	{g=1;
	for(i=2;i<=(a-1);i++)
    	if(a%i==0) g=0;
    if(g==1) f<<resetiosflags(ios::skipws)<<a<<";"<<'\t';}
f.close();}
