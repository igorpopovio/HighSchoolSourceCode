#include <iostream.h>
#include <conio.h>
void main()
{float a,t1,t2,v0,v,d,d0;
cout<<"Miscarea accelerata. Introduceti valorile cerute in Sistemul International, iar programul va afisa distanta parcursa de mobil si viteza la un moment dat!"<<endl;
cout<<"Distanta parcursa initial de mobil este de: ";	cin>>d0;
cout<<"Viteza initiala a mobilului este de: ";	cin>>v0;
cout<<"Timpul in care se incepe cronometrarea este de: ";	cin>>t1;
cout<<"Timpul in care se termina cronometrarea este de: ";	cin>>t2;
cout<<"Acceleratia mobilului este de: ";	cin>>a;
clrscr();
d=d0+v0*(t2-t1)+(a*(t2-t1)*(t2-t1))/2;
v=v0+a*(t2-t1);
cout<<"Distanta parcursa de mobil este de: "<<d<<" metri. "<<endl;
cout<<"Viteza la care a ajuns mobilul este de: "<<v<<" metri pe secunda. ";
getch();}
