#include <iostream.h>
#include <conio.h>
#include <string.h>
void main()
{
	char sir[50][25],aux[25];
    int n,i,j;
    
    textbackground(BLUE);
    textcolor(GREEN);
    clrscr();

    cout<<"Numarul de cuvinte= ";	cin>>n;   	cin.get();
    for (i=0;i<n;i++)
    { cout<<"cuvantul : ";	cin.get(sir[i],25);		cin.get();}
    for (i=0;i<(n-1);i++)
    for (j=i+1;j<n;j++)
    if (strcmp(sir[i],sir[j])>0)
    	{strcpy(aux,sir[i]); strcpy(sir[i],sir[j]);	strcpy(sir[j],aux);}
    for (i=0;i<n;i++)
    	cout<<sir[i]<<endl;
    getch();
    }
