#include <iostream.h>
#include <stdlib.h>
#include "agenda.h"

char nume[20];
agenda ag[100];

void main()
{
char op;

op=meniu();
while (op!=5)
{
switch (op)
{
case '1': creare();   break;
case '3': adauga();   break;
case '2': deschide(); break;
case '4': sterge();   break;
default: op=meniu(); break;
}
op=meniu();
}
exit(1);
}