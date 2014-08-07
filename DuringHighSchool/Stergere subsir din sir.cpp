#include <iostream.h>
#include <conio.h>
#include <string.h>
void main()
{
char sir[256],sb[11],*p;
cout<<"Sirul in care se sterge: "<<endl;	cin.get(sir,255);	cin.get();
cout<<"Subsirul care se sterge: "<<endl;	cin.get(sb,10);     cin.get();
p=strstr(sir,sb);
if (p) strcpy(p,p+strlen(sb));
cout<<endl<<sir;
getch();
}