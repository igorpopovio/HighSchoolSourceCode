//string2.cpp - - metodele clasei Sir (fisier antet string2.h)
#include <iostream.h>
#include <string.h>
#include "strng2.h"

Sir::Sir(const char * s)
{
	lung=strlen(s);
    sir=new char[lung+1];
    strcpy(sir, s);
}
Sir::Sir()
{
	lung=0;
    sir=new char[1];
    sir[0]='\0';
}
Sir::Sir(const Sir & s)
{
	lung=s.lung;
    sir=new char[lung+1];
    strcpy(sir, s.sir);
}
Sir::~Sir()
{
	delete [] sir;
}
Sir & Sir::operator=(const Sir & s)
{
	if (this==&s)
    	return *this;
    delete [] sir;
    lung=s.lung;
    sir=new char[lung+1];
    strcpy(sir, s.sir);
    return *this;
}
Sir & Sir::operator=(const char * s)
{
	delete [] sir;
    lung=strlen(s);
    sir=new char[lung+1];
    strcpy(sir, s);
    return *this;
}
bool operator>(const Sir & s1, const Sir & s2)
{
	if (strcmp(s1.sir, s2.sir)>0)
    	return true;
    else
    	return false;
}
bool operator<(const Sir & s1, const Sir & s2)
{
	if (strcmp(s1.sir, s2.sir)<0)
    	return true;
    else
    	return false;
}
ostream & operator<<(ostream & os, const Sir & s)
{
	os<<s.sir;
    return os;
}
istream & operator>>(istream & is, Sir & s)
{
	char temp[80];
    is.get(temp, 80);
    if (is) s=temp;
    while (is && is.get()!='\n')
    	continue;
    return is;
}