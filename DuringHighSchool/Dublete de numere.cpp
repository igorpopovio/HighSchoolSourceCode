#include <iostream.h>
#include <conio.h>
void main()
{int c,d,i,j,r;
cout<<"r="; cin>>r;
for(i=1;i<=r;i++)
	{c=i*i;
   j=r-i;
   d=j*j;
   if(c+d==r*r) cout<<i<<" "<<j<<endl;}
getch();}