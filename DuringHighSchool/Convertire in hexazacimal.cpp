#include <iostream.h>
#include <iomanip.h>
int main()
{
	unsigned long x;
    cout<<"x= ";	
	while(cin>>x)
	{

		cout<<setiosflags(ios::hex)<<setiosflags(ios::uppercase)<<x<<"\n";
        cout<<"x= ";
    }

cin.get();
return 0;
}