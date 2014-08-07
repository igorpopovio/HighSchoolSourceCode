#include <iostream.h>


double serie(double * a,unsigned n)
{
int i;
double re=0;

for(i=0;i<n;i++)	re+=a[i];
return re;
}

double paralel(double * a,unsigned n)
{
int i;
double re=0;

for(i=0;i<n;i++)	re+=1/a[i];
re=1/re;
return re;
}

double stea_triunghi(double a,double b,double c)
{
return a+b+(a*b)/c;
}

double triunghi_stea(double a,double b,double c)
{
return a*b/(a+b+c);
}

