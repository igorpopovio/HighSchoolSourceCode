#include <iostream.h>
#include <string.h>
int main()
{
	const int Dimensiune=15;
    char nume1[Dimensiune];
    char nume2[Dimensiune]="C++owboy";

    cout<<"Salutare! Eu sunt "<<nume2;
    cout<<"! Cum te cheama?\n";
    cin>>nume1;
    cout<<"Ei bine, "<<nume1<<", numele tau are "
    	<<strlen(nume1)
        <<" litere si este stocat\n"
        <<"intr-un tablou de "
        <<sizeof nume1<<" octeti.\n";
    nume2[3]='\0';
    cout<<"Iata primele trei caractere ale numelui meu: "
    	<<nume2<<"\n";
    cin.get();
    cin.get();
    return 0;
}

