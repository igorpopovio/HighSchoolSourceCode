#ifndef __VECTOR_H
#define __VECTOR_H

class Vector
{
private:
	double x;
    double y;
    double lungime;
    double unghi;
    char mod;
    void set_lung();
    void set_ung();
    void set_x();
    void set_y();
public:
	  Vector();
    Vector(double n1,double n2,char forma='c');
    void set(double n1,double n2,char forma='c');
    ~Vector();
    double valx() const		{return x;}
    double valy() const		{return y;}
    double vallung() const		{return lungime;}
    double valunghi() const		{return unghi;}
    void mod_polar();
    void mod_cartezian();
    Vector operator+(const Vector & v) const;
    Vector operator-(const Vector & v) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    friend Vector operator*(double n,const Vector & v);
    friend ostream & operator<<(ostream & os,const Vector & v);
};

#endif
