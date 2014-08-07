#include <iostream.h>
#include <conio.h>
void main()
{int i,n,x,st,dr,mijl,gasit,a[10];
cout<<"n=";	cin>>n;
cout<<"x=";	cin>>x;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
st=0; dr=n-1; gasit=0;
while(st<=dr&&!gasit)
	{mijl=(st+dr)/2;
   if(a[mijl]==x)	gasit=1;
   	else
      	if(x<a[mijl]) dr=mijl-1;
         	else st=mijl+1;}
if(st>dr) cout<<"Nu s-a gasit elementul!";
	else cout<<"S-a gasit elementul in pozitia "<<(mijl+1);
getch();}
