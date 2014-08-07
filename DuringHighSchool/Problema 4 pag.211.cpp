#include <iostream.h>
#include <time.h>
int main()
{
	const int dimsir=21;
    char c;
    int i,a;
    clock_t f=10*CLOCKS_PER_SEC;
    struct obp
    {
    	char nume[dimsir];
        char functie[dimsir];
        char poreclaOBP[dimsir];
        int optiune;
    };
    cout<<"Raportul Ordinului Binevoitor al Programatorilor\n"
    "a. afisare dupa nume\t\tb. afisare dupa functie\n"
    "c. afisare dupa porecla\t\td. afisare dupa preferinte\ni. iesire\n";
    cout<<"Dupa ce tastati \"i\" asteptati 10 de secunde iar programul se va inchide automat!\n"; 
    cout<<"Optiunea dumneavoastra: ";	cin>>c;

    obp obp[5]=
    {
    	{"Wimp Macho","Programator","Superman",0},
        {"Raki Rhodes","Tanar Programator","Batman",1},
        {"Celia Laiter","Tanara Programatoare","Batgirl",2},
        {"Hoppy Hipman","Analist Stagiar","Speedy",1},
        {"Pat Hand","Tanar Programator","Spiderman",2}
    };

    while (c!='i')
	{
    	switch (c)
        {
        	case 'a':
            {for (i=0;i<5;i++)
            	cout<<obp[i].nume<<"\n";}  break;
            case 'b':
            {for (i=0;i<5;i++)
            	cout<<obp[i].functie<<"\n";}  break;
            case 'c':
            {for (i=0;i<5;i++)
            	cout<<obp[i].poreclaOBP<<"\n";}  break;
            case 'd':
            {for (i=0;i<5;i++)
            {
            	a=obp[i].optiune;
                if (a==0)	cout<<obp[i].nume<<'\n';
                	else if (a==1)	cout<<obp[i].functie<<'\n';
                    	else cout<<obp[i].poreclaOBP<<'\n';
            }}	break;
        }
    	cout<<"\nUrmatoarea optiune: ";		cin>>c;
    }

    clock_t start=clock();
    while (clock()-start<f);
    return 0;
}



