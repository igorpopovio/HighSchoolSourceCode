#include <iostream.h>
#include <time.h>
int main()
{
	cout<<"Introduceti valoarea decalajului, in secunde: ";
    float secunde;
    cin>>secunde;
    clock_t decalaj=secunde*CLOCKS_PER_SEC;
    cout<<"Start!\a\n";clock_t start=clock();
    cout<<start<<'\n';
    while((clock()-start)<decalaj);
    cout<<"Gata!\a\n";
    cin.get();
    cin.get();
    return 0;
}