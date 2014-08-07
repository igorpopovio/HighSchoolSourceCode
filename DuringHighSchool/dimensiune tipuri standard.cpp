#include <iostream.h>
#include <fstream.h>

void main()
{

cout.setf(ios::left);

cout.width(20);  cout<<"tip";    cout.width(16); cout<<"dimensiune"<<endl;
                                 cout.width(20); cout<<" "; cout<<"(in octeti sau bytes)"<<endl;
cout.width(0);   cout<<"-------------------------------------------";
cout<<'\n';
cout.width(25);  cout<<"char";    cout.width(16); cout<<sizeof(char)<<endl;
cout.width(25);  cout<<"signed char";    cout.width(16); cout<<sizeof(signed char)<<endl;
cout.width(25);  cout<<"unsigned char";    cout.width(16); cout<<sizeof(unsigned char)<<endl;
cout.width(25);  cout<<"int";    cout.width(16); cout<<sizeof(int)<<endl;
cout.width(25);  cout<<"signed int";    cout.width(16); cout<<sizeof(signed int)<<endl;
cout.width(25);  cout<<"unsigned int";    cout.width(16); cout<<sizeof(unsigned int)<<endl;
cout.width(25);  cout<<"short int";    cout.width(16); cout<<sizeof(short int)<<endl;
cout.width(25);  cout<<"long int";    cout.width(16); cout<<sizeof(long int)<<endl;
cout.width(25);  cout<<"signed long int";    cout.width(16); cout<<sizeof(signed long int)<<endl;
cout.width(25);  cout<<"unsigned long int";    cout.width(16); cout<<sizeof(unsigned long int)<<endl;
cout.width(25);  cout<<"float";    cout.width(16); cout<<sizeof(float)<<endl;
cout.width(25);  cout<<"double";    cout.width(16); cout<<sizeof(double)<<endl;
cout.width(25);  cout<<"long double";    cout.width(16); cout<<sizeof(long double)<<endl;

fstream f("dimensiunile tipurilor standard.txt",ios::out);

f.setf(ios::left);

f.width(20);  f<<"tip";    f.width(16); f<<"dimensiune"<<endl;
                           f.width(20); f<<" "; f<<"(in octeti sau bytes)"<<endl;
f.width(0);   f<<"-------------------------------------------";
f<<'\n';
f.width(25);  f<<"char";    f.width(16); f<<sizeof(char)<<endl;
f.width(25);  f<<"signed char";    f.width(16); f<<sizeof(signed char)<<endl;
f.width(25);  f<<"unsigned char";    f.width(16); f<<sizeof(unsigned char)<<endl;
f.width(25);  f<<"int";    f.width(16); f<<sizeof(int)<<endl;
f.width(25);  f<<"signed int";    f.width(16); f<<sizeof(signed int)<<endl;
f.width(25);  f<<"unsigned int";    f.width(16); f<<sizeof(unsigned int)<<endl;
f.width(25);  f<<"short int";    f.width(16); f<<sizeof(short int)<<endl;
f.width(25);  f<<"long int";    f.width(16); f<<sizeof(long int)<<endl;
f.width(25);  f<<"signed long int";    f.width(16); f<<sizeof(signed long int)<<endl;
f.width(25);  f<<"unsigned long int";    f.width(16); f<<sizeof(unsigned long int)<<endl;
f.width(25);  f<<"float";    f.width(16); f<<sizeof(float)<<endl;
f.width(25);  f<<"double";    f.width(16); f<<sizeof(double)<<endl;
f.width(25);  f<<"long double";    f.width(16); f<<sizeof(long double)<<endl;

f.close();

cin.get();
cin.get();

}

