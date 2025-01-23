#define _CRT_SECURE_NO_WARNINGS
#include "harriorriar.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "propietateak.h"
#include "text.h"

#include <stdio.h>

#define ARTAZIAK_IMAGE "./img/ARTAZI-txikiabeltza.bmp"
#define HARRIA_IMAGE "./img/HARRIA-txikia.bmp"
#define PAPELA_IMAGE "./img/PAPEL-txikiabeltza.bmp"
#define LEHENENGO_JOKALARIA_TESTUA "LEHENENGO JOKALARIA"
#define BIGARREN_JOKALARIA_TESTUA "BIGARREN JOKALARIA"
#define SARRERAKO_TESTUA "HARRI-ORRI-AR JOKOA, SAKATU RETURN JOLASTEKO"
#define AUKERATU_BEHARREKO_TESTUA                                                                                      \
    "BIGARREN JOKALARIAN AUKERATU: 1-HARRIA, 2-ARTAZIA, 3-PAPELA. ONDOREN RETURN BOTOIA KLIKATU"
#define AUKERATU_BEHARREKO_TESTUA2                                                                                     \
    "LEHENENGO JOKALARIAK AUKERATU: Q-HARRIA, W-ARTAZIA, E-PAPELA. ONDOREN RETURN BOTOIA KLIKATU"
#define LEHENAK_IRABAZI "./img/WINLEHENAK.bmp"
#define BIGARRENAK_IRABAZI "./img/WINBIGARRENAK.bmp"
#define AUKERAKETAK "HEMEN DAGO BAKOITZAK AUKERATU DUEN OBJEKTUA"
#define LEHENENGO_POS "LEHENENGO JOKALARIAK"
#define BIGARREN_POS "BIGARREN JOKALARIAK"

int harriOrriAr(void)
{
    pantailaGarbitu();

    int jarraitu = 0, irabazlea;
    char lehenengoJokalariaHautaketa = 0;
    int bigarrenJokalariaHautaketa = 0;
    int lehenengoIrudia = 0, bigarrenIrudia = 0;
    int harriarenIrudia = 0, artaziarenIrudia = 0, papelarenIrudia = 0;
    int errepikatuDa = 0;

    textuaGaitu(30);

    jokoaAurkeztuAOH();
    while (lehenengoJokalariaHautaketa == bigarrenJokalariaHautaketa)
    {
        lehenengoJokalariaHautaketa =
            aukeraPosibleakAurkeztuLehenengoaAOH(harriarenIrudia, artaziarenIrudia, papelarenIrudia, errepikatuDa);
        bigarrenJokalariaHautaketa =
            aukeraPosibleakAurkeztuBigarrenaAOH(harriarenIrudia, artaziarenIrudia, papelarenIrudia, errepikatuDa);
        if (lehenengoJokalariaHautaketa == bigarrenJokalariaHautaketa)
        {
            errepikatuDa = 1;
            errepikatutaAOH();
        }
    }

    bakoitzakAukeratutakoaAOH(lehenengoJokalariaHautaketa, bigarrenJokalariaHautaketa, lehenengoIrudia, bigarrenIrudia,
                              harriarenIrudia, artaziarenIrudia, papelarenIrudia);

    irabazlea = harriOrriArIrabazleaAOH(lehenengoJokalariaHautaketa, bigarrenJokalariaHautaketa);

    amaierakoPantailaAOH(irabazlea, lehenengoIrudia, bigarrenIrudia);

    return irabazlea;
}

void jokoaAurkeztuAOH(void)
{
    int ebentu = 0;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT / 2) - 20, SARRERAKO_TESTUA, 0XFF, 0XFF, 0XFF);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
}

