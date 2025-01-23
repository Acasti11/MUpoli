#define _CRT_SECURE_NO_WARNINGS
#include "propietateak.h"
#include "asmatu.h"
#include "erreflexuak.h"
#include "galdetegia.h"
#include "graphics.h"
#include "harriorriar.h"
#include "imagen.h"
#include "random.h"
#include "sekuentzia.h"
#include "text.h"

#define Tablero "./img/monopoli_taula.bmp"

int fhasieratu(PROPIETATEAK *propietateak)
{

    FILE *file;
    file = fopen("..\\simpleSdlWrapper\\pruebak.txt", "r");
    if (file == NULL)
    {
        printf("Errorea eman du.\n");
        return 1;
    }

    firakurri(file, propietateak);
    fclose(file);

    return 0;
}

void firakurri(FILE *file, PROPIETATEAK *propietateak)
{
    int id = 0;
    char str[50];
    strcpy(str, "0\0");
    while (str[0] != '\n')
    {
        fgets(str, 50, file);
        sscanf(str, "%d %d %d %d\n", &propietateak[id].prezioa, &propietateak[id].ordaintzekoa,
               &propietateak[id].kampamentoTxiki_prezioa, &propietateak[id].kampamentoHandi_prezioa);

        id++;
    }
}

void zerrendaPantailaratu(PROPIETATEAK *propietateak, int dim)
{
    int id;

    for (id = 0; id < dim; id++)
    {
        printf("%d %d %d %d\n", propietateak[id].prezioa, propietateak[id].ordaintzekoa,
               propietateak[id].kampamentoTxiki_prezioa, propietateak[id].kampamentoHandi_prezioa);
    }
}

void erosiPropietateak(PROPIETATEAK *propietateak, JOKALARIAK *jokalariak, JOKALARIAK *fitxak)
{
    int ebentu;
    int egoera = 0;
    POSIZIOA saguPos;
    textuaGaitu(60);
    do
    {
        saguPos = saguarenPosizioa();
        ebentu = ebentuaJasoGertatuBada();
        pantailaGarbitu();
        textuaDesgaitu();
        ongEnKontextoa(jokalariak->kasilla);
        textuaGaitu(60);

        colorB = 0xff;
        colorR = 0x00;
        colorG = 0x00;
        zuzenaMarraztu(1400, 500, 300, 100);
        colorB = 0x00;
        colorR = 0xff;
        colorG = 0x00;
        zuzenaMarraztu(1400, 700, 300, 100);

        if (saguPos.x < 1700 && saguPos.x > 1400 && saguPos.y < 600 && saguPos.y > 500)
        {
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                if (jokalariak->dirua > propietateak[jokalariak->kasilla].prezioa)
                {

                    jokalariak->dirua -= propietateak[jokalariak->kasilla].prezioa;
                    jokalariak->propietateak[jokalariak->kasilla] = 1;
                    egoera = 1;
                }
            }
            textuaIdatzi(1450, 530, "EROSI", 128, 128, 128);
        }
        else
        {
            textuaIdatzi(1450, 530, "EROSI", 0xff, 0xff, 0xff);
        }
        if (saguPos.x < 1700 && saguPos.x > 1400 && saguPos.y < 800 && saguPos.y > 700)
        {
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                egoera = 1;
            }
            textuaIdatzi(1450, 730, "Aurrera", 128, 128, 128);
        }
        else
        {
            textuaIdatzi(1450, 730, "Aurrera", 0xff, 0xff, 0xff);
        }
        irudiakMarraztu();
        fitxakMarraztu(fitxak);
        pantailaBerriztu();

    } while (egoera == 0);
    textuaDesgaitu();
}

