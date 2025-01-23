#include "random.h"
#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "text.h"
#define text "press enter daduak botatzeko"

long initializetime(void)
{
    tiempoInicio = (long)clock();

    return tiempoInicio;
}
long gettime(void)
{
    return (long)clock() - tiempoInicio;
}
int random(int num)
{
    long tiempo_transcurrido;
    long long randomnum = 0;
    tiempo_transcurrido = gettime();
    randomnum = (tiempo_transcurrido) % num + 1;

    return (int)randomnum;
}
void botaBidaduak(int *dadu1, int *dadu2, int jokalariAukera)
{
    *dadu1 = random(6);
    SDL_Delay(100);
    *dadu2 = random(6);
}
void dadoakMugitu(int *dadu1, int *dadu2, int jokalariAukera)
{
    char *argazkiak[6] = {DADO1, DADO2, DADO3, DADO4, DADO5, DADO6};
    int irudiak[6], ebentu = 0;
    textuaGaitu(60);
    pantailaGarbitu();
    do
    {

        int i = 0;
        ebentu = ebentuaJasoGertatuBada();
        while (i < 6 && ebentu != TECLA_RETURN)
        {
            ebentu = ebentuaJasoGertatuBada();
            pantailaGarbitu();
            textuaIdatzi(centerX - 450, centerY - 800, text, 0xFF, 0xFF, 0xFF);
            irudiak[i] = irudiaKargatu(argazkiak[i], 255);
            irudiaMugitu(irudiak[i], centerX - 600, centerY - 600);
            irudiakMarraztu();
            pantailaBerriztu();

            irudiak[i] = irudiaKargatu(argazkiak[i], 255);
            irudiaMugitu(irudiak[i], centerX - 100, centerY - 600);
            irudiakMarraztu();
            pantailaBerriztu();
            SDL_Delay(180);
            irudiaKendu(irudiak[i]);
            i++;
            irudiaKendu(irudiak[i]);
            pantailaBerriztu();
        }

    } while (ebentu != TECLA_RETURN);

    botaBidaduak(dadu1, dadu2, jokalariAukera);
    ebentu = 0;

    do
    {
        ebentu = ebentuaJasoGertatuBada();

        pantailaGarbitu();
        textuaIdatzi(centerX - 450, centerY - 800, text, 0xFF, 0xFF, 0xFF);
        irudiak[*dadu1 - 1] = irudiaKargatu(argazkiak[*dadu1 - 1], 255);
        irudiaMugitu(irudiak[*dadu1 - 1], centerX - 600, centerY - 600);
        irudiakMarraztu();
        pantailaBerriztu();

        irudiak[*dadu2 - 1] = irudiaKargatu(argazkiak[*dadu2 - 1], 255);
        irudiaMugitu(irudiak[*dadu2 - 1], centerX - 100, centerY - 600);
        irudiakMarraztu();
        pantailaBerriztu();
        SDL_Delay(250);

        irudiaKendu(irudiak[*dadu2 - 1]);
        irudiaKendu(irudiak[*dadu1 - 1]);
        pantailaBerriztu();
    } while (ebentu != TECLA_RETURN);
    textuaDesgaitu();
}