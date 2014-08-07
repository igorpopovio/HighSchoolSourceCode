#include <iostream.h>
#include <math.h>
int st[100],n,k,a=0;

void init()
{
st[k]=0;
}

int am_succesor()
{
if(st[k]<n)
{
st[k]++;	return 1;
}
else return 0;
}

int e_valid()
{
for(int i=1;i<k;i++)
if(st[k]==st[i] || abs(st[k]-st[i])==abs(k-i)) return 0;
return 1;
}

int solutie()
{
return (k==n);
}

void tipar()
{
for(int i=1;i<=n;i++)	cout<<st[i]<<"  ";
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
if(solutie()) {tipar(); a++;}
else	{k++;	init();}
}
else k--;
}
}

int main()
{
cout<<"n=  ";	cin>>n;
if(n>10){ cout<<"nu se poate calcula!"; return 0;}
back();
cout<<"exista "<<a<<" posibilitati de ordonare a celor "<<n<<" dame !";
}