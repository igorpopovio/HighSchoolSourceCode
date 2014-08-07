#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{int a,b,j=2,c,i,min,max;
fstream f1("maxdin.txt",ios::in);
f1>>a;	f1>>b;
for(i=2;i<a;i++)
	if(a%i==0) j++;
max=j;	min=a;	c=1;
for(a=min+1;a<b;a++)
	{j=2;
    for(i=2;i<a;i++)
    	if(a%i==0) j++;
    if(j>max) {max=j;	min=a;	c=1;}
    	else if(j==max) c++;}
fstream f2("maxdout.txt",ios::out);
f2<<resetiosflags(ios::skipws)<<min<<" "<<max<<" "<<c;
f1.close();	f2.close();}
