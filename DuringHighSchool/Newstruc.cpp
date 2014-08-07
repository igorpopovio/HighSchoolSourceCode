#include <iostream.h>
int main()
{   
        struct gonflabil
        {   
            char nume[20];
            float volum;
            double pret;
        };
    gonflabil *ps=new gonflabil;
    cout<<"Introduceti numele articolului gonflabil: ";
    cin.get(ps->nume,20);
    cout<<"Introduceti volumul in metri cubi: ";
    cin>>(*ps).volum;
    cout<<"Introduceti pretul: ";
    cin>>ps->pret;
    cout<<"Nume: "<<(*ps).nume<<"\n";
    cout<<"Volum: "<<ps->volum<<" metri cubi\n";
    cout<<"Pretul: "<<ps->pret<<"$\n";
    cin.get();
    cin.get();
    return 0;
}
