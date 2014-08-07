#include <conio.h>
#include <iostream.h>
int n,coada[50],s[50],i_c=1,sf_c=1,a[50][50]={0},i,m,j;

void citire()
{
cout<<"noduri= ";  cin>>n;
cout<<"muchii= "; cin>>m;
cout<<"(i,j)= i j ENTER"<<endl;
for(int k=1;k<=m;k++)
{
cout<<"muchia "<<k<<": "; cin>>i>>j; a[i][j]=a[j][i]=1;
}
}

void bf(int nod)
{
cout<<"Parcurgerea nodurilor grafului in latime - BF:"<<endl;
coada[i_c]=nod;   s[nod]=1;
while(i_c<=sf_c)
{
i=1;
while(i<=n)
{
if(a[coada[i_c]][i]==1 && s[i]==0)
{
sf_c++;   coada[sf_c]=i;    s[i]=1;
}
i++;
}
cout<<coada[i_c]<<" "; i_c++;
}
}

void main()
{
citire();   int k;
cout<<"k= ";  cin>>k;
bf(k);
getch();
}
