#include <iostream.h>
float gradeFahrenheit(float);
int main()
{float c,f;
cout<<"Va rog sa introduceti o valoare Celsius: ";
cin>>c;
f=gradeFahrenheit(c);
cout<<c<<" grade Celsius reprezinta "<<f<<" grade Fahrenheit.";
cin.get();
cin.get();
return 0;}
float gradeFahrenheit(float a)
{return a*1.8+32;}

