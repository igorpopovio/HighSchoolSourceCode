#include <stdlib.h>   //rand()
#include <iostream.h> //  I/O operations
#include <ctype.h>   //tolower()
#include <conio.h>   //clrscr()

int simulare();
int y=0;
signed long b=0;
void atribuie(signed long f);

void main()
{
int a[3];
char c;
signed long s,i,n,e=0;

cout<<"\nPentru a simula apasati tasta \"s\", iar pentru a termina tasta \"t\"\n";
cout<<"\noptiune: ";

while(cin>>c && tolower(c)=='s')
{


s=2000;
clrscr();
cout<<"Suma de start este: "<<s<<endl;
cout<<"\nIntroduceti numarul de simulari\n";
cout<<"simulari: ";  cin>>n;
cout<<"\nIntroduceti suma pe care doriti sa o depasiti\n";
cout<<"suma: "; cin>>e;

for(i=0;i<n && s>0;i++)
{

if(s>=e) atribuie(i);

a[0]=simulare();
a[1]=simulare();
a[2]=simulare();
if(a[0]==0||a[1]==0||a[2]==0) s-=100;
else if(a[0]==a[1]==a[2]==1) s+=1000;
else if(a[0]==a[1]==a[2]==2) s+=5000;
else if(a[0]==a[1]==a[2]==3) s+=50000;
else s+=200;


}   //for

if(!s) cout<<"\nAti pierdut toti banii!";
else
{
cout<<"\nSuma finala este de: $";
cout.width(15);
cout<<s<<endl;

cout.setf(ios::fixed|ios::showpoint);   cout.precision(3);
cout<<"\nMedia sumei castigate\n   pe simulare este: $";
cout.width(15);
cout<<(double(s-2000)/n);
cout.unsetf(ios::fixed|ios::showpoint);   cout.precision(0);
if(b) cout<<"\nAu fost necesare "<<b<<" simulari pentru a depasi suma introdusa!";
    else cout<<"\nSuma introdusa nu a putut fi depasita!";
}  //if...else

cout<<"\n\nPentru a simula apasati tasta \"s\", iar pentru a termina tasta \"t\"\n";

cout<<"\noptiune: ";
::b=0;

}   //while
cin.get();

}      //void main()

int simulare()
{
return (rand()%4);
}

void atribuie(signed long f)
{

if(!::y) {::b=f; y=1;}

}
