#include <iostream.h>
#include "strng2.h"
const DimTablou=10;
const LungMax=81;
int main()
{
	Sir nume;
    cout<<"Salut, cum te cheama?\n>> ";
    cin>>nume;
    cout<<nume<<", tasteaza maximum "<<DimTablou
    	<<" proverbe scurte <linie vida pentru iesire>:\n";
    Sir proverbe[DimTablou];
    char temp[LungMax];
    int i;
    for (i=0;i<DimTablou;i++)
    {
    	cout<<(i+1)<<": ";
    	cin.get(temp, LungMax);
    	while (cin && cin.get()!='\n')
    		continue;
    	if (!cin || temp[0]=='\0')
    		break;
    	else
    		proverbe[i]=temp;
    }
    int total=i;

    cout<<"Iata proverbele:\n";
    for (i=0;i<total;i++)
    	cout<<proverbe[i]<<'\n';
    int celmaiscurt=0;
    int primul=0;
    for (i=1;i<total;i++)
    {
    	if (proverbe[i].lungime()<proverbe[celmaiscurt].lungime())
    		celmaiscurt=i;
    	if (proverbe[i]<proverbe[primul])
    		primul=i;
    }
    cout<<"Cel mai scurt proverb:\n"<<proverbe[celmaiscurt]<<'\n';
    cout<<"Primul in ordine alfabetica:\n"<<proverbe[primul]<<'\n';
    return 0;
}
