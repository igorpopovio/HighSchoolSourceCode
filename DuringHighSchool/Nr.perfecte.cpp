#include <iostream.h>
#include <conio.h>
#include <math.h>
void main()
{unsigned n,i,j,s;
cout<<"n=";	cin>>n;
for(i=2;i<=n;i++)
	{for(j=2,s=1;j<=sqrt(i);j++)  
   	if(i%j==0)
      	s+=j;
   if(i==s)
   	 cout<<i;}
getch();}
