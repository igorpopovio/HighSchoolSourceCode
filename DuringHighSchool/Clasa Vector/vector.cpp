//vector.cpp - - metodele clasei Vector ("vector.h")
#include <iostream.h>
#include <math.h>
#include "vector.h"
const double Rad_in_grad=57.2957795130823;

void Vector::set_lung()
{
	lungime=sqrt(x*x+y*y);
}

void Vector::set_ung()
{
	if (x==0&&y==0)
    	unghi=0;
    else
    	unghi=atan2(y,x);
}

void Vector::set_x()
{
	x=lungime*cos(unghi);
}

void Vector::set_y()
{
	y=lungime*sin(unghi);
}

Vector::Vector()
{
	x=y=lungime=unghi=0;
    mod='c';
}

Vector::Vector(double n1,double n2,char forma)
{
	mod=forma;
    if (forma=='c')
    {
    	x=n1;
        y=n2;
        set_lung();
        set_ung();
    }
    else if (forma=='p')
    {
    	lungime=n1;
        unghi=n2;
        set_x();
        set_y();
    }
    else
    {
    	cout<<"Al treilea argument al Vector() este incorect - - "
        	<<"vectorul este setat la 0\n";
        x=y=lungime=unghi=0;
        mod='c';
    }
}

void Vector::set(double n1,double n2,char forma)
{
	mod=forma;
    if (forma=='c')
    {
    	x=n1;
        y=n2;
        set_lung();
        set_ung();
    }
    else if (forma=='p')
    {
    	lungime=n1;
        unghi=n2;
        set_x();
        set_y();
    }
    else
    {
    	cout<<"Al treilea argument al Vector() este incorect - - "
        	<<"vectorul este setat la 0\n";
        x=y=lungime=unghi=0;
        mod='c';
    }
}

Vector::~Vector()	{}

void Vector::mod_polar()
{
	mod='p';
}

void Vector::mod_cartezian()
{
	mod='c';
}

Vector Vector::operator+(const Vector & v) const
{
	return Vector(x+v.x,y+v.y);
}

Vector Vector::operator-(const Vector & v) const
{
	return Vector(x-v.x,y-v.y);
}

Vector Vector::operator-() const
{
	return Vector(-x,-y);
}

Vector Vector::operator*(double n) const
{
	return Vector(n*x,n*y);
}

Vector operator*(double n, const Vector & v)
{
	return v*n;
}

ostream & operator<<(ostream & os,const Vector & v)
{
	if(v.mod=='c')
    	os<<"(x,y) = ("<<v.x<<", "<<v.y<<")";
    else if (v.mod=='p')
    {
    	os<<"(l,u) = ("<<v.lungime<<", "
          <<v.unghi*Rad_in_grad<<")";
    }
    else
    	os<<"Modul obiectului Vector este incorect";
    return os;
}


