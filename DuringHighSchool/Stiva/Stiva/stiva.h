//stiva.h - - definitia clasei
#ifndef __STIVA_H
#define __STIVA_H
typedef unsigned long Element;

class Stiva
{
private:
	enum{Max=10};
    Element elemente[Max];
    int varf;
public:
	Stiva();
    bool evida() const;
    bool eplina() const;
    bool push(const Element & elem);
    bool pop(Element & elem);
};
#endif