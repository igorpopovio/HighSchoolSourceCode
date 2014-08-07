#include <iostream.h>
#include <conio.h>
void main()
{int i,n,a[100],b[100];
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++) {cout<<"a["<<(i+1)<<"]="; cin>>a[i];}
for(i=0;i<n;i++) b[i]=a[i];
for(i=0;i<n;i++) cout<<b[i]<<" ";
getch();}
