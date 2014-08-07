#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char cuv1[21],cuv2[21],p[21],q[21];
int i,j,k=0,l=0,g=1;

cout<<"Primul cuvant: "<<endl;	cin.get(cuv1,20);	cin.get();
cout<<"Al doilea cuvant: "<<endl;	cin.get(cuv2,20);	cin.get();
for (i=0;i<strlen(cuv1) && i<strlen(cuv2) && g;i++)
if (cuv1[i]==cuv2[i]) k++;
	else g=0;
strncpy(p,cuv1,k);
p[k]=NULL;
for (i=strlen(cuv1),j=strlen(cuv2),g=1;i>=0 && j>=0 && g;i--,j--)
if (cuv1[i]==cuv2[i]) l++;
	else g=0;
strcpy(q,cuv2+strlen(cuv2)-l);
if (k) cout<<endl<<"Cele doua cuvinte au acelasi prefix: "<<p<<"-"<<endl;
if (l) cout<<"Cele doua cuvinte au acelasi sufix: -"<<q;
getch();
}

