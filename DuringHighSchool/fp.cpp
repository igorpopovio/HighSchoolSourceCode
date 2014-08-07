#include <iostream.h>
#include <conio.h>
#include "fs.cpp"
extern int prim(unsigned);
void main()
{unsigned n;
cout<<"n= "; cin>>n;
if (prim(n)) cout<<"Numarul "<<n<<" este prim!";
	else  cout<<"Numarul "<<n<<" nu este prim!";
getch();}