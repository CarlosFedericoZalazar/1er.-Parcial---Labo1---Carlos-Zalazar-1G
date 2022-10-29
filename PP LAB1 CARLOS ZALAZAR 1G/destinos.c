#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "validar.h"
#include "viajes.h"
#include <string.h>

int inicializarDestino(eDestino unDestino[], int tam)
{
    int todoOk = 0;

    if(unDestino != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            unDestino[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodeoDestino(eDestino destino[], int tam, int* pId, int cantidad)
{
    int todoOk=0;

    eDestino AuxDestino[30] =
    {
        {0,"Calafate", 22250},
        {0,"Bariloche",103000},
        {0,"Salta", 84400},
        {0,"Mendoza", 95600}
    };

    if(destino!=NULL && tam>0 && cantidad<tam && pId!=NULL)
    {



        for(int i=0; i<cantidad; i++)
        {
            AuxDestino[i].id = *pId;
            AuxDestino[i].isEmpty=0;
            destino[i] = AuxDestino[i];
            (*pId)++;

        }
      todoOk=1;
    }
      return todoOk;
}

int listarDestinos(eDestino destino[], int tam)
{
    int todoOk = 0;
    if(destino != NULL && tam > 0)
    {
        system("cls");
        printf("\n            ***** LISTA DE VIAJES *****\n");
        printf("\n****************************************************\n\n");
        printf(" ID DEST.   DESTINO        PRECIO\n");

        for (int i = 0; i < tam; i++)
        {
            if(!destino[i].isEmpty)
            {
                printf("  %d    %-12s %10.2f\n", destino[i].id, destino[i].descripcion, destino[i].precio);
            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int funcionBuscarDestino(int idDestino, eDestino destino[], int sizeDestino, char nombreDestino[])
{
    int todoOk=0;

    if(destino!=NULL && sizeDestino>0)
    {

        for(int i=0; i<sizeDestino; i++)
        {
            if(destino[i].id == idDestino)
            {
                strcpy(nombreDestino, destino[i].descripcion);
            }
        }
    todoOk=1;
    }
    return todoOk;
}

// HARCODEO ARRAY VIAJES






