#include <iostream.h>
struct pizza
	{
    	char compania[20];
        float diametru;
        float masa;
    } Chip_si_Dale;
int main()
{
	cout<<"Introduceti numele companiei care a produs pizza: ";
    cin.getline(Chip_si_Dale.compania,20);
    cout<<"Introduceti diametrul pizzei,in centimetri: ";
    cin>>Chip_si_Dale.diametru;
    cout<<"Introduceti masa pizzei, in grame: ";
    cin>>Chip_si_Dale.masa;

    cout<<"\n\n"
    	<<"Numele companiei care a produs pizza: "
    	<<Chip_si_Dale.compania
        <<'\n'
        <<"Diametrul pizzei: "
        <<Chip_si_Dale.diametru
        <<" centimetri\n"
        <<"Masa pizzei: "
        <<Chip_si_Dale.masa
        <<" grame";
    cin.get();
    cin.get();
    return 0;
}
