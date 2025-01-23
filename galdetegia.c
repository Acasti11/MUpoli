#include "galdetegia.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "soinua.h"
#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SARRERAKO_MEZUA "ONGI ETORRI ONG-EN INGURUKO GALDETEGIRA, SAKATU RETURN HASTEKO"
#define AZALPENA "GALDERA BAKARRA PANTAILARATUKO DA, ETA HONEN AUKERA DESBERDINAK"
#define AZALPEN_GEHIAGO "EGIN BEHARREKO GAUZA HURRENGOA DA, AUKERA ZUZENA AUKERATZEA IRABAZTEKO"
#define JOKALARIAK_IRABAZI "OSO ONDO!!! GALDERA ASMATU DUZU"
#define JOKALARIAK_GALDU "AUKERA OKERRA AUKERATU DUZU, HURRENGOAN IZANGO DA :)"
#define ONG_ARGAZKIA "./img/ONGbmp.bmp"
#define IRABAZI "./img/IRABAZIbmp.bmp"
#define GAIZKI "./img/GAIZKIbmp.bmp"
#define AUKERAK "./img/AZTERKETAbmp.bmp"
#define ONDOTXARTO "./img/ONDOTXARTObmp.bmp"
#define TABLEROA "./img/monopoli_taula.bmp"

int ongriBuruzGaldetegia(void)
{

    textuaGaitu(25);

    int ebentu = 0;
    int zuzena;
    int randomekoZenbakia;

    randomekoZenbakia = random(10);

    zuzena = galderaPantailaratuGAL(randomekoZenbakia);

    amaierakoPantailaGAL(zuzena);

    return zuzena;
}

