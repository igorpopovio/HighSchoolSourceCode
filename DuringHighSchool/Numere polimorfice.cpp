#include <iostream.h>
#include <conio.h>
void main()
{int n,k=0,a,b,p=1,c=0,i,v,d;
cout<<"n= "; cin>>n;
a=n;
while(n)
   {n/=10;	k++;}
d=b=a*a;
for(i=0;i<k;i++)
	{v=b%10; 	b/=10;
    c+=v*p;		p*=10;}
if(a==c) cout<<"Numarul "<<a<<" este polimorfic, patratul sau este "<<d;
	else cout<<"Numarul "<<a<<" nu este polimorfic, patratul sau este "<<d;
getch();}
