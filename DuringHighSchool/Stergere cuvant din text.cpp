#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char text[256],cuv[20],*p;
cout<<"Introduceti un text (terminat cu caracterul ENTER): "<<endl;	cin.get(text,255,'\n');	cin.get();
cout<<"Introduceti cuvantul din text pe care doriti sa-l stergeti: "<<endl;	cin.get(cuv,19,'\n');	cin.get();
p=strstr(text,cuv);
while (p)
{
strcpy(p,p+strlen(cuv));
p=strstr(text,cuv);
}
cout<<endl<<"Textul introdus fara cuvantul \""<<cuv<<"\":"<<endl<<text;
getch();
}