#include <iostream.h>
const int Lungime=66,Diviziuni=6;
void subinterval(char tab[],int jos,int sus,int nivel);
int main()
{
	char rigla[Lungime];
    int i;
    for (i=1;i<(Lungime-2);i++)
    	rigla[i]=' ';
    rigla[Lungime-1]='\0';
    int max=Lungime-2;
    int min=0;
    rigla[min]=rigla[max]='|';
    cout<<rigla<<"\n";
    for (i=1;i<=Diviziuni;i++)
    {
    	subinterval(rigla,min,max,i);
        cout<<rigla<<"\n";
        for (int j=1;j<(Lungime-2);j++)
        	rigla[j]=' ';
    }
    cin.get();
    return 0;
}
void subinterval(char tab[],int jos,int sus,int nivel)
{
	if (nivel==0)	return;
    int mijloc=(sus+jos)/2;
    tab[mijloc]='|';
    subinterval(tab,jos,mijloc,nivel-1);
    subinterval(tab,mijloc,sus,nivel-1);
}
