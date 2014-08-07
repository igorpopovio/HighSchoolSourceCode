#include <iostream.h>
#include <conio.h>
void main()
{int a[50],s,n,i,m,j=0;
cout<<"n=";	cin>>n;
for(i=0,s=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];
   s+=a[i];}
m=(float)s/n;
for(i=0;i<n;i++)
	{if(a[i]>m)
   	{cout<<a[i]<<" ";
      j++;}}
cout<<endl<<"S-au gasit "<<j<<" elemente!";
getch();}
