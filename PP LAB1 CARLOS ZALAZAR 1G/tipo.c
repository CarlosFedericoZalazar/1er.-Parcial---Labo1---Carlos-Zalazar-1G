#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include <string.h>
#include "validar.h"



int inicializarTipo(eTipo unTipo[], int tam)
{
    int todoOk = 0;

    if(unTipo != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            unTipo[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}


int hardcodeoTipo(eTipo tipo[], int tam, int* pId, int cantidad)
{
    int todoOk=0;

    eTipo AuxTipo[4] =
    {
        {5000,"Comun"},
        {5002,"CocheCama"},
        {5001,"Doble"},
        {5004,"Vip"}
    };

    if(tipo!=NULL && tam>0 && cantidad<tam && pId!=NULL)
    {
        for(int i=0; i<cantidad; i++)
        {
            AuxTipo[i].id = *pId;
            AuxTipo[i].isEmpty=0;
            tipo[i] = AuxTipo[i];
            (*pId)++;
        }
      todoOk=1;
    }
    return todoOk;
}

int funcionBuscarTipo(int idTipo, eTipo tipo[], int sizeTipo, char nombreTipo[])
{
    int todoOk=0;

    if(tipo!=NULL && sizeTipo>0)
    {

        for(int i=0; i<sizeTipo; i++)
        {
            if(tipo[i].id==idTipo)
            {
                strcpy(nombreTipo, tipo[i].descripcion);
            }
        }
    todoOk=1;
    }

    return todoOk;
}

int listarTipo(eTipo tipo[], int sizeTipo, int cleanScreen)
{
    int todoOk=0;
    if(cleanScreen)
        system("cls");
    if(tipo!=NULL)
    {

        printf("\nID SERVICIO   T. SERVICIO\n");
        for(int i=0; i<sizeTipo;i++){
            if(!tipo[i].isEmpty)
                printf("    %d      %-10s\n", tipo[i].id, tipo[i].descripcion);
        }
    todoOk=1;
    }
    return todoOk;
}


