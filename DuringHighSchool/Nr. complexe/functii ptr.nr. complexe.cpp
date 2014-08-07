#include <iostream.h>
#include <math.h>
#include <conio.h>
#include "complex.h"

extern int n;


void suma()
{

	complex suma={0,0},c[100];
	citeste_vector(c);
	for (int i=0;i<n;i++)
	{
		suma.real+=c[i].real;
		suma.imaginar+=c[i].imaginar;
	}
	cout<<"suma este:\n";	afiseaza(suma);
}

void produs()
{

	complex produs={1,1},c[100];
	citeste_vector(c);
	produs.real=c[0].real;
	produs.imaginar=c[0].imaginar;
	float a=produs.real,b=produs.imaginar;
	for (int i=1;i<n;i++)
	{
		produs.real=a*c[i].real-b*c[i].imaginar;
		produs.imaginar=a*c[i].imaginar+c[i].real*b;
		a=produs.real;		b=produs.imaginar;
	}
	cout<<"produsul este:\n";	afiseaza(produs);
}

void afiseaza(complex &c)
{

	cout.setf(ios::showpos);
	cout<<"    ";
	cout<<c.real<<c.imaginar<<"*i"<<'\n';
	cout.unsetf(ios::showpos);
	cout<<"Apasati orice tasta ...\n";	getch();  clrscr();
}

void modul()
{

	float x;
	complex c;
	citeste(c);
	x=sqrt(pow(c.real,2)+pow(c.imaginar,2));
	cout<<"Modulul este\n"<<"    "<<x<<'\n';
	cout<<"Apasati orice tasta ...\n";	getch();  clrscr();
}

void conjugat()
{

	complex d,c;
	citeste(c);
	d.real=c.real;
	d.imaginar=-c.imaginar;
	cout<<"Conjugatul este\n"; afiseaza(d);
}

void radical_ord2()
{

	float a,b,x,d,e;
	complex alfa,c;
	citeste(c);
	a=c.real;
	b=c.imaginar/2;
	x=sqrt(pow(c.real,2)+pow(c.imaginar,2));
	d=sqrt((a+x)/2);
	e=sqrt(x-pow(d,2));
	if (b>0)
	{
		alfa.real=d;
		alfa.imaginar=e;
	}
	else
	{
    	alfa.real=-d;
		alfa.imaginar=e;
	}
	afiseaza_rad(alfa);
}

void afiseaza_rad(complex &c)
{

	cout<<"\nRadacinile complexe sunt\n"; afiseaza(c);
	cout<<"\nsi\n";
	c.real=-c.real;
	c.imaginar=-c.imaginar;
	afiseaza(c);
}

void citeste_vector(complex *c)
{

	cout<<endl<<"Cu cate numere complexe doriti sa lucrati?\n";	cin>>n;
	cout<<"\nIntroduceti numerele complexe:\n";

	int i;

	for (i=0;i<n;i++)
	{
		cout<<"numarul "<<(i+1)<<":";
		cout<<"\n     partea reala: ";		cin>>c[i].real;
		cout<<"\n     partea imaginara: ";	cin>>c[i].imaginar;
	}

}

void citeste(complex &c)
{

	cout<<"Introduceti numarul complex:";
	cout<<"\n     partea reala: ";		cin>>c.real;
	cout<<"\n     partea imaginara: ";	cin>>c.imaginar;
}

double rad_in_grade(double &r)
{

	double g;

	g=r*180/M_PI;
	return g;
}

double grade_in_rad(double &g)
{

	double r;

	r=g*M_PI/180;
	return r;
}













































































