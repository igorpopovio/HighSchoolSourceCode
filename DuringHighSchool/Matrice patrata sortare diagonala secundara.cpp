#include <iostream.h>
#include <conio.h>
void main()
{int a[50][50],i,n,j,aux,g=1;
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
    	{cout<<"a["<<(i+1)<<"]["<<(j+1)<<"]=";	cin>>a[i][j];}
while(g)
	{g=0;	i=0;	j=n-1;
    for(i=0;i<(n-1);i++)
    	if(a[i][j-i]>a[i+1][j-i-1])
        	{aux=a[i][j-i];
             a[i][j-i]=a[i+1][j-i-1];
             a[i+1][j-i-1]=aux;
             g=1;}}
for(i=0;i<n;i++)
	{cout<<endl;
    for(j=0;j<n;j++)
    	cout<<a[i][j]<<"   ";}
getch();}












































































































































































































































