#include <iostream.h>
#include <conio.h>
void main()
{float a,b;
char c;
float e;
cout<<"a=";	cin>>a;
cout<<"b=";	cin>>b;
cout<<"c=";	cin>>c;
switch(c)
	{case '+':{e=a+b;	cout<<"E= "<<e;} break;
   case '-':{e=a-b;	cout<<"E= "<<e;} break;
   case '*':{e=a*b;	cout<<"E= "<<e;} break;
   case '/':{e=a/b;	cout<<"E= "<<e;} break;
   default: cout<<"Operator gresit";}
getch();}