int aukeraPosibleakAurkeztuLehenengoaAOH(int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia,
                                         int errepikatuta)
{
    int ebentu = 0;

    if (errepikatuta == 1)
    {
        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
        pantailaGarbitu();
        pantailaBerriztu();
    }

    pantailaGarbitu();
    pantailaBerriztu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 700, (SCREEN_HEIGHT)-700, AUKERATU_BEHARREKO_TESTUA2, 0XFF, 0XFF, 0XFF);

    harriarenIrudia = irudiaKargatu(HARRIA_IMAGE, 255);
    irudiaMugitu(harriarenIrudia, (SCREEN_WIDTH - SCREEN_WIDTH) + 225, SCREEN_HEIGHT - 450);

    artaziarenIrudia = irudiaKargatu(ARTAZIAK_IMAGE, 255);
    irudiaMugitu(artaziarenIrudia, (SCREEN_WIDTH / 2) - 105, SCREEN_HEIGHT - 450);

    papelarenIrudia = irudiaKargatu(PAPELA_IMAGE, 255);
    irudiaMugitu(papelarenIrudia, SCREEN_WIDTH - 400, SCREEN_HEIGHT - 450);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_q && ebentu != TECLA_w && ebentu != TECLA_e);

    switch (ebentu)
    {
    case TECLA_q:
        return 1;
    case TECLA_w:
        return 2;
    case TECLA_e:
        return 3;
    default:
        return 0;
    }

    irudiaKendu(harriarenIrudia);
    irudiaKendu(artaziarenIrudia);
    irudiaKendu(papelarenIrudia);
    pantailaGarbitu();
    pantailaBerriztu();
}

int aukeraPosibleakAurkeztuBigarrenaAOH(int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia,
                                        int errepikatuta)
{
    int ebentu = 0;

    if (errepikatuta == 1)
    {
        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
        pantailaGarbitu();
        pantailaBerriztu();
    }

    pantailaGarbitu();
    pantailaBerriztu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 700, (SCREEN_HEIGHT)-700, AUKERATU_BEHARREKO_TESTUA, 0XFF, 0XFF, 0XFF);

    harriarenIrudia = irudiaKargatu(HARRIA_IMAGE, 255);
    irudiaMugitu(harriarenIrudia, (SCREEN_WIDTH - SCREEN_WIDTH) + 225, SCREEN_HEIGHT - 450);

    artaziarenIrudia = irudiaKargatu(ARTAZIAK_IMAGE, 255);
    irudiaMugitu(artaziarenIrudia, (SCREEN_WIDTH / 2) - 105, SCREEN_HEIGHT - 450);

    papelarenIrudia = irudiaKargatu(PAPELA_IMAGE, 255);
    irudiaMugitu(papelarenIrudia, SCREEN_WIDTH - 400, SCREEN_HEIGHT - 450);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_1 && ebentu != TECLA_2 && ebentu != TECLA_3);

    switch (ebentu)
    {
    case TECLA_1:
        return 1;
    case TECLA_2:
        return 2;
    case TECLA_3:
        return 3;
    default:
        return 0;
    }

    irudiaKendu(harriarenIrudia);
    irudiaKendu(artaziarenIrudia);
    irudiaKendu(papelarenIrudia);
    pantailaGarbitu();
    pantailaBerriztu();
}

void errepikatutaAOH(void)
{
    int ebentu = 0;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT / 2) - 20,
                 "OBJEKTU BERDINA AUKERATU DUZUTE, BERRIRO ERE OBJEKTU BAT AUKERATU BEHAR DUZUTE", 0XFF, 0XFF, 0XFF);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
}

int harriOrriArIrabazleaAOH(int lehenengoAukera, int bigarrenAukera)
{
    int irabazlea;

    if (lehenengoAukera == 1)
    {
        if (bigarrenAukera == 2)
        {
            irabazlea = 1;
        }
        else if (bigarrenAukera == 3)
        {
            irabazlea = 2;
        }
    }
    else if (lehenengoAukera == 2)
    {
        if (bigarrenAukera == 3)
        {
            irabazlea = 1;
        }
        else if (bigarrenAukera == 1)
        {
            irabazlea = 2;
        }
    }
    else if (lehenengoAukera == 3)
    {
        if (bigarrenAukera == 1)
        {
            irabazlea = 1;
        }
        else if (bigarrenAukera == 2)
        {
            irabazlea = 2;
        }
    }

    return irabazlea;
}