void jokoaAurkeztuGAL(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 400, SCREEN_HEIGHT - 700, SARRERAKO_MEZUA, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(ONG_ARGAZKIA, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1150, SCREEN_HEIGHT - 500);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void aurkezpenaGAL(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 400, SCREEN_HEIGHT - 700, AZALPENA, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(AUKERAK, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1150, SCREEN_HEIGHT - 500);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

void bigarrenAzalpenaGAL(void)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();
    textuaIdatzi((SCREEN_WIDTH / 2) - 400, SCREEN_HEIGHT - 700, AZALPEN_GEHIAGO, 0XFF, 0XFF, 0XFF);

    irudia = irudiaKargatu(ONDOTXARTO, 255);
    irudiaMugitu(irudia, SCREEN_WIDTH - 1150, SCREEN_HEIGHT - 500);

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}

int galderaPantailaratuGAL(int randomekoZenbakia) // Nombre corregido
{
    int ebentu = 0;
    int erantzunZuzena;
    int aukeratua;
    int zuzena;

    pantailaGarbitu();

    jokoaAurkeztuGAL();

    aurkezpenaGAL();

    bigarrenAzalpenaGAL();

    pantailaGarbitu();
    switch (randomekoZenbakia)
    {

    case 1:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZER ESAN NAHI DUTE ONG SIGLAK?", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Antolaketa Nazional Gobernamentala", 0XFF, 0XFF,
                     0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Antolaketa Ez Gobernamentala", 0XFF, 0XFF,
                     0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Gobernuaren Ofizina Nazionala", 0XFF, 0XFF,
                     0XFF);
        break;

    case 2:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZEIN DA ONG BATEN HELBURU NAGUSIA?", 0XFF, 0XFF,
                     0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Irabazi ekonomikoak lortzea", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400,
                     "2. Zerbitzuak eskaintzea eta komunitateari laguntzea", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Gobernuaren baliabideak kudeatzea", 0XFF, 0XFF,
                     0XFF);
        break;

    case 3:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "NOLA FINANTZATZEN DIRA ONGak?", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Zerga bidez", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Gobernuen eta pertsona pribatuen dohainekin",
                     0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Produktuak saltzen", 0XFF, 0XFF, 0XFF);
        break;

    case 4:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZEINTZUN DIRA ONGen OHIZKO JARDUERAK?", 0XFF, 0XFF,
                     0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Luxuzko produktuak eskaintzea", 0XFF, 0XFF,
                     0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400,
                     "2. Larrialdi egoeretan dagoen pertsoneri laguntza ematea", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Aditu pertsonen ekintzak sustatzea", 0XFF, 0XFF,
                     0XFF);
        break;

    case 5:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZEINTZUK DIRA ONGak BABESTEN DITUZTEN KASUAK?",
                     0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Diruarekin lotutako kausak bakarrik", 0XFF,
                     0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400,
                     "2. Gizarte, ingurumen, osasun eta eskubideen kausak", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300,
                     "3. Herrialdeen barne politikarekin lotutako kausak", 0XFF, 0XFF, 0XFF);
        break;

    case 6:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700,
                     "ONG BERDIN BATEK HERRIALDE BATEN BAINO GEHIAGOTAN EGIN DEZAKE LAN", 0XFF, 0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500,
                     "1. Ez, bakarrik herrialde batean lan egin dezakete", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Bai, askotan nazioartean daude", 0XFF, 0XFF,
                     0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Ez, beti tokikoak izan behar dute", 0XFF, 0XFF,
                     0XFF);
        break;

    case 7:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZER DA BOLUNTARIO BAT IZATEA ONG BATEAN?", 0XFF,
                     0XFF, 0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Soldata jasotzen duen pertsona", 0XFF, 0XFF,
                     0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400,
                     "2. Bere borondatez lan egiten duen pertsona, kausarekin konprometituaz", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. ONGri dirua bakarrik dohaintzen diona", 0XFF,
                     0XFF, 0XFF);
        break;

    case 8:

        erantzunZuzena = 2;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ONGak IRABAZI EKONOMIKORIK BADAUKATE?", 0XFF, 0XFF,
                     0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Bai", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Ez", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. ONGaren arabera", 0XFF, 0XFF, 0XFF);
        break;

    case 9:

        erantzunZuzena = 1;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZEIN DA ONG OSPETSUA NAZIOARTEAN?", 0XFF, 0XFF,
                     0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500, "1. Greenpeace", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Amazon", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Walmart", 0XFF, 0XFF, 0XFF);
        break;

    case 10:

        erantzunZuzena = 1;

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-700, "ZERGATIK DIRA GARRANTZITSUAK ONGak?", 0XFF, 0XFF,
                     0XFF);

        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-500,
                     "1. Gobernuek edo enpresek ezin dituzten arazoak konpontzen laguntzen dute", 0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-400, "2. Herrialdeen legeak kudeatzeko arduradunak dira",
                     0XFF, 0XFF, 0XFF);
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, (SCREEN_HEIGHT)-300, "3. Langileen ongizatean soilik fokatzen dira",
                     0XFF, 0XFF, 0XFF);
        break;
    }

    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_1 && ebentu != TECLA_2 && ebentu != TECLA_3);

    switch (ebentu)
    {
    case TECLA_1:
        aukeratua = 1;
        break;
    case TECLA_2:
        aukeratua = 2;
        break;
    case TECLA_3:
        aukeratua = 3;
        break;
    }

    if (aukeratua == erantzunZuzena)
    {
        zuzena = 1;
    }
    else
    {
        zuzena = 0;
    }

    return zuzena;
}

void amaierakoPantailaGAL(int zuzena)
{
    int ebentu = 0;
    int irudia;

    pantailaGarbitu();

    if (zuzena == 1)
    {
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, SCREEN_HEIGHT - 700, JOKALARIAK_IRABAZI, 0XFF, 0XFF, 0XFF);

        irudia = irudiaKargatu(IRABAZI, 255);
        irudiaMugitu(irudia, SCREEN_WIDTH - 1250, SCREEN_HEIGHT - 500);
    }
    else
    {
        textuaIdatzi((SCREEN_WIDTH / 2) - 300, SCREEN_HEIGHT - 700, JOKALARIAK_GALDU, 0XFF, 0XFF, 0XFF);

        irudia = irudiaKargatu(GAIZKI, 255);
        irudiaMugitu(irudia, SCREEN_WIDTH - 1250, SCREEN_HEIGHT - 500);
    }

    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    pantailaBerriztu();
}