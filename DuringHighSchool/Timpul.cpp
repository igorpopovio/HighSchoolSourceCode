#include <iostream.h>
#include <conio.h>
void main()
{unsigned min,h;
cout<<"Introduceti timpul exprimat in minute (programul va afisa timpul exprimat in ore si minute):"<<endl<<"Nr.de minute=";	cin>>min;
clrscr();
h=min/60;	min=min%60;
cout<<"Timpul exprimat in ore si minute:"<<endl<<h<<" "<<"ore si "<<min<<" "<<"minute";
getch();}