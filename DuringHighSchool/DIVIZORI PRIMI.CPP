#include <iostream.h>
#include <conio.h>
void main()
{int n,i;
cout<<"Introduceti un numar (programul va afisa divizorii primi ai acestuia):"<<endl<<"n=";	cin>>n;
i=2;
cout<<"Numarul introdus are divizorii primi:"<<endl;
while(n!=1)
	{if(n%i==0)
   	{cout<<i<<'\t';
      while(n%i==0)
      	n/=i;}
   i++;}
getch();}