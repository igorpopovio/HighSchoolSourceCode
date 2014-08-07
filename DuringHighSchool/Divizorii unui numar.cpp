#include <iostream.h>
#include <conio.h>
void main()
{int n,i;
cout<<"Introduceti un numar (programul va afisa divizorii acestuia):"<<endl<<"n=";	cin>>n;
cout<<"Divizorii numarului "<<n<<" sunt:"<<"1 "<<n;
for(i=2;i<=n/2;i++)
	if(n%i==0)
   	cout<<" "<<i;
getch();}