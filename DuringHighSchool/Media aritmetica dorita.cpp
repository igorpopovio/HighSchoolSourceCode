#include <iostream.h>
int main()
{
	int i,n,c,x,m,j;
    float a[50],m1,ma,s1=0,s2,b[50];

    cout<<"Introduceti media pe care doriti sa o aveti: ";	cin>>ma;
    cout<<"Introduceti numarul de note pe care le aveti: ";	cin>>n;
    cout<<"Introduceti numarul maxim de note pe care puteti sa le aveti: ";	cin>>m;
    cout<<"Introduceti notele pe care le aveti:\n";

    for(i=0;i<n;i++)
    	{cout<<"nota "<<(i+1)<<" = ";	cin>>a[i];	s1+=a[i];}
    s2=ma*m-s1;		m1=s1/n;
    if(m1<ma)
    	{i=0;
        while(s2>10)
        	{b[i]=10;	s2-=10;		i++;}
        b[i]=s2;	c=i+1;
        if(i>=1)
        	{for(j=0;b[i-1]>=b[i];j++)
            	{cout<<"Cazul "<<(j+1)<<":\t";
                for(x=0;x<(c-2);x++)
                	cout<<"10;\t";
                cout<<(b[i-1]-j)<<"\t"
                    <<(b[i]+j)<<"\t";}}
        else cout<<b[i];}
    else if(m1==ma) cout<<"Domnule elev deja ai media pe care doreai sa o ai (media "<<ma<<")!";
    	else cout<<"Nu am intalnit nici un elev pana acum care sa doreasca sa-si micsoreze media!";
	cin.get();
    cin.get();
    return 0;}

