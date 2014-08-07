#include <iostream.h>
#include "stiva1.h"
void aduna5(Element & c);
void aduna1(Element & c);

int main()
{
    Stiva A;
    unsigned long a;
    cout<<"Introduceti un element"
    	<<" in stiva (numar natural)\nsau \'p\' pentru procesare:\n";

    while(cin>>a)
    {
    	if (A.eplina())
        {
        	cout<<"stiva este deja plina!\n";
            break;
        }
        else
        {
        	A.push(a);
            cout<<"Introduceti un element"
    			<<" in stiva (numar natural)"
                <<"\nsau \'p\' pentru procesare:\n";
		}
    }
    cin.clear();
    cout<<"Acum voi aduna 5 fiecarui element din stiva!\n";
	A.vizita(aduna5);
    cout<<"Acum voi aduna 1 fiecarui element din stiva!\n";
	A.vizita(aduna1);
    return 0;
}

//------------------------------------------------------------------------------
void aduna5(Element & c)
{
	c+=5;
}
void aduna1(Element & c)
{
	c+=1;
}
