#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <fstream.h>
#include <iomanip.h>
#define DIM 3
struct elev
    {
    char nume[20],prenume[20];
    unsigned n1,n2,n3,n4,n5,t;
    int media;
    };
float media (elev *p,int n);
void main()
{
    elev clasa[DIM];
    int t=0,i;
    char g;
    cout<<"Ce doriti sa faceti?\n1. introducerea unui catalog\n2. aranjarea elevilor in ordinea descrescatoare a mediilor\n\noptiune dumneavoastra este ";
    cin>>g;
    switch (g)
    {case '1':
    {for (i=0;i<DIM;i++)
    { cin.get();
    cout<<"Numele elevului: "; cin.get(clasa[i].nume,20);    cin.get();
    cout<<"Prenumele elevului: "; cin.get(clasa[i].prenume,20);   cin.get();
    cout<<"Nota 1: "; cin>>clasa[i].n1;
    cout<<"Nota 2: "; cin>>clasa[i].n2;
    cout<<"Nota 3: "; cin>>clasa[i].n3;
    cout<<"Nota 4: "; cin>>clasa[i].n4;
    cout<<"Nota 5: "; cin>>clasa[i].n5;
    clasa[i].media=media(clasa,i);
    }
    fstream f1 ("clasa.txt",ios::out);
    for (i=0;i<DIM;i++)
    f1<<resetiosflags(ios::skipws)<<clasa[i].nume<<" "<<clasa[i].prenume<<" "
      <<clasa[i].n1<<" "<<clasa[i].n2<<" "
      <<clasa[i].n3<<" "<<clasa[i].n4<<" "
      <<clasa[i].n5<<" "<<clasa[i].media<<endl;
	f1.close();
    }; break;
    case '2':
    {fstream f2 ("clasa.txt",ios::in);
    i=0;
    while (f2.get(clasa[i].nume,20))
    {
    f2.get();       cout<<clasa[i].nume;
    f2.get(clasa[i].prenume,20); f2.get();            cout<<clasa[i].prenume;
    f2>>resetiosflags(ios::skipws)>>clasa[i].n1;      cout<<clasa[i].n1;
    f2>>resetiosflags(ios::skipws)>>clasa[i].n2;      cout<<clasa[i].n2;
    f2>>resetiosflags(ios::skipws)>>clasa[i].n3;      cout<<clasa[i].n3;
    f2>>resetiosflags(ios::skipws)>>clasa[i].n4;      cout<<clasa[i].n4;
    f2>>resetiosflags(ios::skipws)>>clasa[i].n5;      cout<<clasa[i].n5;
    f2>>resetiosflags(ios::skipws)>>clasa[i].media;   cout<<clasa[i].media; i++;
    }
    while (!t)
    {
    t=1;
    for (i=0;i<DIM;i++)
    if (clasa[i].media<clasa[i+1].media)
	{char n[20];	strcpy(n,clasa[i].nume);
    char p[20];		strcpy(p,clasa[i].prenume);
    int a1=clasa[i].n1;
    int a2=clasa[i].n2;
	int a3=clasa[i].n3;
	int a4=clasa[i].n4;
	int a5=clasa[i].n5;
    float m=clasa[i].media;
    strcpy(clasa[i].nume,clasa[i+1].nume);
    strcpy(clasa[i].prenume,clasa[i+1].prenume);
    clasa[i].n1=clasa[i+1].n1;
    clasa[i].n2=clasa[i+1].n2;
	clasa[i].n3=clasa[i+1].n3;
    clasa[i].n4=clasa[i+1].n4;
    clasa[i].n5=clasa[i+1].n5;
    clasa[i].media=clasa[i+1].media;
    strcpy(clasa[i+1].nume,n);
    strcpy(clasa[i+1].prenume,p);
    clasa[i+1].n1=a1;
    clasa[i+1].n2=a2;
    clasa[i+1].n3=a3;
    clasa[i+1].n4=a4;
    clasa[i+1].n5=a5;
    t=0;
    }
    }
    f2.close();
    fstream f3 ("clasa.txt",ios::out);
    for (i=0;i<DIM;i++)
    f3<<clasa[i].nume<<" "<<clasa[i].prenume<<" "
      <<clasa[i].n1<<" "<<clasa[i].n2<<" "
      <<clasa[i].n3<<" "<<clasa[i].n4<<" "
      <<clasa[i].n5<<" "<<clasa[i].media;
	f3.close();
    }; break;
    default: cout<<"\nOptiune eronata!";
    }
    getch();
    }
    float media (elev *p,int n)
    {
    int s=0,k=0;
    int m;
    if (p[n].n1) {s+=p[n].n1; k++;};
    if (p[n].n2) {s+=p[n].n2; k++;};
    if (p[n].n3) {s+=p[n].n3; k++;};
    if (p[n].n4) {s+=p[n].n4; k++;};
    if (p[n].n5) {s+=p[n].n5; k++;};
    m=(3*s/k+p[n].t)/4;
    return m;
    }


