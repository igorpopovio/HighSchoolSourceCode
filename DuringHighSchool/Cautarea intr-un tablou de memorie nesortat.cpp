#include <iostream.h>
#include <conio.h>
void main()
{int i,n,x,a[100];
cout<<"n=";	cin>>n;
cout<<"x=";	cin>>x;
for(i=0;i<n;i++)
	{cout<<"a["<<(i+1)<<"]=";	cin>>a[i];}
i=0;
while(i<n&&a[i]!=x)i++;
if(i!=n) cout<<"S-a gasit elementul in pozitia "<<(i+1);
	else cout<<"Nu s-a gasit elementul!";
getch();}