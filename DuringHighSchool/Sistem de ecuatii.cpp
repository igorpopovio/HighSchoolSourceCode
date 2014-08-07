#include <iostream.h>
int main()
{
	long double a1,b1,c1,a2,b2,c2,ds,dx,dy;
	cout<<"Introduceti coeficientii sistemului"
		<<" de ecuatii:"<<endl<<"a1*x+b1*y=c1"
    	<<""<<endl<<"a2*x+b2*y=c2"<<endl<<endl;
	cout<<"a1=";	cin>>a1;
	cout<<"b1=";	cin>>b1;
	cout<<"c1=";	cin>>c1;
	cout<<"a2=";	cin>>a2;
	cout<<"b2=";	cin>>b2;
	cout<<"c2=";	cin>>c2;
	ds=a1*b2-b1*a2;	dx=b2*c1-b1*c2;	dy=a1*c2-a2*c1;
	if(ds==0)
		{
        	if(dx==0)	cout<<"Sistem nedeterminat"<<'\a';
    		else	cout<<"Sistem incompatibil"<<'\a';
        }
  	else
    {
    	cout<<"Solutiile sistemului sunt:"
         	<<""<<endl<<"x="<<(float)(dx/ds)<<endl<<"y="
         	<<(float)(dy/ds);}
cin.get();
cin.get();
return 0;
}
