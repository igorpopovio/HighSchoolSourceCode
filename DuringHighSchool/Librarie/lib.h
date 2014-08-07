#ifndef __LIB_H
#define __LIB_H
class Lib
{
private:
	char nume[20];
    double pret;
public:
	Lib();
    Lib(const char * p,double pr=0.0);
    ~Lib();
    void set_nume(const char * p);
    void set_pret(const double n);
    void citeste();	
    void arata();
};

#endif