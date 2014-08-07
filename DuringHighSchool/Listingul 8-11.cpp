#include <iostream.h>
template <class Orice>
void Schimba(Orice &a,Orice &b);

struct serviciu
{
	char nume[40];
	double salar;
	int etaj;
};
void Schimba<serviciu>(serviciu &s1, serviciu &s2);
void Arata(serviciu &s);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	serviciu sue={"Susan Yaffee",63000.60,7};
	serviciu sidney={"Sidney Taffee",66060.72,9};
	cout<<"Inainte de schimbarea serviciilor:\n";
	Arata(sue);
	Arata(sidney);
	Schimba(sue,sidney);
	cout<<"Dupa schimbarea serviciilor:\n";
	Arata(sue);
	Arata(sidney);
	cin.get();
	return 0;
}

template <class Orice>
void Schimba(Orice &a, Orice &b)
{
	Orice temp;
	temp=a;
	a=b;
	b=temp;
}
void Schimba<serviciu>(serviciu &s1, serviciu &s2)
{
	double t1;
	int t2;
	t1=s1.salar;
	s1.salar=s2.salar;
	s2.salar=t1;
	t2=s1.etaj;
	s1.etaj=s2.etaj;
	s2.etaj=t2;
}
void Arata(serviciu &s)
{
	cout<<s.nume<<": "<<s.salar
		<<"$, la etajul "<<s.etaj<<"\n";
}


