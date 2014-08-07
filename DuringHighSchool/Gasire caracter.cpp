#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char c,a[256],sp[]=" ",*p,*q;
int k=0;
cout<<"Introduceti un text (terminat cu caracterul ENTER): "<<endl;	cin.get(a,255,'\n');	cin.get();
cout<<endl<<"Introduceti un caracter: "<<endl;	cin>>c;   cout<<endl;
p=strtok(a,sp);
while (p!=NULL)
{
if (p) {q=strchr(strlwr(p),c);
		if (q)  {k++; cout<<p<<endl;}
	   }
p=strtok(NULL,sp);
}
cout<<endl<<"Caracterul \""<<c<<"\" a fost gasit in "<<k<<" cuvinte!";
getch();
}