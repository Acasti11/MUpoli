#ifndef PROPIETATEAK_H
#define PROPIETATEAK_H
// #define _CRT_SECURE_NO_WARNINGS

#include "jokalariak.h"
#include <stdio.h>
#include <string.h>

typedef struct s_propietateak
{
    int prezioa;
    int ordaintzekoa;
    int kampamentoTxiki_prezioa;
    int kampamentoHandi_prezioa;
    char argazkia[256];
} PROPIETATEAK;

int fhasieratu(PROPIETATEAK *propietateak);
void firakurri(FILE *file, PROPIETATEAK *propietateak);
void zerrendaPantailaratu(PROPIETATEAK *propietateak, int dim);
void erosiPropietateak(PROPIETATEAK *propietateak, JOKALARIAK *jokalariak, JOKALARIAK *fitxak);
void KasillaEgoeraKudeatu(JOKALARIAK *jokalariak, PROPIETATEAK *propietateak, JOKALARIAK *tmp, int daduak,
                          int tableroid);
void etxeenkudeaketa(PROPIETATEAK *propietateak, JOKALARIAK *jokalariak);
void ongEnKontextoa(int kasilla);
#endif