#include <iostream.h>
#include <ctype.h>
#include <math.h>
int main()
{
	const int Max=10;
    double donatii[Max],s=0,m,e;
    int i=1,k=0,j,p=1,b=0,d=0,v=0;
    char c;

    cout<<"Introduceti maximum 10 valori de donatii,in dolari:\n";
    cout<<"Donatia 1: ";	cin.get(c);
    while (i<Max&&isdigit(c))
    {
    while (isdigit(c)||c==','||c=='.')
    {
    	if (isdigit(c))
        {
        	b=b*p+c;	p*=10;	cin.get(c);
        }
        else
        {
        	cin.clear();	break;
        }
    }
    cin.get(c);    p=1;
    while (isdigit(c))
    {
    	d=d*p+c;	p*=10;		v++;	cin.get(c);
    }
    e=b+d/pow10(v);		donatii[i++]=e;		s+=e;
    }
    m=s/i;
    for(j=0;j<i;j++)
    	if (donatii[j]>m)  k++;
    cout<<"Media donatiilor este de "<<m<<" dolari. "<<k<<" donatii depasesc media!";
    cin.get();
    cin.get();
    return 0;
}