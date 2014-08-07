#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char a[256],*p,sp[]=" ",b[256]={'\0'};
int k=0;
cout<<"Introduceti o propozitie, apoi apasati tasta ENTER!"<<endl;
cin.get(a,100,'\n');	cin.get();   cout<<endl;
p=strtok(a,sp);
while (p!=NULL)
{
	if (p) {cout<<p<<endl; k++; strcat(b,p); strcat(b,sp);}
    p=strtok(NULL,sp);
}
cout<<endl<<"Textul are "<<k<<" cuvinte."<<endl;
cout<<"Textul introdus fara spatii suplimentare:"<<endl;
if (b) cout<<b<<" ";
getch();
}