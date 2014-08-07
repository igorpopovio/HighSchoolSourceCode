#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <conio.h>
void main()
{int i;
fstream f1("Codul ASCII.txt",ios::out);
for(i=0;i<=300;i++)
	f1<<resetiosflags(ios::skipws)<<i<<"...................."<<(char)i<<endl;
f1.close();
cout<<"Fisierul \"Codul ASCII\" se gaseste in directorul curent!";
getch();}