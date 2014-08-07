#include <iostream.h>
#include <conio.h>
#include <fstream.h>
void main()
{char ch, nume[20];
cout<<"Numele fisierului este: ";	cin>>nume;
fstream f(nume,ios::out);
while(cin>>ch) f<<ch;
f.close();
getch();}