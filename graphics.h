#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "jokalariak.h"
#include <SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int colorR, colorG, colorB;

int sgHasieratu();
void sgItxi(); // Sin opciones
void arkatzKoloreaEzarri(int red, int green, int blue);
void puntuaMarraztu(int x, int y);
void zuzenaMarraztu(int x1, int y1, int x2, int y2);
void zirkuluaMarraztu(int x, int y, int r);
void pantailaGarbitu();
void pantailaBerriztu();
void fitxakMarraztu(JOKALARIAK *jokalaria);

int irudiaMarraztu(SDL_Texture *texture, SDL_Rect *pDest);

SDL_Renderer *getRenderer(void);

#endif
