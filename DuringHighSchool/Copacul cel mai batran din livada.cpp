#include <iostream.h>
#include <conio.h>
void main()
{int a[100][100],n,m,i,j,max,g,h;
cout<<"Numarul de randuri ale livezii este: ";	cin>>n;
cout<<"Numarul de coloane ale livezii este: ";	cin>>m;
clrscr();
cout<<"Introduceti varsta fiecarui copac in parte!"<<endl;
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
    	{cout<<"Copacul de pe randul "<<(i+1)<<", coloana "<<(j+1)<<" are varsta de: ";	cin>>a[i][j];}
max=a[0][0];  g=0;	h=0;
for(i=1;i<n;i++)
	for(j=1;j<m;j++)
    	if(max<a[i][j])
        	{max=a[i][j];	g=i;	h=j;}
cout<<"Copacul cel mai batran este situat pe randul "<<(g+1)<<", coloana "<<(h+1);
getch();}
