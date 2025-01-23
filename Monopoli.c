#include "Monopoli.h"
#include "graphics.h"

#include <stdio.h>
#include <string.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define PROPIETATEA_1 "./img/1_Marron_1.bmp"
#define PROPIETATEA_2 "./img/3_Marron_2.bmp"
#define PROPIETATEA_3 "./img/6_AzulClaro_1.bmp"
#define PROPIETATEA_4 "./img/8_AzulClaro_2.bmp"
#define PROPIETATEA_5 "./img/9_AzulClaro_3.bmp"
#define PROPIETATEA_6 "./img/11_Morea_1.bmp"
#define PROPIETATEA_7 "./img/13_Morea_2.bmp"
#define PROPIETATEA_8 "./img/14_Morea_3.bmp"
#define PROPIETATEA_9 "./img/16_Laranja_1.bmp"
#define PROPIETATEA_10 "./img/18_Laranja_2.bmp"
#define PROPIETATEA_11 "./img/19_Laranja_3.bmp"
#define PROPIETATEA_12 "./img/21_Gorria_1.bmp"
#define PROPIETATEA_13 "./img/23_Gorria_2.bmp"
#define PROPIETATEA_14 "./img/24_Gorria_3.bmp"
#define PROPIETATEA_15 "./img/26_Horia_1.bmp"
#define PROPIETATEA_16 "./img/27_Horia_2.bmp"
#define PROPIETATEA_17 "./img/29_Horia_3.bmp"
#define PROPIETATEA_18 "./img/30_Berdea_1.bmp"
#define PROPIETATEA_19 "./img/31_Berdea_2.bmp"
#define PROPIETATEA_20 "./img/33_Berdea_3.bmp"
#define PROPIETATEA_21 "./img/36_Urdina_1.bmp"
#define PROPIETATEA_22 "./img/38_Urdina_2.bmp"
#define GRIFOA "./img/GRIFOA.bmp"
#define ARGIA "./img/ARGINDARRA.bmp"
#define Tablero "./img/monopoli_taula.bmp"
#define TRENA "./img/ONDO_INDAKO_TRENA.bmp"
#define BOTON_DOWN_0 "./img/boton_dowm_0.bmp"
#define BOTON_DOWN_1 "./img/boton_dowm_1.bmp"
#define BOTON_UP_0 "./img/boton_up_0.bmp"
#define BOTON_UP_1 "./img/boton_up_1.bmp"
#define PANEL "./img/Panel.bmp"
#define text "sakatu enter daduak botatzeko"

