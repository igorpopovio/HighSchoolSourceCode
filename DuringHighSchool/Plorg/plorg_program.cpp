#include <iostream.h>
#include "plorg.h"

int main()
{
	Plorg A;
    Plorg B("Igor");
    A.raporteaza();
    B.raporteaza();
    A.set_cs(-20);
    B.set_cs(1000);
    A.raporteaza();
    B.raporteaza();

    return 0;
}
