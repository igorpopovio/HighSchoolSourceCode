#ifndef __COMPLEX_H_
#define __COMPLEX_H_

struct complex
{

float real;
float imaginar;

};
//------------------------------------------------------------------------------
//Prototipuri de functii
void suma();
void produs();
void afiseaza(complex &c);
void modul();
void conjugat();
void radical_ord2();
void afiseaza_rad(complex &c);
void citeste_vector(complex *c);
void citeste(complex &c);
char meniu();
double rad_in_grade(double &r);
double grade_in_rad(double &g);

#endif

