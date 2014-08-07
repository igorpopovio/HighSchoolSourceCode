#include <iostream.h>
#include <math.h>
#include <conio.h>
void main()
{float a,b,c,x1,x2,d;
cout<<"Introduceti coeficientii ecuatiei de gradul 2:"<<endl<<"a*x*x+b*x+c=0"<<endl<<endl;
cout<<"a=";	cin>>a;
cout<<"b=";	cin>>b;
cout<<"c=";	cin>>c;
if(a==0)
	{cout<<"Ecuatie de gradul intai";
   if(b==0)
   	{if(c==0)
      	cout<<"Ecuatia are o infinitate de solutii";
       else
       	cout<<"Ecuatia nu are solutii";}
     else
       {x1=-c/b;
       cout<<"Radacina x1="<<x1;}}
  else
  	 {d=b*b-4*a*c;
    if(d>0)
    	{x1=(-b+sqrt(d))/(2*a);
      x2=(-b-sqrt(d))/(2*a);
      cout<<"Ecuatia are doua radacini reale diferite:"<<endl<<"x1="<<x1<<endl<<"x2="<<x2;}
    else
    	{if(d==0)
      	{x1=-b/(2*a);
         cout<<"Ecuatia are doua radacini reale si egale"<<endl<<"x1=x2= "<<x1;}
       else
       	cout<<"Ecuatia nu are solutii reale";}
getch();}