void KasillaEgoeraKudeatu(JOKALARIAK *jokalariak, PROPIETATEAK *propietateak, JOKALARIAK *tmp, int daduak,
                          int tableroid)
{
    int egoera;
    JOKALARIAK *fitxak = jokalariak;
    char str[256];
    int kont = 0, emaitza;
    egoera = kasiillaLibredago(&jokalariak, tmp->kasilla, tmp);
    switch (egoera)
    {
    case 0: // libre
        erosiPropietateak(propietateak, tmp, fitxak);
        break;
    case 1: // nivel basico

        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();

        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 2: // etxe batekin
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa * 5;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa * 5;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 3: // bi etxekin
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa * 15;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa * 15;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 4: // hiru etxekin
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa * 45;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa * 45;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 5: // lau etxekin
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa * 67, 5;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa * 67, 5;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 6: // hotela
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        jokalariak->dirua += propietateak[tmp->kasilla].ordaintzekoa * 91, 125;
        tmp->dirua -= propietateak[tmp->kasilla].ordaintzekoa * 91, 125;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
        // galdera
    case 7:
        int irabazi = 0;

        irudiaKendu(tableroid);
        pantailaBerriztu();
        pantailaGarbitu();

        irabazi = ongriBuruzGaldetegia();
        textuaDesgaitu();
        pantailaGarbitu();
        pantailaBerriztu();

        tableroid = irudiaKargatu(Tablero, 255);
        irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
        irudiakMarraztu();
        pantailaBerriztu();

        break;
    case 8: // minijokoa

        irabazi = 0;
        int zeJoko = 0;

        zeJoko = random(4);

        irudiaKendu(tableroid);
        pantailaBerriztu();
        pantailaGarbitu();

        switch (zeJoko)
        {
        case 1:

            irabazi = zenbakiaAsmatu();
            textuaDesgaitu();
            pantailaBerriztu();
            if (irabazi == 1)
            {
                tmp->dirua += 100;
            }
            break;
        case 2:

            irabazi = harriOrriAr();
            textuaDesgaitu();
            pantailaBerriztu();

            tableroid = irudiaKargatu(Tablero, 255);
            irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
            irudiakMarraztu();
            pantailaBerriztu();
            if (irabazi == 1)
            {
                tmp->dirua += 100;
            }
            break;
        case 3:

            irabazi = erreflexuak();
            textuaDesgaitu();
            pantailaBerriztu();
            if (irabazi == 1)
            {
                tmp->dirua += 100;
            }

            break;
        case 4:

            irabazi = sekuentziaJokatu();
            textuaDesgaitu();
            pantailaBerriztu();
            if (irabazi == 1)
            {
                tmp->dirua += 100;
            }
            break;
        default:
            break;
        }
        tableroid = irudiaKargatu(Tablero, 255);
        irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
        irudiakMarraztu();
        pantailaBerriztu();
        break;
    case 9: // trena
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Ordaintzeko dirua= %d", propietateak[tmp->kasilla].ordaintzekoa);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        if (jokalariak->propietateak[5] == 9)
        {
            kont++;
        }
        if (jokalariak->propietateak[15] == 9)
        {
            kont++;
        }
        if (jokalariak->propietateak[25] == 9)
        {
            kont++;
        }
        if (jokalariak->propietateak[35] == 9)
        {
            kont++;
        }
        for (int x = 0; x < kont; x++)
        {
            emaitza = propietateak[tmp->kasilla].ordaintzekoa * 2;
        }
        jokalariak->dirua += emaitza;
        tmp->dirua -= emaitza;
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 10: // servicioak
        pantailaGarbitu();
        textuaGaitu(60);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        if (jokalariak->propietateak[12] == 10)
        {
            kont++;
        }
        if (jokalariak->propietateak[28] == 10)
        {
            kont++;
        }
        if (kont > 1)
        {
            emaitza = daduak * 10;
        }
        else
        {
            emaitza = daduak * 4;
        }
        jokalariak->dirua += emaitza;
        tmp->dirua -= emaitza;
        snprintf(str, 256, "Ordaintzeko dirua= %d", emaitza);
        textuaIdatzi(500, 200, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        pantailaGarbitu();
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
        textuaIdatzi(500, 500, str, 0xFF, 0xFF, 0xFF);
        snprintf(str, 256, "Jokalari%d-ren dirua = %d", tmp->zenb, tmp->dirua);
        textuaIdatzi(500, 700, str, 0xFF, 0xFF, 0xFF);
        pantailaBerriztu();
        SDL_Delay(5000);
        textuaDesgaitu();
        break;
    case 13:
        tmp->dirua -= 200;
        break;
    case 15: // policia
        tmp->kartzela = 1;
        break;
    case 16: // harri horri har
        irabazi = harriOrriAr();
        textuaDesgaitu();
        pantailaBerriztu();

        tableroid = irudiaKargatu(Tablero, 255);
        irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
        irudiakMarraztu();
        pantailaBerriztu();
        if (irabazi == 1)
        {
            tmp->dirua += 100;
        }
        break;
    default:
        break;
    }
}

void etxeenkudeaketa(PROPIETATEAK *propietateak, JOKALARIAK *jokalariak)
{
    int propietateakId;
    int x = 0, ebentua, egoera = 1, kendu = 0;
    POSIZIOA saguPos;
    char str[128];
    while (x < 40 && egoera != 2)
    {

        if (jokalariak->propietateak[x] >= 1 && jokalariak->propietateak[x] <= 4)
        {
            propietateakId = irudiaKargatu(propietateak[x].argazkia, 255);
            egoera = 0;
            kendu = 1;
        }
        while (egoera == 0)
        {
            pantailaGarbitu();
            irudiakMarraztu();
            saguPos = saguarenPosizioa();
            ebentua = ebentuaJasoGertatuBada();
            irudiaMugitu(propietateakId, SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 200);
            zuzenaMarraztu(150, 900, 330, 100);
            zuzenaMarraztu(800, 900, 330, 100);
            zuzenaMarraztu(1400, 900, 330, 100);

            if (saguPos.x > 150 && saguPos.x < 480 && saguPos.y > 900 && saguPos.y < 1000)
            {
                textuaGaitu(25);
                textuaIdatzi(170, 910, "kanpamendua handitu", 128, 128, 128);
                if (ebentua == SAGU_BOTOIA_EZKERRA && jokalariak->propietateak[x] < 4 &&
                    jokalariak->dirua > propietateak[x].kampamentoHandi_prezioa)
                {
                    jokalariak->propietateak[x]++;
                    if (jokalariak->propietateak[x] == 4)
                    {
                        jokalariak->dirua -= propietateak[x].kampamentoHandi_prezioa;
                    }
                    else
                    {
                        jokalariak->dirua -= propietateak[x].kampamentoTxiki_prezioa;
                    }
                }
                textuaDesgaitu();
            }
            else
            {
                textuaGaitu(25);
                textuaIdatzi(170, 910, "kanpamendua handitu", 0xFF, 0xFF, 0xFF);
                textuaDesgaitu();
            }
            if (saguPos.x > 1400 && saguPos.x < 1730 && saguPos.y > 900 && saguPos.y < 1000)
            {
                textuaGaitu(60);
                textuaIdatzi(1420, 910, "hurrengoa", 128, 128, 128);
                if (ebentua == SAGU_BOTOIA_EZKERRA)
                {
                    egoera = 1;
                }
                textuaDesgaitu();
            }
            else
            {
                textuaGaitu(60);
                textuaIdatzi(1420, 910, "hurrengoa", 0xFF, 0xFF, 0xFF);
                textuaDesgaitu();
            }
            if (saguPos.x > 800 && saguPos.x < 1130 && saguPos.y > 900 && saguPos.y < 1000)
            {
                textuaGaitu(60);
                textuaIdatzi(820, 910, "Atera", 128, 128, 128);
                if (ebentua == SAGU_BOTOIA_EZKERRA)
                {
                    egoera = 2;
                }
                textuaDesgaitu();
            }
            else
            {
                textuaGaitu(60);
                textuaIdatzi(820, 910, "Atera", 0xFF, 0xFF, 0xFF);
                textuaDesgaitu();
            }
            textuaGaitu(60);
            snprintf(str, 256, "Jokalari%d-ren dirua = %d", jokalariak->zenb, jokalariak->dirua);
            textuaIdatzi(100, 500, str, 0xFF, 0xFF, 0xFF);
            snprintf(str, 256, "kanpamendu nivela %d", jokalariak->propietateak[x]);
            textuaIdatzi(100, 700, str, 0xFF, 0xFF, 0xFF);
            pantailaBerriztu();
            textuaDesgaitu();
        }
        if (kendu == 1)
        {
            irudiaKendu(propietateakId);
            kendu = 0;
        }
        x++;
    }
}

void ongEnKontextoa(int kasilla)
{
    pantailaGarbitu();

    switch (kasilla)
    {
    case 1:

        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "THE CLIMATE GROUP", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(16);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Klima-ekintzaren lidergoa eta kolaborazioa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "sustatzen duen nazioarteko erakundea. Enpresak,", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "gobernuak eta erakundeak elkarlanean aritzea", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "bultzatzen du karbono isuriak murrizteko", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "eta energia garbiak sustatzeko.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 3:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "ENERGIA SIN FRONTERAS", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(16);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Energia garbi eta jasangarria eskaintzea", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300, "helburu duen erakundea, bereziki",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300, "herrialde garapen bidean. Energia",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "berriztagarriak eta efizientzia energetikoa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300,
                     "sustatzen ditu komunitate behartsuetan.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 6:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "MARINE CONSERVATION INSTITUTE", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(16);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Itsas-ingurumenaren ikerketa eta babesa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "sustatzen duen erakundea. Itsas-habitaten", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eta espezieen kontserbazioa bultzatzen ditu,", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "ikerketa zientifikoak eta politika aldaketak sustatuz.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 8:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "SEA SHEPHERD CONSERVATION SOCIETY",
                     0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Itsas-faunaren kontserbazioa eta babesa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300, "helburu duen erakundea. Itsas-legez",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "kanpoko jardueren aurka borrokatzen du eta ", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "itsas espezie mehatxatuen babesa sustatzen du.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 9:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "OCEAN CONSERVANCY", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300, "Itsaso eta ozeanoen babesa sustatzen",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "duen erakundea. Itsas-ingurumenaren kontserbazioa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "bultzatzen du, plastiko kutsaduraren aurkako", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "borrokan eta itsas-biodibertsitatearen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "babesaren alde lan egiten du.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 11:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "THE CLIMATE REALITY PROJECT", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Klima aldaketaren inguruko kontzientziazioa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300, "eta ekintza sustatzen duen erakundea.",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Hitzaldiak, prestakuntza programak eta kanpainak", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "garatzen ditu, klima ekintzaren", 0xff,
                     0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300,
                     "aldeko jarrera eta jarduerak sustatzeko.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 13:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "350.ORG", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300, "Klima aldaketaren aurka borrokatzeko",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "mugimendu globala. Kontzientziazio kanpainak", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eta ekintza zuzenak antolatzen ditu, karbono", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "isuriak murrizteko eta energia berriztagarriak sustatzeko.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 14:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "GREENPEACE", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Ingurumenaren babesa eta aldaketa klimatikoaren", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "aurka borrokatzen duen nazioarteko erakundea.", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Ekintza zuzenak eta kanpaina publikoak egiten", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "ditu ingurumen-inpaktu negatiboak",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300,
                     "salatzeko eta politika aldaketak sustatzeko.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 16:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "AGUACONSULT", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Saneamendu eta ur-hornidura proiektuak", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "garatzen eta aholkatzen dituen erakundea. Ur-horniduraren", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "kalitatea eta irisgarritasuna hobetzeko", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "irtenbideak eskaintzen ditu.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 18:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300,
                     "INTERNATIONAL WATER MANAGEMENT INSTITUTE (IWMI)", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Ur-baliabideen kudeaketa hobetzea helburu", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "duen ikerketa-erakundea. Nekazaritzarako", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eta komunitate garapenerako ur-politikak", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "eta teknologiak garatzen ditu.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 19:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "WATERAID", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300, "Ur garbia eta saneamendu zerbitzuak",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "eskaintzea helburu duen erakundea. Ur-horniduraren", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eta higiene-praktiken hobekuntza sustatzen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "ditu mundu osoko komunitate behartsuetan.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 21:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "TEACH FOR ALL", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Hezkuntza berdintasuna eta kalitatea sustatzea", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "helburu duen nazioarteko sare bat. Irakasleen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "prestakuntza eta garapena bultzatzen ditu,", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "ume guztiek kalitatezko hezkuntza",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "eskuratzeko aukera izan dezaten.",
                     0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 23:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "ROOM TO READ", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Hezkuntza eta alfabetatze programak garatzen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300, "dituen erakundea, bereziki nesken",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "hezkuntza sustatzeko. Eskolak eraikitzen ditu,", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "liburuak banatzen ditu eta irakasleen",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "prestakuntza eskaintzen du.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 24:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "UNICEF", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300, "Umeen eskubideak babesten eta haien",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "ongizatea hobetzen diharduen Nazio Batuen agentzia.", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Hezkuntza, osasun, elikadura eta babes", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "programak garatzen ditu mundu osoko umeentzat.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 26:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "PATH", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Osasun-berrikuntzak herrialde behartsuetara", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "eramaten dituen nazioarteko erakundea. Teknologia", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "berritzaileak eta osasun-programak garatzen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "ditu, gaixotasun prebentzioa eta tratamendua hobetzeko.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 27:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "CRUZ ROJA INTERNACIONAL", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Larrialdietan eta gatazketan laguntza humanitarioa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "ematen duen erakundea. Bizitza salbatzeko", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eta sufrimendua arintzeko lan egiten du, osasun", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "eta ongizate programak eskaintzen ditu", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300,
                     "eta eskubide humanitarioak defendatzen ditu.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 29:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "MEDICOS SIN FRONTERAS", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Larrialdietan eta gatazketan osasun-arreta", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "eskaintzen duen nazioarteko erakundea.", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Boluntario medikuek osatutako taldeek larrialdi", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "sanitarioei erantzuten diete eta",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "osasun-sistemak hobetzen dituzte.",
                     0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 31:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "HEIFER INTERNATIONAL", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Nekazaritza eta abeltzaintzaren bidez komunitate", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "behartsuei laguntza ematea helburu duen erakundea.", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Abereen eta nekazaritza-tresnen dohaintzak egiten ditu", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "eta trebakuntza eskaintzen du komunitate", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "horiek ekonomia jasangarria lortzeko.",
                     0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 32:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "WORLD FOOD PROGRAMME", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Nazio Batuen agentzia honek mundu osoko", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "goseari aurre egiteko laguntza humanitarioa", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "eskaintzen du. Gosearen aurka borrokatzeko eta", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "elikadura-segurtasuna bermatzeko",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "programa ugari garatzen ditu.", 0xff,
                     0xff, 0xff);
        textuaDesgaitu();
        break;
    case 34:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "ACTION AGAINST HUNGER", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Gosearen aurkako borroka eta malnutrizioaren", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "prebentzioan espezializatutako erakundea.", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "Ur-hornidura eta saneamendu proiektuak garatzen ditu", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300,
                     "eta larrialdietan nutrizio-programak eskaintzen ditu.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 37:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "OXFAM INTERNATIONAL", 0xff, 0xff,
                     0xff);
        textuaDesgaitu();
        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Pobrezia eta injustizia sozialaren aurka borrokatzen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "duen erakunde globala. Proiektuak garatzen ditu", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "garapenerako, larrialdi-laguntza eskaintzen", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "programak garatzen ditu \neta haurren",
                     0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300,
                     "sustatzen ditu herrialde ezberdinetan.", 0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    case 39:
        textuaGaitu(25);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 700 - 300, "SAVE THE CHILDREN", 0xff, 0xff, 0xff);
        textuaDesgaitu();

        textuaGaitu(13);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 650 - 300,
                     "Nazioarteko erakunde hau umeen eskubideak defendatzea", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 620 - 300,
                     "helburu duen ongizate-erakundea da. Larrialdietan", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 590 - 300,
                     "laguntza humanitarioa eskaintzen du, hezkuntza", 0xff, 0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 560 - 300, "du, eta politika-aldaketak", 0xff,
                     0xff, 0xff);
        textuaIdatzi((SCREEN_WIDTH / 2) - 600 - 300, SCREEN_HEIGHT - 530 - 300, "babeserako ekimenak sustatzen ditu.",
                     0xff, 0xff, 0xff);
        textuaDesgaitu();
        break;
    default:
        break;
    }
}