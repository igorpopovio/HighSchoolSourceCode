#include <iostream.h>
#include <math.h>
int main()
{
	long double a,q,s,b,n,c,d;

	cout<<"Introduceti primul termen si ratia unei progresii"
		<<" geometrice si un numar natural(programul va afisa termenul"
    	<<" al n-lea si suma primilor n termeni):"<<endl;
	cout<<"primul termen=";		cin>>a;
	cout<<"ratia=";		cin>>q;
	cout<<"numar=";		cin>>n;
	c=n-1;
	d=pow(q,c);
	b=a*d;
	s=(a*(pow(q,n)-1))/(q-1);
	cout<<"Al "<<n<<"-lea termen al acestei progresii geometrice este "<<b<<"."<<endl;
	cout<<"Suma primilor "<<n<<" termeni ai acestei progresii geometrice este "<<s<<".";
	cin.get();
    cin.get();
	return 0;
}