#ifndef _AGENDA_H_
#define _AGENDA_H_

struct agenda
{
char nume[20],prenume[20],telefon[15];
};

char meniu(void);
void deschide(void);
void creare(void);
void adauga(void);
void sterge(void);
void citeste(void);
#endif
