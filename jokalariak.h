#ifndef JOKALARIAK_H
#define JOKALARIAK_H

#include "ebentoak.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_jokalariak
{
    int dirua;
    int propietateak[40];
    int kasilla;
    POSIZIOA pos;
    int zenb;
    int kartzela;
    struct s_jokalariak *hurrengoa;
} JOKALARIAK;

JOKALARIAK *SortuNodoa(JOKALARIAK *head, int i);
void NodoakLiberau(JOKALARIAK *head);
void hasieratuArray(int *array, int dim);
int kasiillaLibredago(JOKALARIAK **jokalaria, int x, JOKALARIAK *tmp);
void hasieratuP(int *propietateak);

#endif