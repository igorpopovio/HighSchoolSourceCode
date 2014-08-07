#include <iostream.h>
#include <conio.h>
void main()
{int i,n,s=0,k=0,a[20];
cout<<"n= ";	cin>>n;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";
   cin>>a[i];}
for(i=0;i<n;i++)
	if(a[i]>0) {s+=a[i]; k++;}
if(k>0) cout<<"media= "<<(float)s/k;
getch();}