#include <iostream.h>
#include <conio.h>
void main()
{unsigned a,l;
cout<<"Introduceti anul si luna, iar programul va afisa numarul de zile din luna respectiva:"<<endl;
cout<<"anul=";	cin>>a;
cout<<"luna=";	cin>>l;
if(a%4==0)
	{if(l==2)
   	cout<<"29 de zile";
    else
    	cout<<"28 de zile";}
  else
  	 {if(l==7||l==8)
    	cout<<"31 de zile";
    else
    	{if(l%2)
      	cout<<"31 de zile";
       else
       	cout<<"30 de zile";}}
getch();}
