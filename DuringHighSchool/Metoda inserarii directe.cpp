#include <iostream.h>
#include <conio.h>
void main()
{int i,j,n,aux,a[50],z;
cout<<"n=";	cin>>n;
for(i=0;i<n;i++) {cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
for(i=1;i<n;i++)
	{aux=a[i];	j=i-1;
    while (j>0 && aux<a[j])	{a[j+1]=a[j]; j--;}
    if(aux>=a[j])	a[j+1]=aux;
    	else {a[1]=a[0];	a[0]=aux;}
    for(z=0;z<n;z++) cout<<a[z]<<" ";}
getch();}