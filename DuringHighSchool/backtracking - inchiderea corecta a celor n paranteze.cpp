#include <iostream.h>
int st[100],n,k,a=0,b=0,c=1;

void init()
{
st[k]=0;
}

int am_succesor()
{
if(st[k]<2)
	{st[k]++;

    return 1;}
else return 0;
}

int e_valid()
{
if(k<=n) return 1;
	else return 0;
}

int solutie()
{
a=0; b=0;
for(int i=1;i<=n;i++)
if(st[k]==1) a++;
	else b++;
return  ((k==n) && (a==b));
}

void tipar()
{
cout<<"Varianta "<<c++<<endl;
for(int i=1;i<=k;i++)
	if(st[k]==1) cout<<"(";
		else cout<<")";
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
	if(solutie())	tipar();
    	else {k++;	init();}
}
else k--;
}
}

void main()
{
cout<<"Numarul de paranteze: ";	cin>>n;
if(n%2==0) back();
else cout<<"Numarul de paranteze trebuie sa fie un numar par!";
}


