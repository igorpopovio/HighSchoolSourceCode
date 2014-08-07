#include <iostream.h>
#include <conio.h>
void main()
{int i,j=0,k=0,n,a[100],b[100],c[100],d,e;
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++) {cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
for(i=0;i<n;i++)
	if(a[i]%2==0) {b[j]=a[i];	j++;}
   			else {c[k]=a[i];	k++;}
d=j;	e=k;
if(j)
	{cout<<"Numerele pare sunt:"<<endl;
   for(i=0,j=0;i<d;i++,j++) cout<<b[j]<<endl;}
 else cout<<"Nu exista numere pare!"<<endl;
if(k)
	{cout<<"Numerele impare sunt:"<<endl;
   for(i=0,k=0;i<e;i++,k++) cout<<c[k]<<endl;}
 else cout<<"Nu exista numere impare!"<<endl;
getch();}
