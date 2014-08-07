#ifndef __CAPITAL_H
#define __CAPITAL_H
class Capital
{
private:
	char societate[30];
    int actiuni;
    double val_actiune;
    double val_totala;
    void stab_total()	{val_totala=actiuni * val_actiune;}
public:
	Capital();
    Capital(const char * sa,int n,double pr);
    ~Capital() {}
    void cumpara(int nr,double pret);
    void vinde(int nr,double pret);
    void actualizeaza(double pret);
    void arata() const;
    const Capital & valmax(const Capital &c) const;
};
#endif
