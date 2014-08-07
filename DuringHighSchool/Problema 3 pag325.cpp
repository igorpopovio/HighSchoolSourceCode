#include <iostream.h>
#include <string.h>
struct stringy
{
	char * sir;
    int ct;
};
void seteaza(stringy & a,const char * p);
void arata(stringy & a,int n=1);
void arata(const char * p,int j=1);
int main()
{
	stringy beany;
    char testare[]="Realitatea nu mai este ce era.";
    seteaza(beany,testare);
    arata(beany);
    arata(beany,2);
    testare[0]='D';
    testare[1]='u';
    arata(testare);
    arata(testare,3);
    arata("gata!");
    cin.get();
    return 0;
}
void seteaza(stringy & a,const char * p)
{
	a.sir=new char [strlen(p)+1];
    strcpy(a.sir,p);
    a.sir[strlen(p)]='\0';
    a.ct=1;
}
void arata(stringy & a,int n)
{
    for (int i=1;i<=n;i++)
		cout<<a.sir<<"\n";
}
void arata(const char * p,int j)
{
	for (int i=1;i<=j;i++)
		cout<<p<<"\n";
}

