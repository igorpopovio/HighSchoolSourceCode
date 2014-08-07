#include <iostream.h>
#include "complex.h"

char meniu()
{
cout<<endl;
cout<<"1. suma a \"n\" numere complexe\n";
cout<<"2. produsul a \"n\" numere complexe\n";
cout<<"3. conjugatul unui numar complex\n";
cout<<"4. modulul unui numar complex\n";
cout<<"5. radacina patrata a unui numar complex\n";
cout<<"6. terminare\n";

char a;
cout<<"Optiunea dumneavoastra: ";	cin>>a;
return a;
}