void bakoitzakAukeratutakoaAOH(int lehenengoAukera, int bigarrenAukera, int lehenengoIrudia, int bigarrenIrudia,
                               int harriarenIrudia, int artaziarenIrudia, int papelarenIrudia)
{
    int ebentu = 0;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700, AUKERAKETAK, 0XFF, 0XFF, 0XFF);
    textuaIdatzi((SCREEN_WIDTH / 2) - 480, (SCREEN_HEIGHT)-520, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
    textuaIdatzi((SCREEN_WIDTH / 2) + 280, (SCREEN_HEIGHT)-520, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

    if (lehenengoIrudia != 0)
    {
        irudiaKendu(lehenengoIrudia);
    }
    if (bigarrenIrudia != 0)
    {
        irudiaKendu(bigarrenIrudia);
    }

    if (lehenengoAukera == 1)
    {
        lehenengoIrudia = irudiaKargatu(HARRIA_IMAGE, 255);
        irudiaMugitu(lehenengoIrudia, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }
    else if (lehenengoAukera == 2)
    {
        lehenengoIrudia = irudiaKargatu(ARTAZIAK_IMAGE, 255);
        irudiaMugitu(lehenengoIrudia, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }
    else if (lehenengoAukera == 3)
    {
        lehenengoIrudia = irudiaKargatu(PAPELA_IMAGE, 255);
        irudiaMugitu(lehenengoIrudia, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }

    if (bigarrenAukera == 1)
    {
        bigarrenIrudia = irudiaKargatu(HARRIA_IMAGE, 255);
        irudiaMugitu(bigarrenIrudia, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }
    else if (bigarrenAukera == 2)
    {
        bigarrenIrudia = irudiaKargatu(ARTAZIAK_IMAGE, 255);
        irudiaMugitu(bigarrenIrudia, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }
    else if (bigarrenAukera == 3)
    {
        bigarrenIrudia = irudiaKargatu(PAPELA_IMAGE, 255);
        irudiaMugitu(bigarrenIrudia, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiaKendu(harriarenIrudia);
        irudiaKendu(artaziarenIrudia);
        irudiaKendu(papelarenIrudia);
    }

    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);
}

void amaierakoPantailaAOH(int irabazlea, int lehenengoIrudia, int bigarrenIrudia)
{
    int ebentu = 0;
    int lehenakIrabazi, bigarrenakIrabazi;

    pantailaGarbitu();
    pantailaBerriztu();

    if (irabazlea == 1)
    {
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 300, "LEHENENGO JOKALARIAK IRABAZI DU", 0XFF, 0XFF,
                     0XFF);
        lehenakIrabazi = irudiaKargatu(LEHENAK_IRABAZI, 255);
        irudiaMugitu(lehenakIrabazi, SCREEN_WIDTH - 1200, SCREEN_HEIGHT - 700);

        irudiaKendu(lehenengoIrudia);
        irudiaKendu(bigarrenIrudia);
    }

    if (irabazlea == 2)
    {
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 300, "BIGARREN JOKALARIAK IRABAZI DU", 0XFF, 0XFF,
                     0XFF);
        bigarrenakIrabazi = irudiaKargatu(BIGARRENAK_IRABAZI, 255);
        irudiaMugitu(bigarrenakIrabazi, SCREEN_WIDTH - 1200, SCREEN_HEIGHT - 700);

        irudiaKendu(lehenengoIrudia);
        irudiaKendu(bigarrenIrudia);
    }

    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(lehenakIrabazi);
    irudiaKendu(bigarrenakIrabazi);
    pantailaGarbitu();
    pantailaBerriztu();
}