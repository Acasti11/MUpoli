#define _CRT_SECURE_NO_WARNINGS

#include "sekuentzia.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "random.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>

#define ONGI_ETORRI_MEZUA "Memoriaren jokoa\nSakatu RETURN jolasten hasteko..."
#define MAX_NUMBERS 9

void sekuentziaJokoaAurkeztu(void)
{
    int ebentu = 0;

    textuaGaitu(60);
    textuaIdatzi(100, 200, ONGI_ETORRI_MEZUA, 255, 255, 255);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
    pantailaGarbitu();
    pantailaBerriztu();
}

void sekuentziaErakutsi(Sekuentzia *seq)
{
    pantailaGarbitu();
    char numStr[10];
    for (int i = 0; i < seq->luzera; i++)
    {
        sprintf(numStr, "%d", seq->zenbakiak[i]);
        textuaIdatzi(250, 200, numStr, 255, 255, 255);
        pantailaBerriztu();
        SDL_Delay(500);
        pantailaGarbitu();
        pantailaBerriztu();
    }
}

int erantzunaKonprobatu(Sekuentzia *seq)
{
    int erantzuna[MAX_NUMBERS] = {0};
    int pos = 0, ebentu;
    char numStr[10] = "";

    pantailaGarbitu();
    textuaIdatzi(100, 200, "Sartu sekuentzia:", 255, 255, 255);
    pantailaBerriztu();

    while (pos < seq->luzera)
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu >= SDLK_1 && ebentu <= SDLK_9)
        {
            erantzuna[pos] = ebentu - SDLK_0;
            sprintf(numStr, "%d", erantzuna[pos]);
            textuaIdatzi(250 + pos * 40, 300, numStr, 255, 255, 255);
            pantailaBerriztu();
            pos++;
        }
    }

    for (int i = 0; i < seq->luzera; i++)
    {
        if (erantzuna[i] != seq->zenbakiak[i])
        {
            return 0;
        }
    }
    return 1;
}

int sekuentziaJokatu(void)
{
    Sekuentzia sekuentzia;
    sekuentzia.luzera = 1;
    int nivel = 1;

    sekuentziaJokoaAurkeztu();

    while (1 && nivel < sekuentzia.zenbakiak[MAX_LUZERA])
    {
        sekuentzia.zenbakiak[sekuentzia.luzera - 1] = random(9);
        sekuentziaErakutsi(&sekuentzia);

        if (erantzunaKonprobatu(&sekuentzia))
        {
            char msg[50];
            sprintf(msg, "Zuzena! %d. mailara pasatzen zera", nivel + 1);
            textuaIdatzi(100, 400, msg, 255, 255, 255);
            pantailaBerriztu();
            SDL_Delay(1500);
            sekuentzia.luzera++;
            nivel++;
        }
        else
        {
            char msg[50];
            sprintf(msg, "Okerra! Jokoaren amaiera. %d. mailara iritsi zera", nivel);
            textuaIdatzi(100, 400, msg, 255, 255, 255);
            pantailaBerriztu();
            SDL_Delay(3000);
            break;
        }
    }
    if (nivel == sekuentzia.zenbakiak[MAX_LUZERA])
    {
        return 1;
    }

    return 0;
}