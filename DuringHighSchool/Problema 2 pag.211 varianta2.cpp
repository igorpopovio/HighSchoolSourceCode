#include <iostream.h>
#include <ctype.h>
#include <time.h>
int main()
{
	const int Max=10;
    double donatii[Max],s=0,m;
    int k=0,i=0;
    clock_t f=20*CLOCKS_PER_SEC;
    char c;
    int p=1,a=0,b=0;

	cout<<"Introduceti maximum 10 valori de donatii,in dolari:\n";
    while (i<Max)
    {
    	cout<<"Donatia "<<(i+1)<<": ";
        while (cin.get(c))
    {
    	if (!isdigit(c)||c=='.')	break;
        a=a*p+int(c-48);
        p*=10;
	}
    p=1;
    while (cin.get(c))
    {
        if (!isdigit(c))	break;
        b=b*p+int(c-48);
        p*=10;
    }

    donatii[i++]=a+double(b)/p;
    }
    for (i=0;i<Max;i++)
    	{s+=donatii[i];    cout<<donatii[i]<<"\n";}
    m=s/Max;
    for (i=0;i<Max;i++)
    	if (donatii[i]>m)	k++;
    cout<<"Media donatiilor este de "<<m<<" dolari. "<<k<<" donatii depasesc media!";
    clock_t start=clock();
    while (clock()-start<f);
    return 0;
}

