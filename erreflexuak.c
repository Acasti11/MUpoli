#include "erreflexuak.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "random.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h> // Asegúrate de incluir esta línea
#include <time.h>

#define SARRERAKO_MEZUA "ONGI ETORRI ERREFLEXUEN JOKORA, SAKATU RETURN JOLASTEN HASTEKO"
#define AZALPENA "BI PERTSONEN ARTEKO LEHIA DA, PANTAILAN LETRA EDO ZENBAKI BAT PANTAILARATUKO DA"
#define AZALPENA2 "ZENBAKIA EDO TEKLA AZKARREN SAKATZEN DUENAK PUNTU BAT LORTUKO DU. 5 PUNTUTARA DA PARTIDA."
#define AZALPEN_GEHIAGO "LEHENENGO JOKALARIAK A, C, D, R, G LETRAK ETA 1, 3, 5 ZENBAKIAK ERABILIKO DITU."
#define AZALPEN_GEHIAGO2 "BIGARREN JOKALARIAK BERRIZ, K, L, N, B, Y LETRAK ETA 9, 7, 6 ZENBAKIAK."
#define BATZENBAKIA "./img/BATZENBAKIAbmp.bmp"
#define HIRUZENBAKIA "./img/3ZENBAKIAbmp.bmp"
#define BOSTZENBAKIA "./img/5ZENBAKIAbmp.bmp"
#define SEIZENBAKIA "./img/6ZENBAKIAbmp.bmp"
#define ZAZPIZENBAKIA "./img/7ZENBAKIAbmp.bmp"
#define BEDERATZIZENBAKIA "./img/9ZENBAKIAbmp.bmp"
#define ALETRA "./img/Aletrabmp.bmp"
#define BLETRA "./img/Bletrabmp.bmp"
#define CLETRA "./img/Cletrabmp.bmp"
#define DLETRA "./img/Dletrabmp.bmp"
#define GLETRA "./img/Gletrabmp.bmp"
#define KLETRA "./img/Kletrabmp.bmp"
#define LLETRA "./img/Lletrabmp.bmp"
#define NLETRA "./img/Nletrabmp.bmp"
#define RLETRA "./img/Rletrabmp.bmp"
#define YLETRA "./img/Yletrabmp.bmp"
#define BIGARREN_JOKALARIAK_WIN "BIGARREN JOKALARIAK IRABAZI DU"
#define BIGARRENAK_IRABAZI "./img/WINBIGARRENAK.bmp"
#define LEHENENGO_JOKALARIAK_WIN "LEHENENGO_JOKALARIAK_IRABAZI_DU"
#define LEHENAK_IRABAZI "./img/WINLEHENAK.bmp"
#define LEHENENGO_POS "LEHENENGO JOKALARIAK"
#define BIGARREN_POS "BIGARREN JOKALARIAK"
#define ERREFLEXUAK "./img/ERREFLEXUAKbmp.bmp"
#define BATABESTEA "./img/BATABESTEAbmp.bmp"
#define AZKARRA "./img/AZKARRAbmp.bmp"
#define LEHENENGOJOK "./img/LEHENENGOJOKbmp.bmp"
#define BIGARRENJOK "./img/BIGARRENJOKbmp.bmp"
#define TABLEROA "./img/monopoli_taula.bmp"

int erreflexuak(void)
{
    pantailaGarbitu();

    int jarraitu = 0;
    int lehenengoJokalariarenPuntoak = 0, bigarrenJokalariarenPuntoak = 0;
    int irabazlea = 0;
    int randomekoZenbakia = 0, aurrekoRandomZenb = 10;

    textuaGaitu(30);

    jokoaAurkeztuERR();
    aurkezpenaERR();
    aurkezpena2ERR();
    bigarrenAzalpenaERR();
    bigarrenAzalpena2ERR();

    while (lehenengoJokalariarenPuntoak < 5 && bigarrenJokalariarenPuntoak < 5)
    {
        randomekoZenbakia = random(8);

        do
        {
            randomekoZenbakia = random(8);
        } while (aurrekoRandomZenb == randomekoZenbakia);
        aurrekoRandomZenb = randomekoZenbakia;

        irabazlea =
            zenbakiakPantailaratuERR(lehenengoJokalariarenPuntoak, bigarrenJokalariarenPuntoak, randomekoZenbakia);

        if (irabazlea == 1)
        {
            lehenengoJokalariarenPuntoak++;
        }
        else if (irabazlea == 2)
        {
            bigarrenJokalariarenPuntoak++;
        }
    }
    if (lehenengoJokalariarenPuntoak > bigarrenJokalariarenPuntoak)
    {
        irabazlea = 1;
    }
    else
    {
        irabazlea = 2;
    }
    amaierakoPantailaERR(irabazlea);

    return irabazlea;
}

