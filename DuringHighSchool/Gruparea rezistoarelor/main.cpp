#include <iostream.h>
#include <conio.h>
#include "prototip.h"

void main()
{
char a;
int i=1;

do
{
cout<<"REZISTENTA ECHIVALENTA"<<endl;
cout<<"Alegeti pentru ce fel de grupare doriti sa calculati "
	<<"rezistenta echivalenta"<<endl;
cout<<"1. serie"<<endl
	<<"2. paralel"<<endl
    <<"3. triunghi-->stea"<<endl
    <<"4. stea-->triunghi"<<endl;

cout<<"Optiunea dumneavoastra: ";	cin>>a;
clrscr();
switch(a)
{
case '1': grup_serie(); break;
case '2': grup_paralel(); break;
case '3': grup_triunghi_stea(); break;
case '4': grup_stea_triunghi(); break;
default: break;
}
i++;     clrscr();
}
while(i<=10);
}
