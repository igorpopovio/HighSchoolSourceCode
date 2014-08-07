#include <iostream.h>
#include <ctype.h>

void main()
{
  unsigned n,a,b,c,d;
  char z;

  cout<<"Introduceti \"t\" pentru terminare, iar \"s\" pentru simulare\n";

  while(cin>>z && tolower(z)=='s'){
    cout<<"Introduceti a cata cifra din urmatoarea serie de numere"
        <<"\nnaturale doriti sa o vedeti:\n"
        <<"123456789101112131415161718192021 ...\n"
        <<"n= ";
    cin>>n;

    for(b=1,a=0;a<=n;b++) {
      c=b;
      while(c!=0) {
        if(a>n) break;
        d=c%10;
        c/=10;
        a++;
      }
    }

  cout<<"A "<<n<<"-a cifra este "<<d<<". Ea face parte din numarul "<<(b-1)<<endl;
  cout<<"Introduceti \"t\" pentru terminare, iar \"s\" pentru simulare\n";
  }

}

short cifre(unsigned  n)
{
  short k=0;

  while(n!=0) {
    n/=10;
    k++;
  }

  return k;
}
