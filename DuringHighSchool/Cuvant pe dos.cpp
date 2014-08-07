#include <iostream.h> //Programul afiseaza un cuvant,
#include <string.h>   //citit de la tastatura, pe dos !
int main()
{
	char cuvant[50];
    int i;

    cout<<"Introduceti un cuvant: ";	cin>>cuvant;
    for (i=strlen(cuvant)-1;i>=0;i--)
    	cout<<cuvant[i];
	cin.get();
    cin.get();
    return 0;
}

