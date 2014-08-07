#include <iostream.h>
#include <conio.h>

double serie ( double * a, unsigned n );
double paralel ( double * a, unsigned n );
double stea_triunghi ( double a, double b, double c );
double triunghi_stea( double a, double b, double c );
void grup_serie ( );
void grup_paralel ( );
void grup_stea_triunghi ( );
void grup_triunghi_stea ( );

void grup_serie ( ) {
	int i,n;
	double *a;
	cout<<"GRUPAREA SERIE"<<endl;
	cout<<"Introduceti urmatoarele: "<<endl;
	cout<<"1. numarul de rezistoare: ";	cin>>n; a=new double [n];
	cout<<"2. rezistentele: r1= ";	cin>>a[0];

	for ( i=1; i<n; i++ ) {
		cout<<"                 r"<<(i+1)<<"= ";	cin>>a[i];
	}
	cout<<endl<<endl<<endl;
	cout<<"Rezistenta echivalenta a rezistoarelor introduse este:"<<endl<<"R= "<<serie(a,n);
	cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
	getch ( );
}

void grup_paralel ( ) {
	int i,n;
	double *a;
	cout<<"GRUPAREA PARALEL"<<endl;
	cout<<"Introduceti urmatoarele: "<<endl;
	cout<<"1. numarul de rezistoare: ";	cin>>n; a=new double [n];
	cout<<"2. rezistentele: r1= ";	cin>>a[0];

	for ( i=1; i<n; i++ ) {
	cout<<"                 r"<<(i+1)<<"= ";	cin>>a[i];
	}
	cout<<endl<<endl<<endl;
	cout<<"Rezistenta echivalenta a rezistoarelor introduse este:"<<endl<<"R= "<<paralel(a,n);
	cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
	getch ( );
}

void grup_stea_triunghi ( ) {
	int i;
	double a[3];
	cout<<"GRUPAREA STEA-->TRIUNGHI"<<endl;
	cout<<"Introduceti rezistentele: r1= ";	cin>>a[0];
	for ( i=1; i<3; i++ ) {
		cout<<"                          r"<<(i+1)<<"= ";	cin>>a[i];
}
	cout<<endl<<endl<<endl;
	cout<<"Rezistentele echivalente ale rezistoarelor introduse sunt:"<<endl<<"R12= "<<stea_triunghi(a[0],a[1],a[2])<<endl;
	cout<<"R13= "<<stea_triunghi(a[0],a[2],a[1])<<endl;
	cout<<"R23= "<<stea_triunghi(a[1],a[2],a[0])<<endl;
	cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
	getch ( );
}

void grup_triunghi_stea ( ) {
	int i;
	double a[3];
	cout<<"GRUPAREA TRIUNGHI-->STEA"<<endl;
	cout<<"Introduceti rezistentele: r1= ";	cin>>a[0];
	for ( i=1; i<3; i++ ) {
		cout<<"                          r"<<(i+1)<<"= ";	cin>>a[i];
	}
	cout<<endl<<endl<<endl;
	cout<<"Rezistentele echivalente ale rezistoarelor introduse sunt:"<<endl<<"R12= "<<triunghi_stea(a[0],a[1],a[2])<<endl;
	cout<<"R13= "<<triunghi_stea(a[0],a[2],a[1])<<endl;
	cout<<"R23= "<<triunghi_stea(a[1],a[2],a[0])<<endl;
	cout<<endl<<endl<<"Apasati orice tasta pentru a continua...";
	getch ( );
}

double serie ( double * a, unsigned n ) {
	int i;
	double re=0;
	for ( i=0; i<n; i++ )	re+=a[i];
	return re;
}

double paralel ( double * a, unsigned n ) {
	int i;
	double re=0;
	for ( i=0; i<n; i++ )	re+=1/a[i];
	re=1/re;
	return re;
}

double stea_triunghi ( double a, double b, double c ) {
	return a+b+(a*b)/c;
}

double triunghi_stea ( double a, double b, double c ) {
	return a*b/(a+b+c);
}

int main ( ) {
	char a;
	int i=1;
	do {
		cout<<"REZISTENTA ECHIVALENTA"<<endl;
		cout<<"Alegeti pentru ce fel de grupare doriti sa calculati "
				<<"rezistenta echivalenta"<<endl;
		cout<<"1. serie"<<endl
				<<"2. paralel"<<endl
    		<<"3. triunghi-->stea"<<endl
    		<<"4. stea-->triunghi"<<endl;
		cout<<"Optiunea dumneavoastra: ";	cin>>a;
		clrscr ( );
		switch ( a ) {
			case '1': grup_serie(); break;
			case '2': grup_paralel(); break;
			case '3': grup_triunghi_stea(); break;
			case '4': grup_stea_triunghi(); break;
			default: break;
		}
		i++;     clrscr ( );
	} while ( i<=10 );
	return 0;
}

