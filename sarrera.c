#define _CRT_SECURE_NO_WARNINGS
#include "sarrera.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "text.h"
#include <stdio.h>

#define MONOPOLY_IMG "./img/monopoly2.bmp"
#define MU_IMG "./img/mondragon.bmp"
#define KREDITUAK "Kredituak: Ander, Paulo, Andoni eta Ahadu"
#define NOLA_JOKATU "Nola jokatu?"
#define TITULOA "Mupoli"
#define JOKOA_HASI "Hasi jolasten"

extern SDL_Rect startButtonRect;
extern SDL_Rect howToPlayButtonRect;

int monopolyImgId = -1, muImgId = -1;

SDL_Rect startButtonRect = {750, 300, 400, 80};
SDL_Rect howToPlayButtonRect = {750, 500, 400, 80};

void diseinuaDefinitu()
{
    monopolyImgId = irudiaKargatu(MONOPOLY_IMG, 255);
    muImgId = irudiaKargatu(MU_IMG, 255);

    if (monopolyImgId != -1)
    {
        irudiaMugitu(monopolyImgId, 275, 200);
    }
    else
    {
        printf("Error al cargar la imagen. %s\n", MONOPOLY_IMG);
    }

    if (muImgId != -1)
    {
        irudiaMugitu(muImgId, 1200, 200);
    }
    else
    {
        printf("Error al cargar la imagen. %s\n", MU_IMG);
    }
}

void diseinuaMarraztu()
{
    pantailaGarbitu();
    textuaGaitu(60);
    if (monopolyImgId != -1 && muImgId != -1)
    {
        irudiakMarraztu();
    }

    textuaIdatzi(850, 200, TITULOA, 0XFF, 0XFF, 0XFF);

    // Botoia 1
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 255, 255);
    SDL_RenderFillRect(getRenderer(), &startButtonRect);
    textuaIdatzi(750, 300, JOKOA_HASI, 0XFF, 0XFF, 0XFF);

    // Botoia 2
    SDL_SetRenderDrawColor(getRenderer(), 0, 0, 255, 255);
    SDL_RenderFillRect(getRenderer(), &howToPlayButtonRect);
    textuaIdatzi(750, 500, NOLA_JOKATU, 0XFF, 0XFF, 0XFF);

    // Kredituak
    textuaIdatzi(450, 700, KREDITUAK, 0xff, 0xff, 0xff);
    textuaDesgaitu();
    pantailaBerriztu();
}

void nolaJokatuPantaila()
{
    pantailaGarbitu();
    textuaGaitu(60);
    // Informazioa
    textuaIdatzi(275, 200, "Jokalari kopurua aukeratu (1etik 4ra)", 0XFF, 0XFF, 0XFF);
    textuaIdatzi(275, 300, "Monopoli antzeko joko batekin topatuko zara", 0XFF, 0XFF, 0XFF);
    textuaIdatzi(275, 400, "Baina desberdintasun txiki batzuk ditu...", 0XFF, 0XFF, 0XFF);
    textuaIdatzi(275, 500, "ONG desberdinei laguntzeko aukera izango duzu.", 0XFF, 0XFF, 0XFF);
    textuaIdatzi(275, 600, "Denon artean mundu hobeago bat lortuko dugu! ", 0XFF, 0XFF, 0XFF);
    textuaIdatzi(500, 700, "Sakatu RETURN bueltatzeko.", 0XFF, 0XFF, 0XFF);
    pantailaBerriztu();
    textuaDesgaitu();
    int ebentu = 0;
    while (ebentu != TECLA_RETURN)
    {
        ebentu = ebentuaJasoGertatuBada();
    }
}

int botoiaKlikatu()
{
    int menu = 1;

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            exit(0);
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            SDL_Point mousePos = {event.button.x, event.button.y};

            if (SDL_PointInRect(&mousePos, &startButtonRect))
            {
                menu = 0;
            }
            else if (SDL_PointInRect(&mousePos, &howToPlayButtonRect))
            {
                nolaJokatuPantaila();
                menu = 1;
            }
        }
    }

    return menu;
}
