#include <iostream.h>
#include <conio.h>
void main()
{int a[50],b[50],c[50],i,n;
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
for(i=0;i<n;i++)
	{cout<<"b["<<(i+1)<<"]=";	cin>>b[i];}
for(i=0;i<n;i++)
	c[i]=((a[i]>=b[i])?a[i]:b[i]);
for(i=0;i<n;i++)
	cout<<"c["<<(i+1)<<"]="<<c[i]<<";"<<endl;
getch();}    