void jokoaAurkeztuERR(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, SCREEN_HEIGHT - 700, SARRERAKO_MEZUA, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(ERREFLEXUAK, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1300, SCREEN_HEIGHT - 550);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void aurkezpenaERR(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, SCREEN_HEIGHT - 700, AZALPENA, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(BATABESTEA, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1300, SCREEN_HEIGHT - 550);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void aurkezpena2ERR(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, SCREEN_HEIGHT - 700, AZALPENA2, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(AZKARRA, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1300, SCREEN_HEIGHT - 550);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void bigarrenAzalpenaERR(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, SCREEN_HEIGHT - 700, AZALPEN_GEHIAGO, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(LEHENENGOJOK, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1300, SCREEN_HEIGHT - 550);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void bigarrenAzalpena2ERR(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 600, SCREEN_HEIGHT - 700, AZALPEN_GEHIAGO2, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(BIGARRENJOK, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1300, SCREEN_HEIGHT - 550);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

int zenbakiakPantailaratuERR(int lehenengoJokPunt, int bigarrenJokPunt, int randomekoZenbakia)
{
    int ebentu = 0;
    int pantailetakoIrudia1, pantailetakoIrudia2;

    pantailaGarbitu();

    switch (randomekoZenbakia)
    {
    case 1:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(ALETRA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(BLETRA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;

    case 2:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(CLETRA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(ZAZPIZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 3:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(DLETRA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(SEIZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 4:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(BATZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(NLETRA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 5:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(HIRUZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(LLETRA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 6:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(GLETRA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(YLETRA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 7:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(BOSTZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(KLETRA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();
        break;
    case 8:
        textuaIdatzi((SCREEN_WIDTH / 2) - 600, (SCREEN_HEIGHT)-700,
                     "EA NORK EMATEN DION AZKARRAGO BERARI DAGOKION ZENBAKI EDO LETRARI", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 430, (SCREEN_HEIGHT)-500, LEHENENGO_POS, 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) + 230, (SCREEN_HEIGHT)-500, BIGARREN_POS, 0XFF, 0XFF, 0XFF);

        pantailetakoIrudia1 = irudiaKargatu(RLETRA, 255);
        irudiaMugitu(pantailetakoIrudia1, (SCREEN_WIDTH / 2) - 450, SCREEN_HEIGHT - 450);

        pantailetakoIrudia2 = irudiaKargatu(BEDERATZIZENBAKIA, 255);
        irudiaMugitu(pantailetakoIrudia2, (SCREEN_WIDTH / 2) + 200, SCREEN_HEIGHT - 450);

        irudiakMarraztu();
        pantailaBerriztu();

        irudiaKendu(pantailetakoIrudia1);
        irudiaKendu(pantailetakoIrudia2);

        pantailaBerriztu();

        break;

    default:

        break;
    }

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while ((randomekoZenbakia == 1 && ebentu != TECLA_a && ebentu != TECLA_b) ||
             (randomekoZenbakia == 2 && ebentu != TECLA_c && ebentu != TECLA_7) ||
             (randomekoZenbakia == 3 && ebentu != TECLA_d && ebentu != TECLA_6) ||
             (randomekoZenbakia == 4 && ebentu != TECLA_1 && ebentu != TECLA_n) ||
             (randomekoZenbakia == 5 && ebentu != TECLA_3 && ebentu != TECLA_l) ||
             (randomekoZenbakia == 6 && ebentu != TECLA_g && ebentu != TECLA_y) ||
             (randomekoZenbakia == 7 && ebentu != TECLA_5 && ebentu != TECLA_k) ||
             (randomekoZenbakia == 8 && ebentu != TECLA_r && ebentu != TECLA_9));

    switch (ebentu)
    {
    case TECLA_a:
    case TECLA_c:
    case TECLA_d:
    case TECLA_r:
    case TECLA_g:
    case TECLA_1:
    case TECLA_3:
    case TECLA_5:
        return 1;
    case TECLA_b:
    case TECLA_n:
    case TECLA_k:
    case TECLA_l:
    case TECLA_y:
    case TECLA_9:
    case TECLA_7:
    case TECLA_6:
        return 2;
    default:
        return 0;
    }
}

void amaierakoPantailaERR(int irabazlea)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();

    if (irabazlea == 1)
    {

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 300, LEHENENGO_JOKALARIAK_WIN, 0XFF, 0XFF, 0XFF);
        irudia = irudiaKargatu(LEHENAK_IRABAZI, 255);
        irudiaMugitu(irudia, SCREEN_WIDTH - 1200, SCREEN_HEIGHT - 500);
        irudiakMarraztu();
    }
    else
    {

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT / 2) - 300, BIGARREN_JOKALARIAK_WIN, 0XFF, 0XFF, 0XFF);
        irudia = irudiaKargatu(BIGARRENAK_IRABAZI, 255);
        irudiaMugitu(irudia, SCREEN_WIDTH - 1200, SCREEN_HEIGHT - 500);
        irudiakMarraztu();
    }
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}