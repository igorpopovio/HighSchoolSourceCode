#include <fstream.h>
#include <math.h>
#include <conio.h>

float a[50][50];  int n;

float * creare_m(float *a,int n, int i,int j)
{
float (* m)[(n-1)];
m=new float [(n-1)][(n-1)];
int k,q,p=0,r=0;
for(k=0;k<n;k++)
for(q=0;q<n;q++)
{
if(k==i) k++;
if(q==j) q++;
m[p][r]=a[k][q];  p++;  r++;
}
return m;
}

float determinant(float *a,int n)
{
if(n==2) return a[0][0] * a[1][1] - a[0][1] * a[1][0];
else
{
int f;  float s=0;
for(f=0;f<n;f++)  s+=determinant(creare_m(a,n,0,f),n-1) * a[0][f] * pow(-1,f);
return s;
}
}

void citire()
{
fstream fin("matrice.in",ios::in);
fin>>n;
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
fin>>a[i][j];

f.close();
}

void scrie()
{
fstream fout("determinant.out",ios::out);
float z=determinant(a,n);
fout<<z;  fout.close();
cout<<z;
getch();
}

void main()
{
citire(); scrie();
}
