#include <iostream.h>
struct gonflabil
{
	char nume[20];
    float volum;
    double pret;
};

int main()
{
	gonflabil musafir=
    {
    	"Glorioasa Gloria",
        1.88,
        29.99
    };
	gonflabil amic=
    {
    	"Avantatul Arthur",
        3.12,
        32.99
    };

    cout<<"Extindeti lista dumneavoastra de invitati cu "
    	<<musafir.nume
        <<" si cu\n"
        <<amic.nume
        <<"!\n"
        <<"Ii puteti avea pe amandoi pentru "
        <<(musafir.pret+amic.pret)
        <<"$!\n";
    cin.get();
    cin.get();
    return 0;
}