JOKALARIAK *jokatu(JOKALARIAK *jokalaria)
{
    JOKALARIAK *tmp;
    POSIZIOA saguPos;
    PROPIETATEAK propietateak[40] = {{0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_1},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_2},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_3},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_4},
                                     {0, 0, 0, 0, PROPIETATEA_5},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_6},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_7},
                                     {0, 0, 0, 0, PROPIETATEA_8},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_9},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_10},
                                     {0, 0, 0, 0, PROPIETATEA_11},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_12},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_13},
                                     {0, 0, 0, 0, PROPIETATEA_14},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_15},
                                     {0, 0, 0, 0, PROPIETATEA_16},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_17},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_18},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_19},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_20},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_21},
                                     {0, 0, 0, 0, ""},
                                     {0, 0, 0, 0, PROPIETATEA_22}};
    int tableroid;
    int jokalariAukera = 1, dadu1 = 0, dadu2 = 0, ebentu, actualizau = 0;
    tmp = jokalaria;
    tableroid = irudiaKargatu(Tablero, 255);
    fhasieratu(propietateak);
    irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
    hasieratuJokalariaPos(jokalaria);
    while (tmp->dirua >= 0) // hasta que alguien se quede sin dinero
    {

        pantailaGarbitu();
        saguPos = saguarenPosizioa();
        ebentu = ebentuaJasoGertatuBada();
        colorR = 0x00;
        colorG = 0x00;
        colorB = 0xFF;
        zuzenaMarraztu(180, 750, 300, 100);
        colorR = 0xFF;
        colorG = 0x00;
        colorB = 0x00;
        zuzenaMarraztu(1350, 750, 400, 100);
        if (actualizau == 1) // para iniciar la partida y q el primer turno juegue el jugador 1
        {

            if (tmp->hurrengoa == NULL) // para resetera el orden cuando llegue al final vuelva a jugar el jugador 1
            {
                tmp = jokalaria;
                jokalariAukera = 1;
            }
            else // pasar al siguiente jugador
            {
                tmp = tmp->hurrengoa;
                jokalariAukera++;
            }

            actualizau = 0;
        }
        jokalariDatuak(tmp);
        scoreboard(jokalaria);
        textuaGaitu(60);
        if (saguPos.x < 1750 && saguPos.x > 1350 && saguPos.y < 850 && saguPos.y > 750)
        {
            textuaIdatzi(1360, 760, "Propietateak", 128, 128, 128);
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                irudiaKendu(tableroid);
                textuaDesgaitu();
                propietateakIkusi(tmp, propietateak);
                textuaGaitu(60);
                tableroid = irudiaKargatu(Tablero, 255);
                irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
            }
        }
        else
        {
            textuaIdatzi(1360, 760, "Propietateak", 0xff, 0xff, 0xff);
        }

        if (saguPos.x > 180 && saguPos.x < 480 && saguPos.y > 750 && saguPos.y < 850) // daduak bota
        {
            textuaIdatzi(210, 780, "Daduak", 128, 128, 128);
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                irudiaKendu(tableroid);
                pantailaGarbitu();
                pantailaBerriztu();
                dadoakMugitu(&dadu1, &dadu2, jokalariAukera);
                pantailaGarbitu();
                actualizau = 1;
                tableroid = irudiaKargatu(Tablero, 255);
                irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
                irudiakMarraztu();
                textuaDesgaitu();
                jokalariDatuak(tmp);
                scoreboard(jokalaria);
                fitxakMarraztu(jokalaria);
                textuaGaitu(60);
                pantailaBerriztu();
                if (tmp->kartzela == 0 || dadu1 == dadu2)
                {
                    for (int x = 0; x < dadu1 + dadu2; x++)
                    {

                        tmp->kartzela = 0;
                        SDL_Delay(500);
                        pantailaGarbitu();
                        tmp->kasilla++;
                        // sumar los dados a la posicion del jugador
                        if (tmp->kasilla >= 41) // una vuelta entera al tablero
                        {
                            tmp->kasilla -= 40;
                            tmp->dirua += 200;
                        }

                        if (tmp->kasilla <= 9) // en que direccion mover las fichas
                        {
                            tmp->pos.x -= 71;
                        }
                        else if (tmp->kasilla <= 10)
                        {

                            tmp->pos.x -= 120;
                        }
                        else if (tmp->kasilla <= 20)
                        {
                            tmp->pos.y -= 60;
                        }
                        else if (tmp->kasilla <= 21)
                        {
                            tmp->pos.x += 120;
                        }
                        else if (tmp->kasilla <= 30)
                        {

                            tmp->pos.x += 71;
                        }
                        else if (tmp->kasilla <= 39)
                        {
                            tmp->pos.y += 60;
                        }
                        else
                        {
                            // tmp->pos.x -= 120;
                            tmp->pos.y += 60;
                        }

                        irudiakMarraztu();
                        fitxakMarraztu(jokalaria);
                        pantailaBerriztu();
                    }
                }
                else
                {
                    tmp->kartzela++;
                    if (tmp->kartzela >= 3)
                    {
                        tmp->dirua -= 50;
                    }
                }
                KasillaEgoeraKudeatu(jokalaria, propietateak, tmp, dadu1 + dadu2, tableroid);
            }
        }
        else
        {
            textuaIdatzi(210, 780, "Daduak", 0xFF, 0xFF, 0xFF);
        }

        zuzenaMarraztu(800, 900, 300, 100);

        if (saguPos.x > 800 && saguPos.x < 1100 && saguPos.y > 900 && saguPos.y < 1000)
        {
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                textuaDesgaitu();
                irudiaKendu(tableroid);
                etxeenkudeaketa(propietateak, tmp);
                tableroid = irudiaKargatu(Tablero, 255);
                irudiaMugitu(tableroid, SCREEN_WIDTH / 2 - 500, 120);
                textuaGaitu(60);
            }
            textuaIdatzi(820, 910, "Kudeatu", 128, 128, 128);
        }
        else
        {
            textuaIdatzi(820, 910, "Kudeatu", 0xFF, 0xFF, 0xFF);
        }

        irudiakMarraztu();
        fitxakMarraztu(jokalaria);
        pantailaBerriztu();
        textuaDesgaitu();
    }
    irudiaKendu(tableroid);
    return jokalaria;
}

