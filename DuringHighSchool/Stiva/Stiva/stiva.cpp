//stiva.cpp - - metodele clasei Stiva
#include "stiva.h"
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
	if (varf<Max)
    {
    	elemente[varf++]=elem;
        return true;
    }
    else
       return false;
}

bool Stiva::pop(Element & elem)
{
	if (varf>0)
    {
    	elem=elemente[--varf];
        return true;
    }
    else
       return false;
}

