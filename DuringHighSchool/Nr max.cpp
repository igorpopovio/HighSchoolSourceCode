#include <iostream.h>
#include <conio.h>
void main()
{float a,max;
cout<<"Introduceti un sir de numere reale,apoi zero pentru a incheia executia programului (programul va afisa valoarea maxima introdusa):"<<endl<<"a=";	cin>>a;
max=a;
while(a)
	{if(a>max) max=a;
   cout<<"a=";	cin>>a;}
cout<<"Valoarea maxima introdusa este:"<<max;
getch();}