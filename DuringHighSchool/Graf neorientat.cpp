#include <iostream.h>
#include <conio.h>

int a[10][10],i,j,n;
void citire()
{
cout<<"n= ";  cin>>n;
for(i=0;i<n;i++)
for(j=0;j<n;i++)
{cout<<"muchia ("<<i<<","<<j<<")= ";  cin>>a[i][j];}
}
void muchie()
{
for(i=0;i<n;i++)
{
int s=0;
for(j=0;j<n;j++)
{if(a[i][j]) cout<<"("<<i<<","<<j<<")";   s++; }
cout<<"gradul nodului "<<i<<" este: "<<s/2;
}
}
void main()
{
citire(); muchie();
getch();
}