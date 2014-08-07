#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include "complex.h"

int n;

void main()
{

char optiune;
cout.precision(3);
cout.width(18);

optiune=meniu();
clrscr();
while (optiune!='6')
{

switch (optiune)
{

	case '1': suma(); 			break;
	case '2': produs(); 		break;
	case '3': conjugat();		break;
	case '4': modul(); 			break;
	case '5': radical_ord2();	break;
    default: 					break;
}

optiune=meniu(); 		clrscr();

}
cout<<"Ati ales sa terminati programul! ";		exit(0);

}
