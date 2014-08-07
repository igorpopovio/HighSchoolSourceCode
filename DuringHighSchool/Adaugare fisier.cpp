#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
void main()
{char c;
fstream f1("alfa.txt",ios::in);
fstream f2("beta.txt",ios::in);
fstream f3("gama.txt",ios::app);
while(!f1.eof())
	{f1>>resetiosflags(ios::skipws)>>c;	f3<<resetiosflags(ios::skipws)<<c;}
while(!f2.eof())
	{f2>>resetiosflags(ios::skipws)>>c;	f3<<resetiosflags(ios::skipws)<<c;}
f1.close();	f2.close();	f3.close();}



