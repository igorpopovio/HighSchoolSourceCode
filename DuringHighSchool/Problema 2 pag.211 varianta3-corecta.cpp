#include <iostream.h>
#include <time.h>
int main()
{
    const Max=10;
	double donatii[Max],s=0,m;
    int i=0,k=0,j;
    clock_t f=20*CLOCKS_PER_SEC;

    cout<<"Introduceti va rog maxim 10 donatii <pentru incheiere tastati i>:\n";
    cout<<"Donatia 1: ";
	while (i<Max&&cin>>donatii[i])
    {
    	if (++i<Max) cout<<"Donatia "<<(i+1)<<": ";
    }
    for (j=0;j<i;j++)
    	s+=donatii[j];
    m=s/i;
    for (j=0;j<i;j++)
    	if (donatii[j]>m)	k++;
    cout<<"Media donatiilor este de "<<m<<" dolari. "<<k<<" donatii depasesc media!";
    clock_t start=clock();
    while (clock()-start<f);
    return 0;
}
