#include <iostream.h>
int main()
{
	char c;

    cout<<"Va rog sa introduceti una din urmatoarele optiuni:\nc) carnivor\tp) pianist\na) arbore\tj) joc\n";
	cin>>c;
    while (c!='c'&&c!='p'&&c!='a'&&c!='j')
    {
    	cout<<"Va rog tastati c,p,a sau j: ";
        cin>>c;
    }
    switch (c)
    {
    	case 'c': cout<<"Lupul este carnivor!";	break;
        case 'p': cout<<"Cand voi fi mare voi fi pianist!"; break;
        case 'a': cout<<"Artarul este un arbore!"; break;
        case 'j': cout<<"Imi place sa ma joc!"; break;
    }
    cin.get();
    cin.get();
    return 0;
}
