#include <iostream.h>
#include <conio.h>
void main()
{int i,n,a[100];
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";
   cin>>a[i];}
for(i=n-1;i>=0;i--)
	cout<<a[i]<<" ";
getch();}