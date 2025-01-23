#include "jokalariak.h"

JOKALARIAK *SortuNodoa(JOKALARIAK *head, int i)
{
    JOKALARIAK *nodo = (JOKALARIAK *)malloc(sizeof(JOKALARIAK)); // generar nuevo novo de la lista
    JOKALARIAK *tmp;
    nodo->dirua = 500;
    nodo->kasilla = 0;
    nodo->zenb = i;
    nodo->kartzela = 0;
    hasieratuArray(nodo->propietateak, 40);
    hasieratuP(nodo->propietateak);
    nodo->hurrengoa = NULL;
    if (head == NULL)
    {
        head = nodo;
    }
    else
    {
        tmp = head;
        while (tmp->hurrengoa != NULL)
        {
            tmp = tmp->hurrengoa;
        }
        tmp->hurrengoa = nodo;
    }

    return head;
}

void hasieratuP(int *propietateak)
{
    propietateak[0] = 16;
    propietateak[2] = 8;
    propietateak[4] = 13;
    propietateak[7] = 7;
    propietateak[10] = 14;
    propietateak[17] = 8;
    propietateak[20] = 16;
    propietateak[22] = 7;
    propietateak[30] = 15;
    propietateak[33] = 8;
    propietateak[36] = 7;
    propietateak[38] = 8;
}

void NodoakLiberau(JOKALARIAK *head)
{
    JOKALARIAK *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->hurrengoa;
        free(tmp);
    }
}

void hasieratuArray(int *array, int dim)
{
    int x;

    for (x = 0; x < dim; x++)
    {
        array[x] = 0;
    }
}

int kasiillaLibredago(JOKALARIAK **jokalaria, int x, JOKALARIAK *tmp)
{
    int emaitza = 0;

    while (*jokalaria != NULL && emaitza == 0) // vas mirando si ninguno de los jugadores posee la casilla
    {
        if ((*jokalaria)->propietateak[x] != 0 && (*jokalaria)->zenb != tmp->zenb)
        {
            emaitza = (*jokalaria)->propietateak[x];
        }
        if (emaitza == 0)
        {
            *jokalaria = (*jokalaria)->hurrengoa;
        }
    }

    return emaitza;
}
