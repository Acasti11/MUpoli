#ifndef RANMDOM_H
#define RANMDOM_H
#include "sdl_timer.h"
#include <stdio.h>
#include <time.h>
#define DADO1 "./img/dado1.bmp"
#define DADO2 "./img/dado2.bmp"
#define DADO3 "./img/dado3.bmp"
#define DADO4 "./img/dado4.bmp"
#define DADO5 "./img/dado5.bmp"
#define DADO6 "./img/dado6.bmp"
#define centerX (SCREEN_WIDTH / 2)
#define centerY (SCREEN_WIDTH / 2)

long initializetime(void);
long gettime(void);
int random(int num);
void botaBidaduak(int *dadu1, int *dadu2, int jokalariAukera);
void dadoakMugitu(int *dadu1, int *dadu2, int jokalariAukera);
long tiempoInicio;

#endif