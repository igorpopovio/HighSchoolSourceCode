#include <iostream.h>
#include <conio.h>
void main()
{unsigned n,nr,inv;
cout<<"Introduceti un numar natural(programul va verifica daca numarul introdus este palindrom, adica daca este citit de la stanga la dreapta si de la dreapta la stanga, are aceeasi valoare):"<<endl<<"n=";	cin>>n;
clrscr();
nr=n;	inv=0;
while(n)
	{inv=inv*10 +n%10;	n/=10;}
if(nr==inv)
	cout<<"Numarul este palindrom";
 else
 	cout<<"Numarul nu este palindrom";
getch();}