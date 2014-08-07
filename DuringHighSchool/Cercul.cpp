#include <iostream>
int main()
{long double r;
const double PI=3.1415926535;
cout<<"Introduceti raza cercului "
    <<"(programul va afisa aria si lungimea cercului de raza r):"<<endl;
cout<<"Raza=";	cin>>r;
cout<<"Aria="<<(PI*r*r)<<endl;
cout<<"Lungimea="<<(2*PI*r);
cin.get();
return 0;}
