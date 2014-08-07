#include <iostream.h>
#include <conio.h>
void main()
{long double i,n,c;
cout<<"Introduceti un numar \"n\" (programul va afisa toate cuburile perfecte mai mici sau egale cu n)"<<endl<<"n=";	cin>>n;
for(i=1;i<=n;i++)
	{c=i*i*i;
   if(c<=n) cout<<c<<" ";}
getch();}
