#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

int main()
{
	  srand(time(0));
    double directie;
    Vector pas;
    Vector rezultat(0,0);
    unsigned long pasi=0;
    double tinta;
    double lpas;
    cout<<"Introduceti distanta pana la tinta (i pentru incheiere): ";
    while (cin>>tinta)
    {
    	cout<<"Introduceti lungimea pasului: ";
        if(!(cin>>lpas))
        	break;

        while (rezultat.vallung()<tinta)
        {
        	  directie=rand()%360;
            pas.set(lpas,directie,'p');
            rezultat=rezultat+pas;
            pasi++;
        }
        cout<<"Dupa "<<pasi<<" pasi, subiectul "
          	<<"are urmatoarea locatie:\n";
        cout<<rezultat<<"\n";
        rezultat.mod_polar();
        cout<<" sau\n"<<rezultat<<"\n";
        cout<<"Media distantei parcurse efectiv cu un pas = "
        	<<rezultat.vallung()/pasi<<"\n";
        pasi=0;
        rezultat.set(0,0);
        cout<<"Introduceti distanta pana la tinta (i pentru incheiere): ";
    }

    return 0;
}
