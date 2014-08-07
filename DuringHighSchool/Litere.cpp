#include <iostream.h>
#include <conio.h>
void main()
{char c;
cout<<"caracterul=";	cin>>c;
cout<<(c>='a'&&c<='z'?(char)(c-32):(c>='A'&&c<='Z'?(char)(c+32):c));
getch();}
