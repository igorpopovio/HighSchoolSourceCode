//capital.cpp - - metodele clasei Capital ("capital.h")
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include "capital.h"

Capital::Capital()
{
	strcpy(societate," societate necunoscuta");
    actiuni=0;
    val_actiune=0;
    val_totala=0;
}

Capital::Capital(const char * sa,int n,double pr)
{
	strcpy(societate,sa);
    actiuni=n;
    val_actiune=pr;
    stab_total();
}

void Capital::cumpara(int nr,double pret)
{
	actiuni+=nr;
    val_actiune=pret;
    stab_total();
}

void Capital::vinde(int nr,double pret)
{
	if(nr>actiuni)
    {
    	cerr<<"Nu puteti vinde mai mult decat aveti!\n";
        exit(1);
    }
    actiuni-=nr;
    val_actiune=pret;
    stab_total();
}

void Capital::actualizeaza(double pret)
{
	val_actiune=pret;
    stab_total();
}

void Capital::arata() const
{
	cout<<"Societate: "<<societate
    	<<"\tActiuni: "<<actiuni<<"\n"
        <<"\tPret actiune: "<<val_actiune<<"$"
        <<"\tValoare totala: "<<val_totala<<"$\n";
}

const Capital & Capital::valmax(const Capital & c) const
{
	if(c.val_totala>val_totala)
    	return c;
    else
    	return *this;
}