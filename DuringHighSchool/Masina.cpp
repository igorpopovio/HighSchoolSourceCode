#include <iostream.h>
struct masina
{
	char marca[20];
    int an;
};
int main()
{
	int n,i;

	cout<<"Cate masini doriti sa treceti in catalog? ";
    cin>>n;
    masina *p= new masina ;

    for (i=0;i<n;i++)
    {
    	cout<<"Masina "<<(i+1)<<": ";
        cout<<"Va rog sa introduceti marca: ";
        cin.get(a[i]->marca,20);
        cout<<"Va rog sa introduceti anul fabricatiei: ";
        cin>>a[i]->an;
    }

    cout<<"\n\nIata colectia dumneavoastra:\n";
    for (i=0;i<n;i++)
		cout<<a[i]->an<<" "<<a[i]->marca<<"\n";
    cin.get();
    cin.get();
    return 0;
}
