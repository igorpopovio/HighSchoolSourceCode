#include <iostream.h>
#include <conio.h>
#include <math.h>
void main()
{
struct punct
{
float x,y;
};
punct a,b,c;
float l1,l2,l3,p,s,sp;
int g=0;

//citim coordonatele varfurilor triunghiurilor
cout<<"coordonatele primului punct - x= ";	cin>>a.x;	gotoxy(29,2);
cout<<"- y= ";	cin>>a.y;
cout<<"coordonatele celui de-al doilea punct - x= ";	cin>>b.x;	gotoxy(39,4);
cout<<"- y= ";	cin>>b.y;
cout<<"coordonatele celui de-al treilea punct - x= ";	cin>>c.x;	gotoxy(40,6);
cout<<"- y= ";	cin>>c.y;

//calculam lungimile laturilor
l1=sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
l2=sqrt(pow((c.x-a.x),2)+pow((c.y-a.y),2));
l3=sqrt(pow((c.x-b.x),2)+pow((c.y-b.y),2));

if (!(l1<(l2+l3) || l2<(l1+l3) || l3<(l1+l2)))
{
cerr<<"coordonatele introduse nu pot fi varfurile unui triunghi!";
g=1;
}
if (!g)
{p=l1+l2+l3;		sp=p/2;
s=sqrt(sp*(sp-l1)*(sp-l2)*(sp-l3));
cout<<"perimetru= "<<p<<endl;
cout<<"suprafata= "<<s<<endl;
if (l1==l2==l3) cout<<"triunghi echilateral";
	else if (l1==l2 || l2==l3 || l1==l3) cout<<"triunghi isoscel";
if ((pow(l1,2)==pow(l2,2)+pow(l3,2))||(pow(l2,2)==pow(l1,2)+pow(l3,2))||(pow(l3,2)==pow(l2,2)+pow(l1,2)))
cout<<"triunghi dreptunghic";
}
getch();}


