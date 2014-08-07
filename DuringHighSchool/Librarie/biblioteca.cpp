#include <iostream.h>
#include "lib.h"
int main()
{
	Lib A;
	Lib B("New C++ Primer Plus",534000),C;
    C.citeste();
    A.arata();
	B.arata();
    C.arata();
    return 0;
}