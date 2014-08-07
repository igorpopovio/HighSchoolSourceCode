#include <iostream.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
  enum moneda {ban,stema};
  unsigned long n,i,k;
  moneda a;
  char c;

  cout<<"Introduceti \"t\" pentru terminare, iar \"s\" pentru simulare"<<endl;

  while(cin>>c && tolower(c)=='s') {
    cout<<"Introduceti numarul de simulari"<<endl;
    cout<<"n= ";    cin>>n;
    for(i=0,k=0;i<n;i++) {
      a=rand()%2;
      if(a==stema) k++;
    }
    cout<<"Stema a aparut de "<<k<<" ori, ceea ce da o frecventa relativa de ";
    cout.precision(10);  cout.width(20);     cout.setf(ios::left);
    cout<<(long double) k/n;
    cout<<"\nIntroduceti \"t\" pentru terminare, iar \"s\" pentru simulare"<<endl;
  }
}