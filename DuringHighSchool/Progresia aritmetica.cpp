#include <iostream.h>
#include <conio.h>
void main()
{unsigned long r,a,n,s,b;
cout<<"Introduceti primul termen si ratia unei progresii aritmetice si un numar natural(programul va afisa termenul al n-lea si suma primilor n termeni):"<<endl;
cout<<"primul termen=";	cin>>a;
cout<<"ratia=";	cin>>r;
cout<<"numar=";	cin>>n;
b=a+(n-1)*r;
s=(n*(2*a+(n-1)*r))/2;
cout<<"Al n-lea termen al acestei progresii aritmetice este: "<<b<<endl;
cout<<"Suma primilor n termeni ai acestei progresii aritmetice este: "<<s;
getch();}
