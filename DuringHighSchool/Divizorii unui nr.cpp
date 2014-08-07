#include <iostream.h>
#include <conio.h>
void main()
{unsigned n,i;
highvideo();
textbackground(BLUE);
textcolor(LIGHTGREEN);
clrscr();
cout<<"Introduceti un numar (programul va afisa divizorii acestuia):"<<endl<<"n=";
cin>>n;
cout<<"Divizorii numarului "<<n<<" sunt:"<<"1 "<<n;
for(i=2;i<=n/2;i++)
	if(n%i==0)
   	cout<<" "<<i;
getch();}