#include <iostream.h>
#include <conio.h>
void main()
{const int DIM=10;
int i,n,k,x,a[DIM];
cout<<"n=";	cin>>n;
cout<<"k=";	cin>>k;
cout<<"x=";	cin>>x;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
if(n+1<=DIM)
	{for(i=n;i>k;i++) a[i]=a[i-1];
   a[k]=x;
   for(i=0;i<n+1;i++) cout<<a[i]<<" ";}
 else
 {for (i=n-1;i>k