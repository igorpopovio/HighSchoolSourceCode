#include <iostream.h>
#include <fstream.h>
#include <math.h>
int main()
{
	fstream f1("Hacker.in.txt",ios::in),f2("Luceafar.Out.txt",ios::out);
	unsigned a,g=0;

    while (f1.get(a,9,'#')&&g==0)
    	if (int(sqrt(a))==sqrt(a))		f2<<char(sqrt(a));
        	else g=1;
	f1.close();
	f2.close();
	return 0;
}