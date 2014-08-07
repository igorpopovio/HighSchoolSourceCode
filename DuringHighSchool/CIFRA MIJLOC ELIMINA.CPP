#include <iostream.h>
#include <conio.h>
void main()
{unsigned long n,nr,j,a,b,c,d,e,p,i;
cout<<"Introduceti un numar natural (programul va afisa numarul obtinut prin eliminarea cifrei din mijloc, daca n are nr. impar de cifre, respectiv a celor doua cifre din mijloc, daca n are nr. par de cifre):"<<endl<<"n=";	cin>>n;
clrscr();
j=n;	p=1;	d=0;	e=0;	a=0;
while(n)
	{n/=10;
   a+=1;}
b=a/2;
if(a%2)
	{for(i=1;i<=b;i++)
   	{c=j%10;
      j/=10;
      d=d+c*p;
      p*=10;}
   j/=10;	p=1;
   for(i=1;i<=b;i++)
   	{c=j%10;
      j/=10;
      e=e+c*p;
      p*=10;}}
  else
    {for(i=1,p=1;i<b;i++)
    	{c=j%10;
      j/=10;
      d=d+c*p;
      p*=10;}
    j/=100;	p=1;
    for(i=1;i<b;i++)
    	{c=j%10;
      j/=10;
      e=e+c*p;
      p*=10;}}
nr=e*p+d;
cout<<"Noul numar este "<<nr;
getch();}

