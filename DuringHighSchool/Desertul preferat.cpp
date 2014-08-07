#include <iostream.h>
int main()
{
	const int DimTab =20;
    char nume[DimTab];
    char desert[DimTab];

    cout<<"Introduceti numele dumneavoastra:\n";
    cin.getline(nume,DimTab);
    cout<<"Introduceti desertul dumneavoastra preferat:\n";
    cin.getline(desert,DimTab);
    cout<<"Am un "<<desert<<" delicios "
    	<<"pentru dumneavoastra, "<<nume<<".\n";
    cin.get();
    cin.get();
    return 0;
}