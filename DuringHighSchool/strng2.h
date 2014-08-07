//string2.h
#ifndef __STRING2_H
#define __STRING2_H
#include <iostream.h>

class Sir
{
private:
	  char * sir;
    int lung;
public:
	Sir(const char * s);
    Sir();
    Sir(const Sir & s);
    ~Sir();
    int lungime() const {return lung;}
//overloaded operators
	Sir & operator=(const Sir & s);
    Sir & operator=(const char * s);
//friend functions
	friend bool operator>(const Sir & s1, const Sir & s2);
    friend bool operator<(const Sir & s1, const Sir & s2);
    friend bool operator==(const Sir & s1, const Sir & s2);
    friend ostream & operator<<(ostream & os, const Sir & s);
    friend istream & operator>>(istream & is, Sir & s);
};

#endif
