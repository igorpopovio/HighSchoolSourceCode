#include <iostream.h>
#include <conio.h>
void main()
{int a,b,c,max;
cout<<"a=";	cin>>a;
cout<<"b=";	cin>>b;
cout<<"c=";	cin>>c;
clrscr();
max=a;
max=max<b?b:max;
max=max<c?c:max;
cout<<"Valoarea maxima introdusa este "<<max;
getch();}