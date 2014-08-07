#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{char linie[100],nume[20];
cout<<"Introduceti numele fisierului!"<<endl<<"nume: ";	cin>>nume;
fstream f1(nume,ios::out);
while(!cin.eof())
	{while(cin.get(linie,100))
    	{f1<<linie<<endl;	cin.get();}
    f1<<endl;}
    f1.close();}