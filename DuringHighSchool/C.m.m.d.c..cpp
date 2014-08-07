#include <iostream.h>
#include <conio.h>
void main ()
{int a,b,c,r,x,y,m;
cout<<"a=";	cin>>a;
cout<<"b=";	cin>>b;
x=a;	y=b;
if(b==0)
	c=a;
 else
 	{while(b)
   	{r=a%b;
      a=b;
      b=r;}
   c=a;}
if(c==0)
	cout<<"Nu se poate calcula; ambele sunt 0"<<'\a';
 else
 	if(x==0 || y==0)
   	cout<<"Nu se poate calcula c.m.m.m.c."<<endl<<"c.m.m.d.c.="<<c<<'\a';
    else
    	{m=x*y/c;
      cout<<"c.m.m.m.c.="<<m<<endl<<'\a';
      cout<<"c.m.m.d.c.="<<c<<'\a';}
getch ();}
