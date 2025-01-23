#define _CRT_SECURE_NO_WARNINGS

#include "asmatu.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "random.h"
#include "string.h"
#include "text.h"

#define ZENBAKIAK1ETA100 "./img/1-100.bmp"

void jokoaAurkeztu(void)
{
    int ebentu = 0, irudia;

    textuaGaitu(35);

    pantailaGarbitu();
    textuaIdatzi(200, (100),
                 "Joko honetan 1etik 100erako zenbaki bat asmatu behar duzu eta horretarako 5 bizitza dituzu", 0xFF,
                 0xFF, 0xFF);
    irudia = irudiaKargatu(ZENBAKIAK1ETA100, 255);
    irudiaMugitu(irudia, 350, 180);
    irudiakMarraztu();
    pantailaBerriztu();

    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_RETURN);

    irudiaKendu(irudia);
    textuaDesgaitu();
}

int zaiatuAsmatzen(int zenbakiAleatorioa)
{

    int bizitza = 5, asmatuta = 0, ebentu = 0, jokalariarenzenbakia = 0;

    int currentX = centerX - 20;
    char bizitzak[10];

    textuaGaitu(40);

    pantailaGarbitu();
    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
    textuaIdatzi(centerX - 500, centerY - 580, "Sartu zenbakia:", 0xFF, 0xFF, 0xFF);
    pantailaBerriztu();

    while (bizitza > 0 && !asmatuta)
    {
        sprintf(bizitzak, "%d", bizitza);
        char pos[4] = {'\0'};
        do
        {

            ebentu = ebentuaJasoGertatuBada();
            if (ebentu >= TECLA_0 && ebentu <= TECLA_9)
            {
                char num = (char)(ebentu - TECLA_0 + '0');

                if (strlen(pos) < 3)
                {
                    if (strlen(pos) < 1 || pos[0] == '0')
                    {
                        pos[0] = '\0';
                        pantailaGarbitu();
                    }

                    size_t len = strlen(pos);
                    pos[len] = num;
                    pos[len + 1] = '\0';

                    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 500, centerY - 580, "Sartu zenbakia:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX + (len * 20), centerY - 300, pos + len, 0xFF, 0xFF, 0xFF);
                    pantailaBerriztu();
                }
            }
            else if (ebentu == TECLA_BACKSPACE)
            {
                size_t len = strlen(pos);
                if (len > 1)
                {
                    pos[len - 1] = '\0';
                    pantailaGarbitu();
                    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 500, centerY - 580, "Sartu zenbakia:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX, centerY - 300, pos, 0xFF, 0xFF, 0xFF);
                    pantailaBerriztu();
                }
                else
                {
                    pos[0] = '0';
                    pantailaGarbitu();
                    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 500, centerY - 580, "Sartu zenbakia:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX, centerY - 300, pos, 0xFF, 0xFF, 0xFF);
                    pantailaBerriztu();
                }
            }

            if (ebentu == TECLA_RETURN)
            {
                jokalariarenzenbakia = atoi(pos);

                if (jokalariarenzenbakia >= 1 && jokalariarenzenbakia <= 100)
                {

                    pantailaGarbitu();
                    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 500, centerY - 580, "Sartu zenbakia:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 100, centerY - 150, pos, 0xFF, 0xFF, 0xFF);
                }
                else
                {
                    // Mostrar un mensaje de error si el número es inválido
                    pantailaGarbitu();
                    textuaIdatzi(centerX - 500, centerY - 650, "Jokoan egiteko ", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 500, centerY - 580, "Berriro saiatu:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
                    textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
                    pos[0] = '\0';           // Reiniciar la entrada
                    currentX = centerX - 20; // Reiniciar la posición x
                }

                pantailaBerriztu();
            }

        } while (ebentu != TECLA_RETURN);
        if (jokalariarenzenbakia == zenbakiAleatorioa)
        {
            return asmatuta = 1;
        }
        if (jokalariarenzenbakia < zenbakiAleatorioa)
        {
            bizitza--;
            textuaIdatzi(centerX - 500, centerY - 100, "OKERRA, sartu duzun zenbakia baino altuagoa da.", 0xFF, 0xFF,
                         0xFF);
            textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
            textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
            pantailaBerriztu();
        }
        else if (jokalariarenzenbakia > zenbakiAleatorioa)
        {
            bizitza--;
            textuaIdatzi(centerX - 500, centerY - 100, "OKERRA, sartu duzun zenbakia baino baxuagoa da.", 0xFF, 0xFF,
                         0xFF);
            textuaIdatzi(centerX - 350, centerY - 450, "Honek dira dituzun bizitzak:", 0xFF, 0xFF, 0xFF);
            textuaIdatzi(centerX - 450, centerY - 450, bizitzak, 0xFF, 0xFF, 0xFF);
            pantailaBerriztu();
        }
    }

    return asmatuta;
}

int zenbakiaAsmatu(void)
{

    int zenbakiAleatorioa, asmatuta = 0, ebentu = 0;
    char ausazkoa[10];

    textuaGaitu(30);
    jokoaAurkeztu();
    zenbakiAleatorioa = random(100);
    asmatuta = zaiatuAsmatzen(zenbakiAleatorioa);
    sprintf(ausazkoa, "%d", zenbakiAleatorioa);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (asmatuta == 1)
        {
            pantailaGarbitu();
            textuaIdatzi(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2, "Zuzena! , irabazi egin duzu!!", 0xFF, 0xFF, 0xFF);
        }
        else
        {
            pantailaGarbitu();
            textuaIdatzi(SCREEN_WIDTH / 2 - 680, SCREEN_HEIGHT / 2,
                         "OOOOOOO! , Galdu egin duzu!, hau zen zenbakia:", 0xFF, 0xFF, 0xFF);
            textuaIdatzi(SCREEN_WIDTH / 2 + 300, SCREEN_HEIGHT / 2, ausazkoa, 0xFF, 0xFF, 0xFF);
        }
        pantailaBerriztu();
    } while (ebentu != TECLA_RETURN);

    textuaDesgaitu();

    return asmatuta;
}