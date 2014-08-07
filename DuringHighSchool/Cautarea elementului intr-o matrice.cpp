#include <iostream>
using namespace std;
int main()
{
    int i,j,n,m,x,a[10][10];
    cout<<"n=";	cin>>n;
    cout<<"m=";	cin>>m;
    cout<<"x=";	cin>>x;
    for(i=0;i<n;i++)
	for(j=0;j<m;j++)
   	  {cout<<"a["<<(i+1)<<","<<(j+1)<<"]=";
            cin>>a[i][j];}
            i=0;	j=0;
            while(i<n&&a[i][j]!=x)
	            if(j==n-i){j=0; i++;}else j++;
	            if(i!=n)
		            cout<<"S-a gasit elementul in linia "<<(i+1)<<", coloana "<<(j+1);
		             else
 		             	cout<<"Nu s-a gasit elementul!";
 		             	return 0;}
