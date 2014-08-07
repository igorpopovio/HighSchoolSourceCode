#include <iostream.h>
#include <math.h>
#include <conio.h>
void main()
{float terminat=1,a,c,n,i,b,d;
cout<<"n=";	cin>>n;
for(i=n;terminat!=0;i++)
	{a=sqrt(i);
   b=(int)a;
   if(a==b) terminat=0;}
terminat=1;
for(i=n;terminat!=0;i--)
	{c=sqrt(i);
   d=(int)c;
   if(c==d) terminat=0;}
cout<<"Cele mai apropiate patrate perfecte sunt: "<<c*c<<" si "<<a*a;
getch();}
