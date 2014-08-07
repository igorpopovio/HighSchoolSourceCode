#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
char a[256];
int b;
cout<<"Introduceti un cuvant: ";	cin.get(a,100,'\n');	cin.get();
b=atoi(a);
cout<<"Cuvantul introdus convertit la tipul intreg este: "<<b;
getch();
}