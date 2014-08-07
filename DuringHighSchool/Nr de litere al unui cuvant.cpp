#include <iostream.h>
int strlen1(const char * p);
int main()
{
	char cuvant[15];
    cout<<"Introduceti un cuvant, va rog:\n";	cin.get(cuvant,15);
    cuvant[14]='\0';
    cout<<"Cuvantul dumneavoastra are "<<strlen(cuvant)<<" litere!";
    cin.get();
    cin.get();
    return 0;
}

int strlen1(const char * p)
{
	int i=0;
    while (p[i])
    	i++;
    return i;
}
