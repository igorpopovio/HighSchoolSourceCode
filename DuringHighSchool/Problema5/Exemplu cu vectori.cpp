#include <iostream>
#include <conio.h>


//urmatoarele header-e se folosesc fara ".h" :
  //iostream , string , fstream etc
//insa acestea se folosesc cu ".h" :
  //math.h , conio.h etc

//Observa urmatoarea linie (se foloseste intotdeauna cu iostream si fstream): 
using namespace std;

float suma ( float * vector, int n ) {   
  //daca vrei sa modifici vectorul in subprogram folosesti "float *& vector" cu &
  //sau daca vrei sa-l returnezi folosesti prototipul functiei
  // "float * suma ( float * vector, int n )"
  //si returnezi adresa primului element
  float s=0;
  for ( int i=0; i<n; i++ )
		s+=vector[i];
  return s;
} 

// exemplu de returnare a unui vector
float * alta_suma ( float * vector, int n ) {
  //adunam la fiecare componenta a vectorului  2
  for ( int i=0; i<n; i++ )
  	vector [ i ] = vector [ i ] + 2;
 	return vector;
}

int main ( ) {
  int n;
  float s, tablou[20];
  float * pointer;
  
  cout<<"Introduceti numarul de componente ale vectorului: ";	cin>>n;
  
  //citirea componentelor tabloului:
  for ( int i=0; i<n; i++ ) {
    cout<<"tablou["<<i<<"]= ";	cin>>tablou[i];
  }
  s=suma ( tablou, n );
  cout<<endl;
  
  cout<<"Suma elementelor din tablou este: "<<s<<endl;
  //se poate si direct:
    //cout<<"Suma elementelor din tablou este: "<<suma ( tablou, n ); 
  
  pointer=alta_suma ( tablou, n );
  
  cout<<"Acuma afisam componentele tabloului initial + 2 : "<<endl;
  //Observatie: "endl" inseamna endline si trece la o linie noua
  for ( int i=0; i<n; i++ ) 
  	cout<<pointer[i]<<"  ";
  
  getch ( );
  
  return 0;
}   
