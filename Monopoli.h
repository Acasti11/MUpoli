#ifndef MONOPOLI_H
#define MONOPOLI_H

#include "ebentoak.h"
#include "graphics.h"
#include "imagen.h"
#include "jokalariak.h"
#include "ourTypes.h"
#include "propietateak.h"
#include "random.h"
#include "soinua.h"
#include "string.h"
#include "text.h"

int jokalariKopuruaAukeratu();
void hasieratuJokalariaPos(JOKALARIAK *jokalariak);
void jokalariDatuak(JOKALARIAK *jokalariak);
void scoreboard(JOKALARIAK *jokalariak);
void propietateakIkusi(JOKALARIAK *jokalaria, PROPIETATEAK *propietateak);
JOKALARIAK *jokatu(JOKALARIAK *jokalaria);
#endif