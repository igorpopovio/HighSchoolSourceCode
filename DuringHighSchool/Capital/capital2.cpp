#include <iostream.h>
#include "capital.h"

const int 	CAPIT=4;
int main()
{
	Capital capitaluri[CAPIT]=
    {
    	Capital("NanoSmart",12,20),
        Capital("Obiecte Hazlii",200,2),
        Capital("Obeliscuri Monolitice",130,3.25),
        Capital("Fleep SA",60,6.5)
    };

    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);
    cout.setf(ios::showpoint);

    cout<<"Capitaluri detinute:\n";
    int cap;
    for (cap=0;cap<CAPIT;cap++)
    	capitaluri[cap].arata();
    Capital max= capitaluri[0];
    for (cap=1;cap<CAPIT;cap++)
    	max=max.valmax(capitaluri[cap]);
    cout<<"\nActiunile cele mai valoroase:\n";
    max.arata();

    return 0;
}