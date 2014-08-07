//stivuitor.cpp - - testeaza clasa Stiva
#include <iostream.h>
#include <ctype.h>
#include "stiva.h"

int main()
{
	Stiva st;
    char c;
    unsigned long cc;
    cout<<"Tastati A pentru a adauga o comanda de cumparare,\n"
    	<<"P pentru procesarea comenzii sau "
        <<"I pentru iesire.\n";
    while (cin>>c&&toupper(c)!='I')
    {
    	while (cin.get()!='\n')
        	continue;
        if (!isalpha(c))
        {
        	cout<<"\a";
            continue;
        }
        switch (c)
        {
        	case 'A':
            case 'a': cout<<"Introduceti un numar de CC pentru adaugare: ";
            		  cin>>cc;
                      if (st.eplina())
                      	cout<<"stiva este deja plina\n";
                      else
                      	st.push(cc);
                      break;
            case 'P':
            case 'p': if(st.evida())
            			cout<<"stiva este vida\n";
            		  else
                      {
                      	st.pop(cc);
                        cout<<"CC #"<<cc<<" extrasa\n";
                      }
                      break;
        }
        cout<<"Tastati A pentru a adauga o comanda de cumparare,\n"
    	<<"P pentru procesarea comenzii sau "
        <<"I pentru iesire.\n";
    }
    return 0;
}
