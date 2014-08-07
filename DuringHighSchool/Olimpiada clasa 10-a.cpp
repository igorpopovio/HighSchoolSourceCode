	#include <iostream.h>
	#include <string.h>
	#include <conio.h>
	void main()
	{
	char sir[1000],*v[256],*c;
	int p,i,a;

	cout<<"Introduceti sirul: "<<endl;	cin.get(sir,1000,'\n');      cin.get();
	cout<<"Introduceti numarul de caractere al liniilor: ";	cin>>p;
	a=strlen(sir)/p;
    for(i=0;i<p;i+=2)
	{
	strncat(v[i],(sir+i*a),a);
	if(i>=p) break;
	strncpy(c,(sir+(i+1)*a),a);
	strcat(v[i+1],strrev(c));
	}

	for(i=0;i<a;i++)
		cout<<v[i]<<endl;
	getch();
	}
