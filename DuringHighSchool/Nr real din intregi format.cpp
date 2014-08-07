#include <iostream.h>
#include <ctype.h>
int main()
{
	char c;
    int p=1,a=0,b=0;
    float d;


    while (cin.get(c))
    {
    	if (!isdigit(c)||c=='.')	break;
        a=a*p+int(c-48);
        p*=10;
	}
    p=1;
    while (cin.get(c))
    {
        if (!isdigit(c))	break;
        b=b*p+int(c-48);
        p*=10;
    }
    cout<<a<<"    "<<b<<"     "<<p;
    d=a+float(b)/p;
    cout<<"\n"<<d;
    cin.get();
    cin.get();
    return 0;
}