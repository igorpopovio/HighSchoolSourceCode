#include <iostream.h>
#include <conio.h>
void main()
{int i,n,k,a[10];
cout<<"n=";	cin>>n;
cout<<"k=";	cin>>k;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
for(i=k-1;i<n-1;i++) a[i]=a[i+1];
for(i=0;i<n-1;i++) cout<<a[i]<<" ";
getch();}

