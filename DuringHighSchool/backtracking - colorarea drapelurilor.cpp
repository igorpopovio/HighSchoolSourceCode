#include <iostream.h>

int st[10],k,n=3,a=6,g,h;
char *culoare[6]={"alb","galben","rosu","verde","albastru","negru"};

void init()
{
st[k]=0;
}

int am_succesor()
{
if(st[k]<a)	return 1;
else return 0;
}

int e_valid()
{
if(k<=n)	return 1;
return 0;
}

int e_valid1()
{
g=0;
for(int i=1;i<n;i++)
for(int j=i+1;j<=n;j++)
if(st[i]==st[j]){ g=1;    break;}

h=(st[1]==1 || st[1]==3);

if(!g && h) return 1;
return 0;
}

int solutie()
{
if(k==n)	return 1;
return 0;
}


void tipar()
{
for(int i=1;i<=n;i++)	cout<<culoare[(st[i])+1]<<"   ";
cout<<endl;
}

void back()
{
int AS;
k=1;	init();
while(k>0)
{
do {} while((AS=am_succesor()) && !e_valid());
if(AS)
{
if(solutie()){if(e_valid1()) tipar();}
	else {k++;	init();}
}
else k--;
}
}

void main()
{
back();

}
