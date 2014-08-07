#include <iostream.h>
#include <conio.h>
#include "prototip.h"

void grup_serie()
{
int i,n;
double *a;
cout<<"GRUPAREA SERIE"<<endl;
cout<<"Introduceti urmatoarele: "<<endl;
cout<<"1. numarul de rezistoare: ";	cin>>n; a=new double [n];
cout<<"2. rezistentele: r1= ";	cin>>a[0];

for(i=1;i<n;i++)
{
cout<<"                 r"<<(i+1)<<"= ";	cin>>a[i];
}

cout<<endl<<endl<<endl;
cout<<"Rezistenta echivalenta a rezistoarelor introduse este:"<<endl<<"R= "<<serie(a,n);
cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
getch();
}

void grup_paralel()
{
int i,n;
double *a;
cout<<"GRUPAREA PARALEL"<<endl;
cout<<"Introduceti urmatoarele: "<<endl;
cout<<"1. numarul de rezistoare: ";	cin>>n; a=new double [n];
cout<<"2. rezistentele: r1= ";	cin>>a[0];

for(i=1;i<n;i++)
{
cout<<"                 r"<<(i+1)<<"= ";	cin>>a[i];
}

cout<<endl<<endl<<endl;
cout<<"Rezistenta echivalenta a rezistoarelor introduse este:"<<endl<<"R= "<<paralel(a,n);
cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
getch();
}

void grup_stea_triunghi()
{
int i;
double a[3];
cout<<"GRUPAREA STEA-->TRIUNGHI"<<endl;
cout<<"Introduceti rezistentele: r1= ";	cin>>a[0];

for(i=1;i<3;i++)
{
cout<<"                          r"<<(i+1)<<"= ";	cin>>a[i];
}

cout<<endl<<endl<<endl;
cout<<"Rezistentele echivalente ale rezistoarelor introduse sunt:"<<endl<<"R12= "<<stea_triunghi(a[0],a[1],a[2])<<endl;
cout<<"R13= "<<stea_triunghi(a[0],a[2],a[1])<<endl;
cout<<"R23= "<<stea_triunghi(a[1],a[2],a[0])<<endl;
cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
getch();
}

void grup_triunghi_stea()
{
int i;
double a[3];
cout<<"GRUPAREA TRIUNGHI-->STEA"<<endl;
cout<<"Introduceti rezistentele: r1= ";	cin>>a[0];

for(i=1;i<3;i++)
{
cout<<"                          r"<<(i+1)<<"= ";	cin>>a[i];
}

cout<<endl<<endl<<endl;
cout<<"Rezistentele echivalente ale rezistoarelor introduse sunt:"<<endl<<"R12= "<<triunghi_stea(a[0],a[1],a[2])<<endl;
cout<<"R13= "<<triunghi_stea(a[0],a[2],a[1])<<endl;
cout<<"R23= "<<triunghi_stea(a[1],a[2],a[0])<<endl;
cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
getch();
}