int jokalariKopuruaAukeratu()
{
    int Id[3];
    int zenbat = 2;
    char zenb[5];
    POSIZIOA saguPos;
    int egoera = 0;

    while (egoera != TECLA_RETURN && zenb != 0)
    {
        saguPos = saguarenPosizioa();
        egoera = ebentuaJasoGertatuBada();
        pantailaGarbitu();
        textuaGaitu(60);
        if (saguPos.x > 650 && saguPos.x < 850 && saguPos.y > 650 && saguPos.y < 850)
        {
            Id[0] = irudiaKargatu(BOTON_DOWN_1, 255);
            if (egoera == SAGU_BOTOIA_EZKERRA && zenbat > 2)
            {
                zenbat--;
            }
        }
        else
        {
            Id[0] = irudiaKargatu(BOTON_DOWN_0, 255);
        }
        if (saguPos.x > 650 && saguPos.x < 850 && saguPos.y > 100 && saguPos.y < 350)
        {
            Id[1] = irudiaKargatu(BOTON_UP_1, 255);
            if (egoera == SAGU_BOTOIA_EZKERRA && zenbat < 4)
            {
                zenbat++;
            }
        }
        else
        {
            Id[1] = irudiaKargatu(BOTON_UP_0, 255);
        }
        Id[2] = irudiaKargatu(PANEL, 255);

        irudiaMugitu(Id[0], 600, 600);
        irudiaMugitu(Id[1], 600, 100);
        irudiaMugitu(Id[2], 0, 0);
        zenb[0] = zenbat + '0';
        zenb[1] = '\0';
        irudiakMarraztu();
        textuaIdatzi((SCREEN_WIDTH / 2), SCREEN_HEIGHT / 2 - 150, "AUKERATU JOKALARI KANTITATEA", 0xFF, 0xFF, 0xFF);
        textuaIdatzi((SCREEN_WIDTH / 2), SCREEN_HEIGHT / 2, "SAKATU ENTER AUKERATZEKO", 0xFF, 0xFF, 0xFF);
        textuaIdatzi(480, 480, zenb, 0x00, 0x00, 0x00);

        pantailaBerriztu();
        irudiaKendu(Id[0]);
        irudiaKendu(Id[1]);
        irudiaKendu(Id[2]);
    }
    textuaDesgaitu();
    return zenbat;
}

void hasieratuJokalariaPos(JOKALARIAK *jokalariak)
{
    int x = 0, y = 0;
    while (jokalariak != NULL)
    {
        if (x == 2)
        {
            y = 1;
            x = 0;
        }
        if (y == 2)
        {
            y = 0;
            x = 1;
        }
        jokalariak->pos.x = 1250 + x * 30;
        jokalariak->pos.y = 780 + y * 30;
        jokalariak = jokalariak->hurrengoa;
        x++;
        y++;
    }
}

void jokalariDatuak(JOKALARIAK *jokalariak)
{
    char str[256];
    textuaGaitu(30);
    snprintf(str, 256, "dirua = %d", jokalariak->dirua);
    textuaIdatzi(230, 250, str, 0xFF, 0xFF, 0xFF);

    snprintf(str, 256, "Kasilla=%d", jokalariak->kasilla);
    textuaIdatzi(230, 300, str, 0xFF, 0xFF, 0xFF);

    snprintf(str, 256, "Jokalari%d", jokalariak->zenb);
    textuaIdatzi(230, 200, str, 0xFF, 0xFF, 0xFF);
    textuaDesgaitu();
}

