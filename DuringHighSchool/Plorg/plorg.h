#ifndef __PLORG_H
#define __PLORG_H

class Plorg
{
private:
	char nume[19];
    int cs;
public:
	Plorg();
    Plorg(char * p);
    ~Plorg();
    void set_cs(int n)	{cs=n;};
    void raporteaza();
};

#endif