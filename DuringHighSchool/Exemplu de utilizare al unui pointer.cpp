#include <iostream.h>
int main()
{
	double *p3=new double[3];
    p3[0]=0.2;	p3[1]=0.5;	p3[2]=0.8;
    cout<<"p3[1] este "
    	<<p3[1]
        <<".\n";
    p3=p3+1;
    cout<<"Acum, p3[0] este "
    	<<p3[0]
        <<", iar p3[1] este "
        <<p3[1]<<".\n";
    p3-=1;
    delete [] p3;
    cin.get();
    cin.get();
    return 0;
}
