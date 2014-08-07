#include <iostream.h>
#include <conio.h>
void main()
{unsigned long n,i,j,s;
cout<<"n=";	cin>>n;
for(i=2;i<=n;i++)
	{for(j=2,s=1;j<=(i/2);j++)
   	if(i%j==0) s+=j;
   if(i==s) cout<<i<<" ";}
getch();}
