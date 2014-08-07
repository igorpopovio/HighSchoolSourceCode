#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdio.h>
void main()
{char ch,nume1[20],nume2[20],nume3[20];
cout<<"Numele primului fisier este: ";	cin>>nume1;
fstream f1(nume1,ios::in);
if(!f1)
	{cout<<"Fisierul "<<nume1<<" nu exista!";
    f1.close();}
  else
  	{cout<<"Numele celui de-al doilea fisier este ";	cin>>nume2;
    fstream f2(nume2,ios::out);
    while (f1>>resetiosflags(ios::skipws)>>ch)
    	f2<<resetiosflags(ios::skipws)<<ch;
f1.close();	f2.close();
remove(nume1);
cout<<"Noul nume al fisierului 2 este: ";	cin>>nume3;
rename(nume2,nume3);
fstream f3(nume3,ios::in);
while (f3>>resetiosflags(ios::skipws)>>ch) cout<<ch;
f3.close();}
getch();}

