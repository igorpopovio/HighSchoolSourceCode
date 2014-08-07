#include <iostream.h>
#include <conio.h>
void main()
{unsigned a,b,c,d,n,e,i=0;
cout<<"Introduceti un numar natural, iar programul va afisa daca are forma abba:"<<endl;
cout<<"n=";	cin>>n;
e=n;
while(e)
	{e/=10;
   i++;}
if(i==4)
	{d=n%10;
   c=(n/10)%10;
   b=(n/100)%10;
   a=n/1000;
   if(a==d&&b==c) cout<<"Numarul indeplineste conditia";
   		else cout<<"Numarul nu indeplineste conditia";}
if(i!=4)
	cout<<"Introduceti un numar natural de 4 cifre!";
getch();}
