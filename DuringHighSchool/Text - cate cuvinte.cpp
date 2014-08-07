#include <iostream.h>
#include <conio.h>
#include <string.h>
void main()
{
    int k=0,i=0;
    char a[256];

    cout<<"Introduceti un text. Dupa terminare apasati tasta ENTER! "<<endl;
    cin.get(a,100,'\n');   cin.get();

    while (a[i])
    {
    if (a[i]==' ' ||a[i]==',' ||a[i]=='.') k++; i++;	
    }
    cout<<"Textul introdus contine "<<k<<" cuvinte!";
    getch();
}
