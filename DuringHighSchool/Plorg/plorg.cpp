#include <iostream.h>
#include <string.h>
#include "plorg.h"

Plorg::Plorg()
{
	strcpy(nume,"Plorga");
    cs=50;
}

Plorg::Plorg(char * p)
{
	strcpy(nume,p);
    cs=50;
}

Plorg::~Plorg()		{}

void Plorg::raporteaza()
{
	cout<<"Nume: "<<nume<<"\tCS: "<<cs<<"\n";
}

