#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{char ch, nume[20];
cout<<"Numele fisierului este: ";	cin>>nume;
fstream f(nume,ios::in);
while (f>>resetiosflags(ios::skipws)>>ch) cout<<resetiosflags(ios::skipws)<<ch;
f.close();
getch();}