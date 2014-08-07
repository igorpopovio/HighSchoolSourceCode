#include <iostream>
using namespace std;
int main()
{
    int actualizari=6;
    int *p_actualizari;
    
    p_actualizari=&actualizari;
    cout<<"Valori: actualizari= "
        <<actualizari
        <<", *p_actualizari= "
        <<*p_actualizari
        <<"\n";
    
    cout<<"Adrese: &actualizari= "
        <<&actualizari
        <<", p_actualizari= "
        <<p_actualizari
        <<"\n";
        
    *p_actualizari+=1;
    cout<<"Dupa incrementarea cu 1 a lui *p_actualizari, actualizari devine: "
        <<actualizari;
    cin.get();
    cin.get();
    return 0;
}
