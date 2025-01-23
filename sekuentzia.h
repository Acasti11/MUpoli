#ifndef SEKUENTZIA_H
#define SEKUENTZIA_H

#include "ourTypes.h"

#define MAX_LUZERA 10

typedef struct
{
    int luzera;
    int zenbakiak[MAX_LUZERA];
} Sekuentzia;

void sekuentziaJokoaAurkeztu(void);
void sekuentziaErakutsi(Sekuentzia *seq);
int erantzunaKonprobatu(Sekuentzia *seq);
int sekuentziaJokatu(void);

#endif