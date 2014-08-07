#include <iostream.h>
#include <conio.h>
void main()
{float a[100],aux,min;
int i,n,k=0,p;
cout<<"n= ";	cin>>n;
for (i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
while(k<n)
	{min=a[k];	p=k;
    for(i=k;i<n;i++)
    	if(min>a[i]){min=a[i];	p=i;}
    aux=a[k];
    a[k]=a[p];
    a[p]=aux;	k++;}
cout<<"Vectorul este sortat crescator dupa cum urmeaza:"<<endl;
for(i=0;i<n;i++)
	cout<<"a["<<(i+1)<<"]="<<a[i]<<endl;
getch();}
