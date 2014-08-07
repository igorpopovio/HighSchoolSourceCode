#include <iostream.h>
#include <conio.h>
void main()
{int n,i,s=0,terminat=1,j=1,a;
cout<<"n=";	cin>>n;
for(i=0;i<n;i++)
	{cout<<"a"<<(i+1)<<"= ";	cin>>a;
   while(terminat!=0)
		{j++;
      	if(a%j==0) terminat=0;}
   s+=j;	j=1;}
cout<<"Suma obtinuta adunand primul divizor prim din fiecare numar citit este: "<<s;
getch();}

