#include <iostream.h>
#include <conio.h>
void main()
{long c,a,s=0,p=1,b,d,e;
cout<<"Introduceti codul de pe cartela de identificare:"<<endl<<"codul este: ";	cin>>c;
a=c;
while(a)
	{b=a%10;
    a/=10;
    if(b%2==0) p*=b;
    	else s+=b;}
d=p%b;	e=s%b;
if(d==e) cout<<"Cod acceptat! Acces permis.";
	else cout<<"Cod gresit! Acces interzis.";
getch();}