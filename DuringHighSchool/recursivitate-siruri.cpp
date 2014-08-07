#include <string.h>
#include <iostream.h>

int m;

void citire(char *s)
{
cout<<"Introduceti un cuvant: ";	cin.get(s,50,'\n');
cin.get();
}

int compara(char *s1,char *s2,int n)
{
if(n<m)
{
if(s1[n]<s2[n]) return -1;
	else if(s2[n]<s1[n]) return 1;
else return (compara(s1,s2,n)*compara(s1,s2,n+1));
}
else if(n==m) return 0;
}

void main()
{
char s1[50],s2[50];
citire(s1); citire(s2);
m=(strlen(s1)<strlen(s2))?strlen(s1):strlen(s2);
switch(compara(s1,s2,0))
{
case -1: cout<<"s1<s2"<<endl; break;
case  0: cout<<"s1=s2"<<endl; break;
case  1: cout<<"s1>s2"<<endl; break;
}
}