void scoreboard(JOKALARIAK *jokalariak)
{
    char str[256];
    JOKALARIAK scoreboard[4], tmp;
    int x = 0, y = 0;
    textuaGaitu(60);
    textuaIdatzi(1380, 150, "SAILKAPENA", 0xFF, 0xFF, 0xFF);
    textuaDesgaitu();
    textuaGaitu(30);

    while (jokalariak != NULL)
    {
        scoreboard[x] = *jokalariak;
        y = 0;
        while (scoreboard[x - y - 1].dirua < scoreboard[x - y].dirua && (x - y - 1) >= 0)
        {
            tmp = scoreboard[x - y - 1];
            scoreboard[x - y - 1] = scoreboard[x - y];
            scoreboard[x - y] = tmp;
            y++;
        }
        jokalariak = jokalariak->hurrengoa;
        x++;
    }
    x--;
    while (x >= 0)
    {
        snprintf(str, 256, " jokalaria%d = %d", scoreboard[x].zenb, scoreboard[x].dirua);
        textuaIdatzi(1400, 300 + x * 100, str, 0xFF, 0xFF, 0xFF);

        snprintf(str, 256, "%d.", x + 1);
        textuaIdatzi(1380, 300 + x * 100, str, 0xFF, 0xFF, 0xFF);
        x--;
    }
    textuaDesgaitu();
}

void propietateakIkusi(JOKALARIAK *jokalaria, PROPIETATEAK *propietateak)
{
    int propietateakId[22];
    int ebentu;
    POSIZIOA saguPos;
    const char *propietateakStr[28] = {
        PROPIETATEA_1,  PROPIETATEA_2,  PROPIETATEA_3,  PROPIETATEA_4,  PROPIETATEA_5,  PROPIETATEA_6,  PROPIETATEA_7,
        PROPIETATEA_8,  PROPIETATEA_9,  PROPIETATEA_10, PROPIETATEA_11, PROPIETATEA_12, PROPIETATEA_13, PROPIETATEA_14,
        PROPIETATEA_15, PROPIETATEA_16, PROPIETATEA_17, PROPIETATEA_18, PROPIETATEA_19, PROPIETATEA_20, PROPIETATEA_21,
        PROPIETATEA_22, ARGIA,          GRIFOA,         TRENA,          TRENA,          TRENA,          TRENA};
    int position[28] = {1,  3,  6,  8,  9,  11, 13, 14, 16, 18, 19, 21, 23, 24,
                        26, 27, 29, 31, 32, 34, 37, 39, 12, 28, 5,  15, 25, 35};
    int rows = 6;    // Número de filas en la pantalla
    int cols = 6;    // Número de columnas en la pantalla (ajustado a 22 imágenes)
    int margin = 10; // Espacio entre imágenes
    int imageWidth = (SCREEN_WIDTH - (cols + 1) * margin) / cols;   // Ancho ajustado por columna
    int imageHeight = (SCREEN_HEIGHT - (rows + 1) * margin) / rows; // Alto ajustado por fila

    int index = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols && index < 28; col++)
        {
            // Calcula las coordenadas de cada imagen
            int x = margin + col * (imageWidth + margin);
            int y = margin + row * (imageHeight + margin);

            // Carga la imagen
            if (jokalaria->propietateak[position[index]] >= 1)
            {
                propietateakId[index] = irudiaKargatu(propietateakStr[index], 255);
            }
            else
            {
                propietateakId[index] = irudiaKargatu(propietateakStr[index], 128);
            }
            if (propietateakId[index] != -1)
            {
                // Mueve la imagen a la posición calculada
                irudiaMugitu(propietateakId[index], x, y);
            }
            index++;
        }
    }
    int egoera = 0;
    textuaGaitu(60);
    do
    {
        saguPos = saguarenPosizioa();
        ebentu = ebentuaJasoGertatuBada();

        pantailaGarbitu();
        zuzenaMarraztu(1600, 1000, 300, 100);
        if (saguPos.x > 1600 && saguPos.x < 1900 && saguPos.y > 1000 && saguPos.y < 1100)
        {
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                egoera = 1;
            }
            textuaIdatzi(1620, 1010, "atera", 128, 128, 128);
        }
        else
        {
            textuaIdatzi(1620, 1010, "atera", 0xFF, 0xFF, 0xFF);
        }

        irudiakMarraztu();
        pantailaBerriztu();

    } while (egoera != 1);

    while (index != 0)
    {
        irudiaKendu(propietateakId[index]);
        index--;
    }
    textuaDesgaitu();
}
