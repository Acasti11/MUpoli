// Esto con un incude de include
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define GRAPHICS

#include <SDL_ttf.h>

#include "graphics.h"
#include "imagen.h"

SDL_Window *window = NULL;
SDL_Renderer *gRenderer;

SDL_Renderer *getRenderer(void)
{
    return gRenderer;
}

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int sgHasieratu()
{
    int ret = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) // hasieratu sdl
    {
        fprintf(stderr, "Ezin SDL hasieratu: %s\n", SDL_GetError());
        return -1;
    }
    atexit(SDL_Quit);

    SDL_DisplayMode displayMode; // pantailaren  dimentzioak ateratzen ditu
    if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0)
    {
        fprintf(stderr, "Ezin pantailaren tamaina lortu: %s\n", SDL_GetError());
        return -1;
    }
    int screenWidth = displayMode.w;
    int screenHeight = displayMode.h;

    window = SDL_CreateWindow(
        "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight,
        SDL_WINDOW_FULLSCREEN_DESKTOP); // lehioa kreatzen du eta bariablekin adaptatzen da gure pantailara

    if (window == NULL)
    {
        fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
        return -1;
    }

    gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL)
    {
        fprintf(stderr, "Ezin renderizadorea sortu: %s\n", SDL_GetError());
        return -1;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL_RenderSetLogicalSize(gRenderer, SCREEN_WIDTH,
                             SCREEN_HEIGHT); // gure programan dauden medidak reajustatzen ditu edozein resoluziora

    if (TTF_Init() < 0)
    {
        fprintf(stderr, "Ezin TTF hasieratu: %s\n", TTF_GetError());
        return -1;
    }
    atexit(TTF_Quit);

    return ret;
}

void sgItxi()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void arkatzKoloreaEzarri(int red, int green, int blue)
{
    colorR = red;
    colorG = green;
    colorB = blue;
}

void zuzenaMarraztu(int x1, int y1, int luzera, int zabalera)
{
    SDL_Rect rect;
    rect.x = x1;
    rect.y = y1;
    rect.w = luzera;
    rect.h = zabalera;

    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(gRenderer, &rect);
}

void puntuaMarraztu(int x, int y)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(gRenderer, x, y);
}

void zirkuluaMarraztu(int x, int y, int r)
{

    int i, h;

    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    for (i = x - r; i <= x + r; i++)
    {
        h = (int)llround(sqrt((double)(r * r - (i - x) * (i - x))));
        SDL_RenderDrawLine(gRenderer, i, y + h, i, y - h);
    }
}

int irudiaMarraztu(SDL_Texture *texture, SDL_Rect *pDest)
{
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = pDest->w;
    src.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

void pantailaGarbitu()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
}

void pantailaBerriztu()
{
    SDL_RenderPresent(gRenderer);
}

void fitxakMarraztu(JOKALARIAK *jokalaria)
{
    int x = 0;
    while (jokalaria != NULL)
    {
        switch (x)
        {
        case 0:
            colorR = 0x00;
            colorG = 0x00;
            colorB = 0xFF;
            break;
        case 1:
            colorR = 0xFF;
            colorG = 0x00;
            colorB = 0x00;
            break;
        case 2:
            colorR = 0x00;
            colorG = 0xFF;
            colorB = 0x00;
            break;
        case 3:
            colorR = 0xFF;
            colorG = 0xFF;
            colorB = 0x00;
            break;

        default:
            break;
        }
        zirkuluaMarraztu(jokalaria->pos.x, jokalaria->pos.y, 10);
        jokalaria = jokalaria->hurrengoa;
        x++;
    }
}