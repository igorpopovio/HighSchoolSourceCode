#include <iostream.h>
#include <ctype.h>
int main()
{
	char ch[100];
    int i;

    cout<<"Introduceti va rog o linie de text:\n";
    cin.getline(ch,100);
    for (i=0;ch[i]!='@'&&ch[i]!='\0';i++)
    	{if (!isdigit(ch[i]))
        	{if (ch[i]==tolower(ch[i])) cout<<char(toupper(ch[i]));
            	else cout<<char(tolower(ch[i]));}
        	else continue;}
    cin.get();
    cin.get();
    return 0;
}