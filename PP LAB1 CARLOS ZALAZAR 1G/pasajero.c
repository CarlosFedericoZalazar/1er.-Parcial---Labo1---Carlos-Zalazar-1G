#include <stdio.h>
#include <stdlib.h>
#include "pasajero.h"

int inicializarPasajero(ePasajero pasajero[], int tam)
{
    int todoOk = 0;

    if(pasajero != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            pasajero[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int hardcodeoPasajeros(ePasajero pasajeros[], int tamPasajero, int* pId, int cantidad)
{
    int todoOk=0;

    ePasajero AuxPasajero[30] =
    {
        {0,"Carlos Zalazar", 'm',0,},
        {0,"Andrea Orzuza",'f',0,},
        {0,"Jazmin Alvarez",'f',0},
        {0,"Pepe Grillo", 'm',0}
    };

    if(pasajeros!=NULL && tamPasajero>0 && pId!=NULL)
    {

        for(int i=0; i<cantidad; i++)
        {
            AuxPasajero[i].id = *pId;
            AuxPasajero[i].isEmpty=0;
            pasajeros[i] = AuxPasajero[i];
            (*pId)++;

        }
      todoOk=1;
    }
      return todoOk;
}
