#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
char *sir="123456789",*p;
int n1;
long n2;
double n3;
long double n4;

n1=atoi(sir);
n2=atol(sir);
cout<<n1<<"       "<<n2<<endl;
strcpy(sir,"12345");
n1=atoi(sir);
n2=atol(sir);
cout<<n1<<"       "<<n2<<endl;
strcpy(sir,"12345.6789");
n1=atoi(sir);
n2=atol(sir);
n3=atof(sir);
n4=_atold(sir);
cout<<n1<<"       "<<n2<<"       "<<n3<<"       "<<n4<<endl;
strcpy(sir,"12Aa");
n2=strtol(sir,&p,16);
if (!*p) cout<<"conversie corecta -> "<<n2<<endl;
	else {cout<<"nu s-au putut converti decat primele "<<(p-sir)<<" caractere -> "<<n2<<endl;}
n2=strtol(sir,&p,10);
if (!*p) cout<<"conversie corecta -> "<<n2<<endl;
	else {cout<<"nu s-au putut converti decat primele "<<(p-sir)<<" caractere -> "<<n2<<endl;}
getch();
}
