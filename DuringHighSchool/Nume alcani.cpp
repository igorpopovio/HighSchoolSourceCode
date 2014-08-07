#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char nume[50]={'\0'};
int n,a,b;

clrscr();
cout<<"Introduceti numarul de atomi de carbon din molecula alcanului: ";
while (cin>>n)
{b=n;  if (b>99) exit(1);
if (n>=1 && n<=19)
{
switch (n)
{
case 1: strcat(nume,"metan"); break;
case 2: strcat(nume,"etan"); break;
case 3: strcat(nume,"propan"); break;
case 4: strcat(nume,"butan"); break;
case 5: strcat(nume,"pentan"); break;
case 6: strcat(nume,"hexan"); break;
case 7: strcat(nume,"heptan"); break;
case 8: strcat(nume,"octan"); break;
case 9: strcat(nume,"nonan"); break;
case 10: strcat(nume,"decan"); break;
case 11: strcat(nume,"undecan"); break;
case 12: strcat(nume,"dodecan"); break;
case 13: strcat(nume,"tridecan"); break;
case 14: strcat(nume,"tetradecan"); break;
case 15: strcat(nume,"pentadecan"); break;
case 16: strcat(nume,"hexadecan"); break;
case 17: strcat(nume,"heptadecan"); break;
case 18: strcat(nume,"octodecan"); break;
case 19: strcat(nume,"nonadecan"); break;
}
}
if (n>=20 && n<=29)
{
a=n%10;
switch (a)
{
case 0: break;
case 1: strcat(nume,"henei"); break;
case 2: strcat(nume,"do"); break;
case 3: strcat(nume,"tria"); break;
case 4: strcat(nume,"tetra"); break;
case 5: strcat(nume,"penta"); break;
case 6: strcat(nume,"hexa"); break;
case 7: strcat(nume,"hepta"); break;
case 8: strcat(nume,"octo"); break;
case 9: strcat(nume,"nona"); break;
}
strcat(nume,"cosan");
}
if (n>29 && n<=99)
{
while (n)
{
a=n%10;		n/=10;
switch (a)
{
case 0: break;
case 1: strcat(nume,"henei"); break;
case 2: strcat(nume,"do"); break;
case 3: strcat(nume,"tria"); break;
case 4: strcat(nume,"tetra"); break;
case 5: strcat(nume,"penta"); break;
case 6: strcat(nume,"hexa"); break;
case 7: strcat(nume,"hepta"); break;
case 8: strcat(nume,"octo"); break;
case 9: strcat(nume,"nona"); break;
}
}
if (b<30) strcat(nume,"cosan");
   else strcat(nume,"contan");
}
clrscr();
cout<<"Numele alcanului cu "<<b<<" atomi de carbon in molecula este "<<nume;
cout<<endl<<"\n\nDaca doriti incheierea programului introduceti o valoare nenumerica\nsau o valoare mai mare de 99,\naltfel introduceti numarul de atomi de carbon din molecula alcanului: ";
nume[0]='\0';
}
}
