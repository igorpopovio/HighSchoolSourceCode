#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{int a,b,n2,p,c,n,i,j;
cout<<"a= ";	cin>>a;
cout<<"b= ";	cin>>b;
fstream f1("rotund.txt",ios::out);
for(;a<=b;a++)
	{c=a;	i=0;	j=0;	n2=0;	p=1;
    while(c)
    	{n2+=p*(c%2);
        c/=10;
        p*=10;}
    n=n2;
    while(n2)
    	{c=n2%10;
        n2/=10;
        if(c==0) i++;
        	else j++;}
    if(i==j)f1<<resetiosflags(ios::skipws)<<"Numarul "<<a<<" este rotund.Conversia in binar este "<<n<<"."<<endl;
         else f1<<resetiosflags(ios::skipws)<<"Numarul "<<a<<" nu este rotund.Conversia in binar este "<<n<<"."<<endl;}}
