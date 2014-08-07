#include <iostream.h>
#include <stdlib.h>
#include <time.h>


void main()
{
unsigned long a,b,k=0,c,i;
cout<<"b= ";	cin>>b;
for(i=0;i<b;i++)
{
c=(unsigned long)(srand(time(400000))*100);
a=c%2;
if(a==0) k++;
}

cout<<"Frecventa de aparitie a banului: "<<float(k)/b<<"     "<<k;
}
