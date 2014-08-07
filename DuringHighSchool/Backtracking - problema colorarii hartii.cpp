#include <iostream.h>
int st[10],a[20][20],n,k,c=0;

void init()
{
st[k]=0;
}

int am_succesor()
{
if(st[k]<4)
{st[k]++;	return 1;}
else return 0;
}

int e_valid()
{
for(int i=1;i<=(k-1);i++)
	if(st[i]==st[k] && a[i][k]==1) return 0;
return 1;
}

int solutie()
{
return (k==n);
}

void tipar()
{
cout<<"Varianta "<<c++<<endl;
for(int i=1;i<=n;i++)	cout<<"tara "<<i<<" culoarea "<<st[i]<<endl;
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
{if(solutie())	tipar();
	else {k++; init();}
}
else k--;
}
}

void main()
{
cout<<"Numar de tari ";	cin>>n;
for(int i=1;i<=n;i++)
  for(int j=1;j<=i-1;j++)
  {
  cout<<"a["<<i<<"]["<<j<<"]= ";	cin>>a[i][j];
  a[j][i]=a[i][j];
  }
back();
}

