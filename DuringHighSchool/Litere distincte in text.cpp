#include <iostream.h>
#include <conio.h>
#include <string.h>
void main()
{
char text[256];
int v[52]={0},i,k=0;

cout<<"Introduceti textul: "<<endl;	cin.get(text,255);	cin.get();
for (i=0;i<strlen(text);i++) {v[(text[i]-65)]++;	k++;}
cout<<"In textul introdus se gasesc "<<k<<" litere distincte;";
for (i=0;i<52;i++)
if (v[i])
	cout<<endl<<"Litera "<<(char)(65+i)<<" apare de "<<v[i]<<" ori.";
getch();
}