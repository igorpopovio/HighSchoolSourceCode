#include <fstream.h>
#include <iostream.h>
void main()
{
fstream f ("C:\\Borland C++ programe\\Agenda\\Agende create\\a.txt",ios::out);
f<<"Igor este cel mai destept baiat din Univers!";
f.close();
}