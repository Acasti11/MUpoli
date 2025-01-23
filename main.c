/*#include "orokorrak.h"
#include "bukaera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "sarrera.h"*/

//---------------------------------------------------------------------------------
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "jokalariak.h"
#include "propietateak.h"
#include "random.h"
#include "sarrera.h"
#include "sekuentzia.h"
#include "soinua.h"
#include "text.h"
//---------------------------------------------------------------------------------
#define kaixo "kaixooooooo"
#include <stdio.h>

#include "lib/Monopoli.h"
#include "ourTypes.h"

void menuaHasi()
{
    int menu = 1, ebentu = 0;
    int monopolyImgId, muImgId;
    JOKALARIAK *jokalariak = NULL;

    diseinuaDefinitu();

    while (menu)
    {

        diseinuaMarraztu();

        menu = botoiaKlikatu();
    }

    if (monopolyImgId != -1)
    {
        irudiaKendu(monopolyImgId);
    }

    if (muImgId != -1)
    {
        irudiaKendu(muImgId);
    }

    int zenbat, i = 0;
    zenbat = jokalariKopuruaAukeratu();

    for (i = 0; i < zenbat; i++)
    {
        jokalariak = SortuNodoa(jokalariak, i + 1);
    }
    jokalariak = jokatu(jokalariak);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        pantailaGarbitu();
        scoreboard(jokalariak);
        pantailaBerriztu();
    } while (ebentu != TECLA_RETURN);
    NodoakLiberau(jokalariak);
    sgItxi();
}

int main(int argc, char *str[])
{

    tiempoInicio = initializetime();

    if (sgHasieratu() == -1) // iniciar la ventana
    {
        fprintf(stderr, "Unable to set video: %s\n", SDL_GetError());
        return 1;
    }

    menuaHasi();

    sgItxi();
    return 0;
}
