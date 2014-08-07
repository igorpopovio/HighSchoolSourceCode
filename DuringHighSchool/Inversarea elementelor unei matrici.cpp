#include <iostream.h>
#include <conio.h>
void main()
{int n,m,i,j,x,a[10][10];
cout<<"n= ";	cin>>n;
cout<<"m= ";	cin>>m;
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
   	{cout<<"a["<<(i+1)<<","<<(j+1)<<"]= ";	cin>>a[i][j];}
for(i=0;i<n;i++)
	for(j=0;j<m/2;j++)
   	{x=a[i][j];	a[i][j]=a[i][m-j-1];	a[i][m-j-1]=x;}
for(i=0;i<n;i++)
	{for(j=0;j<m;j++) cout<<a[i][j]<<" ";
   cout<<endl;}
getch();}