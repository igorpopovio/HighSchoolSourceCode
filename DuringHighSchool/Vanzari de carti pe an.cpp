#include <iostream.h>
int main()
{
	const char *luna[12]=
    	{
        	"Ianuarie","Februarie","Martie","Aprilie","Mai","Iunie",
        	"Iulie","August","Septembrie","Octombrie","Noiembrie","Decembrie"
        };
    int vanzari[3][12],i,j,s1[3],s2=0;

    for (i=0;i<3;i++)
    	{
        	s1[i]=0;
            cout<<"Anul "<<(i+1)<<": \n";
            for (j=0;j<12;j++)
    			{
        			cout<<"Vanzari - luna "<<luna[j]<<": ";
            		cin>>vanzari[i][j];
                    s1[i]+=vanzari[i][j];
        		}
		}
    for (i=0;i<3;i++)
    	{
        	s2+=s1[i];
    		cout<<"\nPentru anul "<<(i+1)<<" totalul vanzarilor lunare de carti atinge valoarea de: "
    			<<s1[i];
        }
    cout<<"\n\nNumarul de vanzari pe parcursul celor trei ani este de: "<<s2;
    cin.get();
    cin.get();
    return 0;
}

