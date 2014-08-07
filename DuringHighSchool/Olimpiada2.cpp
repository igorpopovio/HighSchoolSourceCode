#include <iostream.h>
#include <fstream.h>
#include <math.h>
void main()
{int n=1000;
float a,b[100];
fstream f1("Hacker_in.txt",ios::in);	fstream f2("Hacker_out.txt",ios::out);
f1.getline(b,n,"#");
while(!f1.eof())
	{a=sqrt(b);
    f2<<'a';
    f1.getline(b,n,"#");}
f1.close();	f2.close();}

