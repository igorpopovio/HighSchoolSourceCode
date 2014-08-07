#include <iostream.h>
#include <string.h>
#include "lib.h"

Lib::Lib()
{
	strcpy(nume,"fara nume");
    pret=50000.0;
}

Lib::Lib(const char * p,double pr)
{
	strncpy(nume,p,19);
    nume[19]='\0';
    pret=pr;
}

Lib::~Lib()	{}

void Lib::citeste()
{
	cout<<"Introduceti numele cartii: ";
    cin.get(nume,19);
    nume[19]='\0';
    cout<<"Introduceti pretul cartii: ";
    cin>>pret;
}

void Lib::set_nume(const char * p)
{
	strncpy(nume,p,19);
    nume[19]='\0';
}
void Lib::set_pret(const double n)
{
	pret=n;
}

void Lib::arata()
{
	cout<<"Numele cartii: "<<nume<<"\tPret: "<<pret<<"\n";
}
