#include <iostream.h>
#include <conio.h>
void main()
{char c;
cout<<"Introduceti un caracter:"<<endl<<"c=";	cin>>c;
cout<<(c>='a'&&c<='z'?"Litera mica":(c>='A'&&c<='Z'?"Litera mare":"Nu este litera"));
getch();}