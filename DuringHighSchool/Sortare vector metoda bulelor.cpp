#include <iostream.h>
#include <conio.h>
void main()
{int n,i,t=0;
float a[100],aux;
cout<<"n=";	cin>>n;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
while(!t)
	{t=1;
    for(i=0;i<(n-1);i++)
    	if(a[i]>a[i+1])
        	{aux=a[i];	a[i]=a[i+1];	a[i+1]=aux;	t=0;}}
for(i=0;i<n;i++)
	cout<<"a["<<(i+1)<<"]="<<a[i]<<'\t';
getch();}

