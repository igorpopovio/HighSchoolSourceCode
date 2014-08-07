//stiva.cpp - - metodele clasei Stiva
#include <iostream.h>
#include "stiva1.h"
#include <stdlib.h>
Stiva::Stiva()
{
	varf=0;
}

bool Stiva::evida() const
{
	return varf==0;
}

bool Stiva::eplina() const
{
	return varf==Max;
}

bool Stiva::push(const Element & elem)
{
	k=0;
    if (varf<Max)
    {
    	elemente[varf++]=elem;	k++;
        return true;
    }
    else
       return false;
}



void Stiva::vizita(void (* p)(Element & c))
{
  set_varf();
	for (;varf<k;varf++)
    {
      (* p)(elemente[varf]);
    	cout<<elemente[varf]<<"\n";
    }
}

